#!/bin/sh -x

#/**
# * @file tests_run.sh
# * @author  Leonid <leonid@runmemo.com>
# * @version 1.0
# *
# * @section DESCRIPTION
# *
# * This script runs "drush test-run" for every test in test_list file
# * and save results as xml. 
# *
# */

if [ -z $1 ]; then
	url="http://default"
else
	url=$1
fi
 
rm 	  -rf /tmp/tests/*
mkdir  -p /tmp/tests/
chmod 777 /tmp/tests/

cd /var/www/html/runmemo/runmemo-website

drush status
drush cache-clear all
for testname in `cat ./scripts/Jenkins/tests_list`; do
	drush test-run --jenkins=/tmp/tests/ -l $url ${testname}
done
  