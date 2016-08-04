FROM tenforward/centos-i386
MAINTAINER Hans Zandbelt <hzandbelt@pingidentity.com>

RUN rpm --import http://dl.fedoraproject.org/pub/epel/RPM-GPG-KEY-EPEL-6
RUN rpm -ihv http://dl.fedoraproject.org/pub/epel/6/i386/epel-release-6-8.noarch.rpm

ENV CMD_PREFIX linux32

RUN ${CMD_PREFIX} yum update -y

ENV MOD_AUTH_OPENIDC_VERSION 2.0.0rc0
ENV CJOSE_VERSION 0.4.1

ENV CJOSE_PKG cjose-${CJOSE_VERSION}-1.el6.i686.rpm
RUN curl -s -L -o ~/${CJOSE_PKG} https://mod-auth-openidc.org/download/${CJOSE_PKG}
RUN ${CMD_PREFIX} yum localinstall -y ~/${CJOSE_PKG}

ENV MOD_AUTH_OPENIDC_PKG mod_auth_openidc-${MOD_AUTH_OPENIDC_VERSION}-1.el6.i686.rpm

RUN curl -s -L -o ~/${MOD_AUTH_OPENIDC_PKG} https://mod-auth-openidc.org/download/${MOD_AUTH_OPENIDC_PKG}
RUN ${CMD_PREFIX} yum localinstall -y ~/${MOD_AUTH_OPENIDC_PKG}

ADD 000-default.conf /etc/httpd/conf.d/
RUN service httpd start && curl -v http://localhost/protected/index.php 2>&1 | grep "Location:" | grep "accounts.google.com/o/oauth2/auth"
