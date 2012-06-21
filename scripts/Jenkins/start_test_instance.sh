#!/bin/sh


INSTANCE=i-0f8e1f47
echo ${INSTANCE}


ec2-describe-instances ${INSTANCE} --filter "instance-state-code=16" | grep ${INSTANCE}
if [ $? -eq 0 ]; then
	echo "Test instance is already running"
	exit 0
fi

echo "Starting test instance..."
ec2-start-instances ${INSTANCE}
if [ $? -ne 0 ]; then
	echo "Failed to start test instance"
	exit 1
fi

sleep 3m

ec2-describe-instances ${INSTANCE} --filter "instance-state-code=16" | grep ${INSTANCE}
if [ $? -eq 0 ]; then
	echo "Test instance is already running"
	exit 0
else
	echo "Failed to start test instance"
	exit 1
fi