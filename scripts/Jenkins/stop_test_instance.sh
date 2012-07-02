#!/bin/sh -x

#/**
# * @file stop_test_instance.sh
# * @author  Leonid <leonid@runmemo.com>
# * @version 1.0
# *
# * @section DESCRIPTION
# *
# * This is one of the scripts that are executed by Jenkins when a code change is detected. 
# * The script stops test instance and makes shure that it's stopped.
# * 
# * WARNING Following parametrs must be set by Jenkins:
# * #Exporting Instance ID and certificate
# * export INSTANCE=i-0f8e1f47
# * export CERT=/root/web_staging.pem
# * #Exporting EC2 settings
# * export EC2_KEYPAIR=TestMicroInstances 
# * export EC2_URL=https://ec2.eu-west-1.amazonaws.com
# * export EC2_PRIVATE_KEY=/root/.ec2/pk-SCD4I2VBV4QEHCXU4XGVMBE7PXPGD363.pem
# * export EC2_CERT=/root/.ec2/cert-SCD4I2VBV4QEHCXU4XGVMBE7PXPGD363.pem
# * export JAVA_HOME=/usr/lib/jvm/java-6-openjdk/
# */

if [ -z ${INSTANCE} ]; then
	echo "Parametr INSTANCE is not defined"
	exit 1
fi
echo "Stop test instance: ${INSTANCE}"


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