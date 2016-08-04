FROM debian:jessie
MAINTAINER hzandbelt@pingidentity.com

RUN apt-get clean && apt-get update
RUN apt-get install -y apt-utils curl

RUN echo "Acquire::http::Timeout \"90\";" > /etc/apt/apt.conf.d/99timeout

RUN apt-get install -y build-essential devscripts dh-make pkg-config util-linux
RUN apt-get install -y gcc tar autoconf automake libtool
RUN apt-get install -y libssl-dev libcurl4-openssl-dev libjansson-dev libhiredis-dev libpcre3-dev check

ENV DEB_BUILD_OPTIONS noddebs

ENV MOD_AUTH_OPENIDC_VERSION 2.0.0rc0
ENV CJOSE_VERSION 0.4.1

ENV CJOSE_TGZ cjose-${CJOSE_VERSION}.tar.gz
ENV CJOSE_ORIG_TGZ libcjose_${CJOSE_VERSION}.orig.tar.gz

WORKDIR /root
RUN curl -o ${CJOSE_ORIG_TGZ} https://mod-auth-openidc.org/download/${CJOSE_TGZ}
RUN tar zxvf ${CJOSE_ORIG_TGZ}

WORKDIR /root/cjose-${CJOSE_VERSION}
ADD debian-cjose debian
RUN dpkg-buildpackage -uc -us

#install cjose
RUN dpkg -i ~/libcjose_${CJOSE_VERSION}-1_amd64.deb

RUN apt-get install -y apache2-dev

ENV MOD_AUTH_OPENIDC_ORIG_TGZ libapache2-mod-auth-openidc_${MOD_AUTH_OPENIDC_VERSION}.orig.tar.gz

WORKDIR /root
RUN curl -o ${MOD_AUTH_OPENIDC_ORIG_TGZ} https://mod-auth-openidc.org/download/${MOD_AUTH_OPENIDC_ORIG_TGZ}
RUN tar zxvf ${MOD_AUTH_OPENIDC_ORIG_TGZ}

WORKDIR /root/mod_auth_openidc-${MOD_AUTH_OPENIDC_VERSION}
ADD debian-mod_auth_openidc debian
RUN dpkg-buildpackage -uc -us
