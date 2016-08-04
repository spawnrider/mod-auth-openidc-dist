FROM tenforward/centos-i386
MAINTAINER Hans Zandbelt <hzandbelt@pingidentity.com>

RUN rpm --import http://dl.fedoraproject.org/pub/epel/RPM-GPG-KEY-EPEL-6
RUN rpm -ihv http://dl.fedoraproject.org/pub/epel/6/i386/epel-release-6-8.noarch.rpm

ENV CMD_PREFIX linux32

RUN ${CMD_PREFIX} yum update -y
