#!/bin/sh


INSTANCE=i-0f8e1f47
echo ${INSTANCE}


ec2-describe-instances ${INSTANCE} --filter "instance-state-code=80" | grep ${INSTANCE}
if [ $? -eq 0 ]; then
	echo "Test instance is already stopped"
	exit 0
fi

echo "Stopping test instance..."
ec2-stop-instances ${INSTANCE}
if [ $? -ne 0 ]; then
	echo "Failed to stop test instance"
	exit 1
fi


sleep 3m

ec2-describe-instances ${INSTANCE} --filter "instance-state-code=80" | grep ${INSTANCE}
if [ $? -eq 0 ]; then
	echo "Test instance is already stopped"
	exit 0
else
	echo "Failed to stop test instance"
	exit 1
fi