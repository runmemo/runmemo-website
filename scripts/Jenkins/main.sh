#!/bin/sh

INSTANCE="i-0f8e1f47"
echo "instance=${INSTANCE}"

CERT="/root/web_staging.pem"
echo "certificate=${CERT}"

#get ip of test instance
ip=$(ec2-describe-instances ${INSTANCE} --filter "instance-state-code=16" | grep ^INSTANCE | cut -f 18)
if [ -z ${ip} ]; then
	echo "Failed to get ip of test instance"
	exit 1
fi
echo "ip=${ip}"

#pull repo on test instance
ssh -i ${CERT} root@${ip} "cd /var/www/html/runmemo/runmemo-website/; git pull"
if [ $? -ne 0 ]; then
	echo "Failed to pull repo on test instance"
	exit 1
fi

#run tests
ssh -i ${CERT} root@${ip} "/bin/sh /var/www/html/runmemo/runmemo-website/scripts/Jenkins/tests_run.sh"
if [ $? -ne 0 ]; then
	echo "Failed to run tests"
	exit 1
fi

#get results
mkdir -p /tmp/tests/${BUILD_ID}
echo "test-dir=/tmp/tests/${BUILD_ID}"
scp -i ${CERT} root@${ip}:"/tmp/tests/*" /tmp/tests/${BUILD_ID}/
if [ $? -ne 0 ]; then
	echo "Failed to get results"
	exit 1
fi