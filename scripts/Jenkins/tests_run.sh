#!/bin/sh -x

rm 	  -rf /tmp/tests/*
mkdir  -p /tmp/tests/
chmod 777 /tmp/tests/

cd /var/www/html/runmemo/runmemo-website

drush status
drush cache-clear all
for testname in `cat ./scripts/Jenkins/tests_list`; do
	drush test-run --jenkins=/tmp/tests/ ${testname}
done
  