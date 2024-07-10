FROM alpine:3.19

RUN apk -U upgrade && apk add --no-cache nginx openssl dumb-init

COPY ./conf/nginx.conf /etc/nginx/http.d/default.conf

COPY ./tools/run.sh .

ENTRYPOINT ["/usr/bin/dumb-init", "--", "sh", "./run.sh"]