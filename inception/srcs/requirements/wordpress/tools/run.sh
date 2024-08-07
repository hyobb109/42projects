#!/bin/sh

if [ ! -e "/var/www/html/wp-config.php" ]; then
    mkdir -p /var/www/html
    cd /var/www/html
    wp core download --allow-root
    wp config create --dbname=$DB_NAME --dbuser=$WP_ADMIN --dbpass=$WP_ADMIN_PASSWORD --dbhost=$MARIADB_HOSTNAME #--skip-check
    wp core install --url=$DOMAIN_NAME --title=$WP_TITLE --admin_user=$WP_ADMIN --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL
    wp user create $WP_USER $WP_USER_EMAIL --user_pass=$WP_USER_PASSWORD
fi

exec /usr/sbin/php-fpm82 -F