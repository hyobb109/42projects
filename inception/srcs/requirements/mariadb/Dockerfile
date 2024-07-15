FROM alpine:3.19

RUN apk -U upgrade && apk add --no-cache mariadb mariadb-client dumb-init

RUN mkdir -p /run/mysqld

COPY ./conf/my.cnf /etc/my.cnf

EXPOSE 3306

COPY ./tools/run.sh .

RUN chmod +x run.sh

ENTRYPOINT ["/usr/bin/dumb-init", "--", "sh", "./run.sh"]
