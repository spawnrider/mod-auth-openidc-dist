FROM centos:centos6
MAINTAINER Hans Zandbelt <hzandbelt@pingidentity.com>

ENV VERSION 1.8.4

# setup base libraries
RUN yum update -y
RUN yum install -y rpm-build gcc tar git autoconf automake libtool

# epel
RUN rpm --import http://dl.fedoraproject.org/pub/epel/RPM-GPG-KEY-EPEL-6
RUN rpm -ihv http://dl.fedoraproject.org/pub/epel/6/x86_64/epel-release-6-8.noarch.rpm

# setup rpmbuild environment
WORKDIR /opt/rpmbuild
ENV HOME /opt/rpmbuild
RUN mkdir -p $HOME/rpm/{BUILD,SRPMS,SPECS,SOURCES,RPMS}
RUN echo "%_topdir $HOME/rpm" > ~/.rpmmacros

# mod_auth_openidc depends
RUN yum install --enablerepo=centosplus -y openssl-devel 
RUN yum install --enablerepo=epel -y jansson-devel
RUN yum install -y httpd httpd-devel curl-devel hiredis-devel pcre-devel

# build mod_auth_openidc rpm
RUN curl -o $HOME/rpm/SOURCES/mod_auth_openidc-${VERSION}.tar.gz https://mod-auth-openidc.org/download/libapache2-mod-auth-openidc_${VERSION}.orig.tar.gz
ADD mod_auth_openidc.spec $HOME/rpm/SPECS/mod_auth_openidc.spec
ENV HIREDIS_LIBS -lhiredis
RUN rpmbuild --define "release ${VERSION}" -bb $HOME/rpm/SPECS/mod_auth_openidc.spec
