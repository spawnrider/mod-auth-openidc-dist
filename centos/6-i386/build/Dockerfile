FROM tenforward/centos-i386
MAINTAINER Hans Zandbelt <hzandbelt@pingidentity.com>

RUN rpm --import http://dl.fedoraproject.org/pub/epel/RPM-GPG-KEY-EPEL-6
RUN rpm -ihv http://dl.fedoraproject.org/pub/epel/6/i386/epel-release-6-8.noarch.rpm

ENV CMD_PREFIX linux32

RUN ${CMD_PREFIX} yum update -y

# install dev tools
RUN ${CMD_PREFIX} yum install -y rpm-build gcc tar git autoconf automake libtool make

# setup rpmbuild environment
WORKDIR /opt/rpmbuild
ENV HOME /opt/rpmbuild
RUN mkdir -p $HOME/rpm/{BUILD,SRPMS,SPECS,SOURCES,RPMS}
RUN echo "%_topdir $HOME/rpm" > ~/.rpmmacros

# mod_auth_openidc depends
RUN ${CMD_PREFIX} yum install --enablerepo=centosplus -y openssl-devel 
RUN ${CMD_PREFIX} yum install --enablerepo=epel -y jansson-devel
RUN ${CMD_PREFIX} yum install -y httpd httpd-devel curl-devel hiredis-devel pcre-devel check-devel

ENV MOD_AUTH_OPENIDC_VERSION 2.0.0rc0
ENV CJOSE_VERSION 0.4.1

ENV CJOSE_TGZ cjose-${CJOSE_VERSION}.tar.gz
ENV MOD_AUTH_OPENIDC_TGZ mod_auth_openidc-${MOD_AUTH_OPENIDC_VERSION}.tar.gz
ENV MOD_AUTH_OPENIDC_ORIG_TGZ libapache2-mod-auth-openidc_${MOD_AUTH_OPENIDC_VERSION}.orig.tar.gz

# build cjose RPM
RUN curl -o ${HOME}/rpm/SOURCES/${CJOSE_TGZ} https://mod-auth-openidc.org/download/${CJOSE_TGZ}
ADD cjose.spec ${HOME}/rpm/SPECS/cjose.spec
RUN ${CMD_PREFIX} rpmbuild --define "release ${CJOSE_VERSION}" -bb ${HOME}/rpm/SPECS/cjose.spec

#install cjose RPM
RUN ${CMD_PREFIX} yum localinstall -y /opt/rpmbuild/rpm/RPMS/i686/cjose-${CJOSE_VERSION}-1.el6.i686.rpm

ENV MOD_AUTH_OPENIDC_TGZ mod_auth_openidc-${MOD_AUTH_OPENIDC_VERSION}.tar.gz
ENV MOD_AUTH_OPENIDC_ORIG_TGZ libapache2-mod-auth-openidc_${MOD_AUTH_OPENIDC_VERSION}.orig.tar.gz

# build mod_auth_openidc RPM
RUN curl -o ${HOME}/rpm/SOURCES/${MOD_AUTH_OPENIDC_TGZ} https://mod-auth-openidc.org/download/${MOD_AUTH_OPENIDC_ORIG_TGZ}
ADD mod_auth_openidc.spec ${HOME}/rpm/SPECS/mod_auth_openidc.spec
ENV HIREDIS_LIBS -lhiredis
RUN ${CMD_PREFIX} rpmbuild --define "release ${MOD_AUTH_OPENIDC_VERSION}" -bb ${HOME}/rpm/SPECS/mod_auth_openidc.spec
