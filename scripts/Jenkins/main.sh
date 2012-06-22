#!/bin/sh -x

echo "main.sh"
echo "instance=${INSTANCE}"
echo "certificate=${CERT}"

SSH_OPTIONS="-o UserKnownHostsFile=/dev/null -o StrictHostKeychecking=no"

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

#run tests
ssh ${SSH_OPTIONS} -i ${CERT} root@${ip} "/bin/sh -x /var/www/html/runmemo/runmemo-website/scripts/Jenkins/tests_run.sh"
if [ $? -ne 0 ]; then
	echo "Failed to run tests"
	exit 1
fi

#get results
scp ${SSH_OPTIONS} -i ${CERT} root@${ip}:"/tmp/tests/*"  ${WORKSPACE}/${BUILD_ID}
if [ $? -ne 0 ]; then
	echo "Failed to get results"
	exit 1
fi