FROM alpine:3.19

RUN apk -U upgrade && apk add --no-cache mariadb mariadb-client dumb-init

COPY ./conf/my.cnf /etc/my.cnf

COPY ./tools/run.sh .

ENTRYPOINT ["/usr/bin/dumb-init", "--", "sh", "./run.sh"]
