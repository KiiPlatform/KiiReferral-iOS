#!/bin/sh

# SET VARIABLES HERE

# your kii app credentials
KII_APP_ID=""
KII_APP_KEY=""
KII_CLIENT_ID=""
KII_CLIENT_SECRET=""

# the site your app is hosted in (us|jp|cn)
# ex: us
KII_SITE=""

# name of the directory holding the kii cli sdk
# ex: kii-cli-vX.Y.Z
KII_DIR=""

# END SET VARIABLES


# DO NOT EDIT BELOW THIS LINE UNLESS YOU KNOW WHAT YOU ARE DOING :)


echo "Checking variables..."

if [ -z $KII_APP_ID ]; then
    echo "FATAL ERROR => Invalid KII_APP_ID: edit the deploy.sh file configuration variables"
    exit 1
fi

if [ -z $KII_APP_KEY ]; then
    echo "FATAL ERROR => Invalid KII_APP_KEY: edit the deploy.sh file configuration variables"
    exit 1
fi

if [ -z $KII_CLIENT_ID ]; then
    echo "FATAL ERROR => Invalid KII_CLIENT_ID: edit the deploy.sh file configuration variables"
    exit 1
fi

if [ -z $KII_CLIENT_SECRET ]; then
    echo "FATAL ERROR => Invalid KII_CLIENT_SECRET: edit the deploy.sh file configuration variables"
    exit 1
fi

if [ -z $KII_SITE ]; then
    echo "FATAL ERROR => Invalid KII_SITE: edit the deploy.sh file configuration variables"
    exit 1
fi

if [ -z $KII_DIR ]; then
    echo "FATAL ERROR => Invalid KII_DIR: edit the deploy.sh file configuration variables"
    exit 1
fi

echo "Checking for Kii CLI"

if [ ! -d $KII_DIR ]; then
    echo "FATAL ERROR => $KII_DIR not found. Make sure you have installed the Kii CLI and pointed the KII_DIR variable in deploy.sh to the correct path. You can find more about installing the Kii CLI here: http://documentation.kii.com/en/guides/commandlinetools/"
fi

echo "Uploading server hooks"

node $KII_DIR/bin/kii-servercode.js deploy-file \
  --file referral-hook-source.js \
  --site $KII_SITE \
  --app-id $KII_APP_ID \
  --app-key $KII_APP_KEY \
  --client-id $KII_CLIENT_ID \
  --client-secret $KII_CLIENT_SECRET \
  --hook-config referral-hooks.config
  
echo "Done uploading server hooks"