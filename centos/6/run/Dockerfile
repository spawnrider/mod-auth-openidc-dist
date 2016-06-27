FROM centos:centos6
MAINTAINER hzandbelt@pingidentity.com

# CentOS release 6.6 (Final)

ENV VERSION 1.8.10
ENV PATCHLEVEL 1
ENV PKG mod_auth_openidc-${VERSION}-${PATCHLEVEL}.el6.x86_64.rpm

RUN rpm --import http://dl.fedoraproject.org/pub/epel/RPM-GPG-KEY-EPEL-6
RUN rpm -ihv http://dl.fedoraproject.org/pub/epel/6/x86_64/epel-release-6-8.noarch.rpm

RUN yum update -y

RUN curl -s -L -o ~/${PKG} https://mod-auth-openidc.org/download/${PKG}
RUN yum localinstall -y ~/${PKG}

ADD 000-default.conf /etc/httpd/conf.d/
RUN service httpd start && curl -v http://localhost/protected/index.php 2>&1 | grep "Location:" | grep "accounts.google.com/o/oauth2/auth"
