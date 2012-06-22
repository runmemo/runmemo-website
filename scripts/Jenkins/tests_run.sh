#!/bin/sh -x

rm 	  -rf /tmp/tests/*
mkdir  -p /tmp/tests/
chmod 777 /tmp/tests/

cd /var/www/html/runmemo/runmemo-website

drush status
drush cache-clear all
while read -r testname; do
	drush test-run --jenkins=/tmp/tests/drupal-tests ${testname}
done < ./scripts/Jenkins/tests_list
  