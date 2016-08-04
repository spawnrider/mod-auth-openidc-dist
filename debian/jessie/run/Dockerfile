FROM debian:jessie
MAINTAINER hzandbelt@pingidentity.com

RUN apt-get clean && apt-get update
RUN apt-get install -y apt-utils curl

ENV MOD_AUTH_OPENIDC_VERSION 2.0.0rc0
ENV CJOSE_VERSION 0.4.1

ENV CJOSE_PKG libcjose_${CJOSE_VERSION}-1_amd64.deb
RUN apt-get install -y libjansson4
RUN curl -s -L -o ~/${CJOSE_PKG} https://mod-auth-openidc.org/download/${CJOSE_PKG}
RUN dpkg -i ~/${CJOSE_PKG}
RUN apt-get install -y -f

ENV MOD_AUTH_OPENIDC_PKG libapache2-mod-auth-openidc_${MOD_AUTH_OPENIDC_VERSION}-1_amd64.deb
RUN apt-get install -y apache2 libhiredis0.10
RUN curl -s -L -o ~/${MOD_AUTH_OPENIDC_PKG} https://mod-auth-openidc.org/download/${MOD_AUTH_OPENIDC_PKG}
RUN dpkg -i ~/${MOD_AUTH_OPENIDC_PKG}
RUN apt-get install -y -f

ADD 000-default.conf /etc/apache2/sites-available/

RUN a2enmod auth_openidc
RUN service apache2 start && curl -v http://localhost/protected/index.php 2>&1 | grep "Location:" | grep "accounts.google.com/o/oauth2/auth"
