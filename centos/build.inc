# install dev tools
RUN yum install -y rpm-build gcc tar git autoconf automake libtool make

# setup rpmbuild environment
WORKDIR /opt/rpmbuild
ENV HOME /opt/rpmbuild
RUN mkdir -p $HOME/rpm/{BUILD,SRPMS,SPECS,SOURCES,RPMS}
RUN echo "%_topdir $HOME/rpm" > ~/.rpmmacros

# mod_auth_openidc depends
RUN yum install --enablerepo=centosplus -y openssl-devel 
RUN yum install --enablerepo=epel -y jansson-devel
RUN yum install -y httpd httpd-devel curl-devel hiredis-devel pcre-devel check-devel
