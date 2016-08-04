FROM centos:centos6
MAINTAINER Hans Zandbelt <hzandbelt@pingidentity.com>

# CentOS release 6.6 (Final)

RUN rpm --import http://dl.fedoraproject.org/pub/epel/RPM-GPG-KEY-EPEL-6
RUN rpm -ihv http://dl.fedoraproject.org/pub/epel/6/x86_64/epel-release-6-8.noarch.rpm

RUN yum update -y
