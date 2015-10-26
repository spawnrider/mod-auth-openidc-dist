FROM debian:jessie
MAINTAINER hzandbelt@pingidentity.com

ENV VERSION 1.8.6
ENV PKG libapache2-mod-auth-openidc_${VERSION}.orig.tar.gz

RUN apt-get update
RUN apt-get install -y build-essential devscripts dh-make curl pkg-config util-linux
RUN apt-get install -y libssl-dev libcurl4-openssl-dev libjansson-dev libhiredis-dev libpcre3-dev gcc tar autoconf automake libtool apache2-dev

WORKDIR /root
RUN curl -o ${PKG} https://mod-auth-openidc.org/download/${PKG}
RUN tar zxvf ${PKG}
ADD debian /root/mod_auth_openidc-${VERSION}/debian

WORKDIR /root/mod_auth_openidc-${VERSION}
#RUN linux32 dpkg-buildpackage -uc -us -ai386
RUN dpkg-buildpackage -uc -us
