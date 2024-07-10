#!/bin/sh

/usr/bin/mysqld --user=root --datadir=/var/lib/mysql &

# mariaDB 서버 시작 전까지 대기
while ! mysqladmin ping --silent; do
	echo "Waiting for MariaDB to start..."
	sleep 1
done


mysql -uroot --skip-password -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$MARIADB_ROOT_PASSWORD';"
mysql -uroot -p$MARIADB_ROOT_PASSWORD -e "CREATE DATABASE IF NOT EXISTS $WP_DB_NAME;"
mysql -uroot -p$MARIADB_ROOT_PASSWORD -e "CREATE USER IF NOT EXISTS '$WP_ADMIN'@'%' IDENTIFIED BY '$WP_ADMIN_PASSWORD';"
mysql -uroot -p$MARIADB_ROOT_PASSWORD -e "GRANT ALL PRIVILEGES ON $WP_DB_NAME.* TO '$WP_ADMIN'@'%'"
mysql -uroot -p$MARIADB_ROOT_PASSWORD -e "FLUSH PRIVILEGES;"
