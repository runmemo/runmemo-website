#!/bin/sh -x

#/**
# * @file rollout.sh
# * @author  Leonid <leonid@runmemo.com>
# * @version 1.0
# *
# * @section DESCRIPTION
# *
# * Rollout process:
# * 1. Put website into maintenance mode
# * 2. Backup all attached volumes & wait until comlete
# * 3. Pull new release
# * 4. Run update script
# * 5. MANUAL: additional configuration
# * 6. MANUAL: Bring website out of maintenance mode
# *
# *
# * WARNING Following parametrs must be set by Jenkins:
# * #Exporting Instance ID and certificate
# * Answer=yes
# * export INSTANCE=i-0f8e1f47
# * export CERT=/root/website-live.pem
# * export SITE_WORKDIR="/var/www/html/runmemo/runmemo-website"
# * #Exporting EC2 settings(required by ec2 tools)
# * export EC2_KEYPAIR=TestMicroInstances 
# * export EC2_URL=https://ec2.eu-west-1.amazonaws.com
# * export EC2_PRIVATE_KEY=/root/.ec2/pk-SCD4I2VBV4QEHCXU4XGVMBE7PXPGD363.pem
# * export EC2_CERT=/root/.ec2/cert-SCD4I2VBV4QEHCXU4XGVMBE7PXPGD363.pem
# * export JAVA_HOME=/usr/lib/jvm/java-6-openjdk/
# *
# */

if [ -z ${Answer} ] || [ "${Answer}" != "yes" ]; then
	echo "Aborted by user"
	exit 1	
fi

if [ -z ${INSTANCE} ]; then
	echo "Parametr INSTANCE is not defined"
	exit 1
fi

if [ -z ${CERT} ]; then
	echo "Parametr CERT is not defined"
	exit 1
fi

if [ -z ${SITE_WORKDIR} ]; then
	echo "Parametr SITE_WORKDIR is not defined"
	exit 1
fi

echo "rollout.sh"
echo "instance=${INSTANCE}"
echo "certificate=${CERT}"

SSH_OPTIONS="-o UserKnownHostsFile=/dev/null -o StrictHostKeychecking=no"
BACKUP_TIMELIMIT=30

# Get an ip address
ip=$(ec2-describe-instances ${INSTANCE} | grep ^INSTANCE | cut -f18)
if [ -z ${ip} ]; then
	echo "Failed to get ip of instance"
	exit 1
fi
echo "ip=${ip}"

# * 1. Put website into maintenance mode
ssh ${SSH_OPTIONS} -i ${CERT} root@${ip} "cd ${SITE_WORKDIR}; drush vset --always-set site_offline 1 && drush cc all"
if [ $? -ne 0 ]; then
	echo "Failed to put site into maintenance mode"
	exit 1
fi

# * 2. Backup all attached volumes & wait until comlete
for vol in $(ec2-describe-instances ${INSTANCE} | grep ^BLOCKDEVICE | cut -f3); do
#   Start snapshot process, get snapshot name
	snap=$(ec2-create-snapshot ${vol} --description "Backup before rollout >> ${rel} for ${vol}" | cut -f2)
	if [ $? -ne 0 ] || [ -z ${snap} ]; then
		echo "Failed to create a snapshot of a volume(${vol})"
		exit 1		
	fi
	
# 	Wait until backup complete
	backup_start_at=$(date +%s) 
	until [ $(ec2-describe-snapshots ${snap} | cut -f2) == "completed" ]; do
		if [ $(( ( $(date +%s) - $backup_start_at ) / 60 )) >= ${BACKUP_TIMELIMIT} ]; then
			echo "Failed to create a snapshot(${snap}) of a volume(${vol})"
			echo "Backup killed by timeout(${BACKUP_TIMELIMIT}min)"
			exit 1					
		fi 
		sleep 1m
	done
	
done


# * 3. Pull new release
ssh ${SSH_OPTIONS} -i ${CERT} root@${ip} "cd ${SITE_WORKDIR}; git pull"
if [ $? -ne 0 ]; then
	echo "Failed to pull new release"
	exit 1
fi


# * 4. Run update script
#
# drush
#   updatedb (updb)
#          Apply any database updates required (as with running update.php).
#   pm-updatecode (upc)
#          Update Drupal core and contrib projects to latest recommended releases.
#   pm-update (up)
#          Update Drupal core and contrib projects and apply any pending database updates (Same as pm-updatecode + updatedb).

ssh ${SSH_OPTIONS} -i ${CERT} root@${ip} "cd ${SITE_WORKDIR}; drush pm-update && drush cc all"
if [ $? -ne 0 ]; then
	echo "Failed to run update script"
	exit 1
fi


# * 5. MANUAL: additional configuration
# * 6. MANUAL: Bring website out of maintenance mode
cat << EOF
"============================================================" 
"> New release has been installed!!!                         "
"> You have to perform manual configuration and bring        "
"> website out of maintenance:                               "
"> # drush vset --always-set site_offline 0 && drush cc all  "
"============================================================"
EOF

# Bring website out of maintenance mode
#ssh ${SSH_OPTIONS} -i ${CERT} root@${ip} "cd ${SITE_WORKDIR}; drush vset --always-set site_offline 0 && drush cc all"
#if [ $? -ne 0 ]; then
#	echo "Failed to bring website back"
#	exit 1
#fi