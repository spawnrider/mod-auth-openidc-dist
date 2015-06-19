FROM ubuntu:12.04.5
MAINTAINER hzandbelt@pingidentity.com

# Ubuntu 12.04.5 LTS

ENV VERSION 1.8.3
ENV PATCHLEVEL 1
ENV PKG libapache2-mod-auth-openidc_${VERSION}-${PATCHLEVEL}ubuntu1~precise+1_amd64.deb

RUN apt-get update
RUN apt-get install -y curl apache2 libjansson4
RUN curl -s -L -o ~/${PKG} https://mod-auth-openidc.org/download/${PKG}
RUN dpkg -i ~/${PKG} && echo ok || echo ko
#RUN apt-get install -y -f

ADD default /etc/apache2/sites-available/

RUN a2enmod auth_openidc
RUN service apache2 start && curl -v http://localhost/protected/index.php 2>&1 | grep "Location:" | grep "accounts.google.com/o/oauth2/auth"
