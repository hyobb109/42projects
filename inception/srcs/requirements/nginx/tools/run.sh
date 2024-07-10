#!/bin/sh

openssl req -newkey rsa:4096 -noenc -x509 -days 365 \
      -keyout /etc/ssl/mynginx.key \
      -out /etc/ssl/mynginx.crt \
      -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Inception/CN=hyobicho"

chmod 600 /etc/ssl/mynginx.crt /etc/ssl/mynginx.key

exec nginx -g 'daemon off;'
