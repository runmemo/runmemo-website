#!/bin/sh -x

#/**
# * @file pull_only.sh
# * @author  Leonid <leonid@runmemo.com>
# * @version 1.0
# *
# * @section DESCRIPTION
# *
# * This is the main script should be executed by Jenkins when a code change is detected.  
# * The script pulls git repo on test instance.
# * 
# * WARNING Test instance must be running
# * WARNING Following parametrs must be set by Jenkins:
# * #Exporting Instance ID and certificate
# * export INSTANCE=i-0f8e1f47
# * export CERT=/root/web_staging.pem
# * export SSH_OPTIONS="-o UserKnownHostsFile=/dev/null -o StrictHostKeychecking=no"
# * #Exporting EC2 settings
# * export EC2_KEYPAIR=TestMicroInstances 
# * export EC2_URL=https://ec2.eu-west-1.amazonaws.com
# * export EC2_PRIVATE_KEY=/root/.ec2/pk-SCD4I2VBV4QEHCXU4XGVMBE7PXPGD363.pem
# * export EC2_CERT=/root/.ec2/cert-SCD4I2VBV4QEHCXU4XGVMBE7PXPGD363.pem
# * export JAVA_HOME=/usr/lib/jvm/java-6-openjdk/
# *
# */

if [ -z ${INSTANCE} ]; then
	echo "Parametr INSTANCE is not defined"
	exit 1
fi

if [ -z ${CERT} ]; then
	echo "Parametr CERT is not defined"
	exit 1
fi

echo "main.sh"
echo "instance=${INSTANCE}"
echo "certificate=${CERT}"
echo "SSH_OPTIONS=${SSH_OPTIONS}"

#get ip of test instance
ip=$(ec2-describe-instances ${INSTANCE} --filter "instance-state-code=16" | grep ^INSTANCE | cut -f 18)
if [ -z ${ip} ]; then
	echo "Failed to get ip of test instance"
	exit 1
fi
echo "ip=${ip}"

#pull repo on test instance
ssh ${SSH_OPTIONS} -i ${CERT} root@${ip} "cd /var/www/html/runmemo/runmemo-website/; git pull"
if [ $? -ne 0 ]; then
	echo "Failed to pull repo on test instance"
	exit 1
fi