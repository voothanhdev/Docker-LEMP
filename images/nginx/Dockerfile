FROM nginx:alpine

MAINTAINER VooThanh DEV <voothanhphong@gmail.com>

ENV SERVER_NAME local.io
ENV ROOT_FOLDER /project
ENV VARNISH ""
ENV VARNISH_PORT=6081
ENV PROJECT_TYPE=2
ENV HTTPS true
ENV PROXY ""
ENV PROXY_PORT ""

COPY include/ /etc/nginx/include/
COPY config/*.conf /etc/nginx/conf.d/
COPY bin/* /usr/local/bin/
COPY entrypoint /

RUN apk update && \
    apk add bash && \
    apk add openssl
RUN adduser -G www-data -D -u 1000 -s /bin/bash www \
    && touch /var/run/nginx.pid \
    && mkdir -p ${ROOT_FOLDER} /sock \
    && mv -f /etc/nginx/include/nginx.conf /etc/nginx/nginx.conf \
    && chown -R www /etc/nginx /var/cache/nginx /var/run/nginx.pid /var/log/nginx /sock /entrypoint \
    && chown -R www:www-data "${ROOT_FOLDER}" \
    && chmod +x /entrypoint \
    && chmod +x /usr/local/bin/*
RUN rm -f /etc/nginx/conf.d/default.conf \
    rm -rf /var/cache/apk/*

WORKDIR ${ROOT_FOLDER}

ENTRYPOINT ["/entrypoint"]

EXPOSE 443 80

USER www