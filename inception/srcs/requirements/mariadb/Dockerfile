FROM alpine:3.18

RUN apk -U upgrade && apk add --no-cache mariadb mariadb-client dumb-init

COPY ./conf/my.cnf /etc/my.cnf

ENTRYPOINT [ "/usr/bin/dumb-init", "--" ]