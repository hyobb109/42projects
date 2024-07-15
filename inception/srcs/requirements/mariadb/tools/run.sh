#!/bin/sh

# 이미 실행중인 MariaDB가 있을 경우 초기화 하지 않음
if [ ! -e "/run/mysqld/mysqld.sock" ]; then
	mariadb-install-db --user=mysql --datadir=/var/lib/mysql --skip-test-db

	chown mysql:mysql /var/run/mysqld 
	
	mariadbd-safe --datadir='/var/lib/mysql' &

	# mariaDB 서버 시작 전까지 대기
	while ! mariadb-admin ping --silent; do
		echo "Waiting for MariaDB to start..."
		sleep 1
	done

	mariadb -e "CREATE USER IF NOT EXISTS '$MARIADB_USER'@'%' IDENTIFIED BY '$MARIADB_PASSWORD';"
	mariadb -e "CREATE DATABASE IF NOT EXISTS $DB_NAME;"
	mariadb -e "GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$WP_ADMIN'@'%'"
	mariadb -e "FLUSH PRIVILEGES;"

	# mariaDB 서버 종료
	mariadb-admin --wait-for-all-slaves shutdown
fi

# mariaDB 서버 시작
exec mariadbd-safe


