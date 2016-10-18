# install dev tools
RUN ${CMD_PREFIX} yum install -y rpm-build gcc tar git autoconf automake libtool make

# setup rpmbuild environment
WORKDIR /opt/rpmbuild
ENV HOME /opt/rpmbuild
RUN mkdir -p $HOME/rpm/{BUILD,SRPMS,SPECS,SOURCES,RPMS}
RUN echo "%_topdir $HOME/rpm" > ~/.rpmmacros

# mod_auth_openidc depends
RUN ${CMD_PREFIX} yum install -y openssl-devel 
RUN ${CMD_PREFIX} yum install -y jansson-devel
RUN ${CMD_PREFIX} yum install -y httpd httpd-devel curl-devel hiredis-devel pcre-devel check-devel
