FROM centos:centos7
MAINTAINER hzandbelt@pingidentity.com

# CentOS Linux release 7.0.1406 (Core)

ENV VERSION 1.8.10.1
ENV PATCHLEVEL 1
ENV PKG mod_auth_openidc-${VERSION}-${PATCHLEVEL}.el7.centos.x86_64.rpm

RUN rpm --import http://dl.fedoraproject.org/pub/epel/RPM-GPG-KEY-EPEL-7
RUN rpm -ihv http://dl.fedoraproject.org/pub/epel/7/x86_64/e/epel-release-7-7.noarch.rpm

RUN yum -y swap -- remove fakesystemd -- install systemd systemd-libs
RUN yum -y update; yum clean all; \
(cd /lib/systemd/system/sysinit.target.wants/; for i in *; do [ $i == systemd-tmpfiles-setup.service ] || rm -f $i; done); \
rm -f /lib/systemd/system/multi-user.target.wants/*;\
rm -f /etc/systemd/system/*.wants/*;\
rm -f /lib/systemd/system/local-fs.target.wants/*; \
rm -f /lib/systemd/system/sockets.target.wants/*udev*; \
rm -f /lib/systemd/system/sockets.target.wants/*initctl*; \
rm -f /lib/systemd/system/basic.target.wants/*;\
rm -f /lib/systemd/system/anaconda.target.wants/*;
VOLUME [ "/sys/fs/cgroup" ]
CMD ["/usr/sbin/init"]

RUN yum install -y httpd

RUN curl -s -L -o ~/${PKG} https://mod-auth-openidc.org/download/${PKG}
RUN yum localinstall -y ~/${PKG}

ADD 000-default.conf /etc/httpd/conf.d/
RUN /usr/sbin/httpd && curl -v http://localhost/protected/index.php 2>&1 | grep "Location:" | grep "accounts.google.com/o/oauth2/auth"
