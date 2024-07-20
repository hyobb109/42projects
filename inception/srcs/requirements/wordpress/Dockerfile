FROM alpine:3.19

RUN apk -U upgrade && apk add --no-cache \
    curl \
    php82 \
    php82-curl \
    php82-phar \
    php82-fpm \
    php82-mysqli \
    php82-json \
    php82-dom \
    php82-fileinfo \
    php82-intl \
    php82-mbstring \
    php82-openssl \
    php82-xml \
    php82-xmlreader \
    php82-zlib \
    php82-session \
    php82-iconv \
    php82-simplexml \
    php82-zip \
    dumb-init

RUN sed -i "s|listen = 127.0.0.1:9000|listen = 9000|g" \
		/etc/php82/php-fpm.d/www.conf

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar

RUN chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp

COPY ./tools/run.sh .

EXPOSE 9000

ENTRYPOINT ["/usr/bin/dumb-init", "--", "sh", "./run.sh"]