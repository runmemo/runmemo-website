#!/bin/sh

rm 	  -rf /tmp/tests/*
mkdir  -p /tmp/tests/
chmod 777 /tmp/tests/

cd /var/www/html/runmemo/runmemo-website

drush status >> /tmp/tests/drush.log

while read -r testname; do
	drush test-run --jenkins=/tmp/tests/drupal-tests ${testname} >> drush.log 2 >> drush.err
done < ./scripts/Jenkins/tests_list
  