FROM tenforward/centos-i386
MAINTAINER Hans Zandbelt <hzandbelt@pingidentity.com>

ENV VERSION 1.8.5

# setup base libraries
RUN linux32 yum update -y
RUN linux32 yum install -y rpm-build gcc tar git autoconf automake libtool

# epel
RUN linux32 rpm --import http://dl.fedoraproject.org/pub/epel/RPM-GPG-KEY-EPEL-6
RUN linux32 rpm -ihv http://dl.fedoraproject.org/pub/epel/6/i386/epel-release-6-8.noarch.rpm

# setup rpmbuild environment
WORKDIR /opt/rpmbuild
ENV HOME /opt/rpmbuild
RUN mkdir -p $HOME/rpm/{BUILD,SRPMS,SPECS,SOURCES,RPMS}
RUN echo "%_topdir $HOME/rpm" > ~/.rpmmacros

# mod_auth_openidc depends
RUN linux32 yum install --enablerepo=centosplus -y openssl-devel 
RUN linux32 yum install --enablerepo=epel -y jansson-devel
RUN linux32 yum install -y httpd httpd-devel curl-devel hiredis-devel pcre-devel

# build mod_auth_openidc rpm
RUN curl -o $HOME/rpm/SOURCES/mod_auth_openidc-${VERSION}.tar.gz https://mod-auth-openidc.org/download/libapache2-mod-auth-openidc_${VERSION}.orig.tar.gz
ADD mod_auth_openidc.spec $HOME/rpm/SPECS/mod_auth_openidc.spec
ENV HIREDIS_LIBS -lhiredis
RUN linux32 rpmbuild --define "release ${VERSION}" -bb $HOME/rpm/SPECS/mod_auth_openidc.spec
