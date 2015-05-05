Name:		mod_auth_openidc
Version:	1.8.1
Release:	1%{?dist}
Summary:	Authentication/Authorization module for the Apache 2.x HTTP server that allows users to authenticate using an OpenID Connect enabled Identity Provider

Group:		Networking/Daemons/HTTP
License:	Apache License Version 2.0
URL:		https://github.com/pingidentity/mod_auth_openidc
Source0:        mod_auth_openidc-%{version}.tar.gz

Requires:       httpd, openssl, curl, jansson, hiredis, pcre
BuildRequires:	httpd-devel, openssl-devel, curl-devel, jansson-devel, hiredis-devel, pcre-devel

%description
This module enables an Apache 2.x web server to operate as an OpenID Connect Relying Party and/or OAuth 2.0 Resource Server.

%prep
%setup -q

%build
export APXS2_OPTS="-S LIBEXECDIR=$RPM_BUILD_ROOT%{_libdir}/httpd/modules/" 
autoreconf
%configure
make

%install
mkdir -p $RPM_BUILD_ROOT%{_libdir}/httpd/modules/
make install
# mv %{_libdir}/httpd/modules/mod_auth_openidc.so $RPM_BUILD_ROOT%{_libdir}/httpd/modules/

%clean
rm -rf $RPM_BUILD_ROOT

%files
%doc LICENSE.txt ChangeLog 
%{_libdir}/httpd/modules/mod_auth_openidc.so

%changelog
* Tue May 5 2015 Hans Zandbelt <hzandbelt@pingidentity.com> 1.8.1-1
- Release 1.8.1.

* Thu Feb 26 2015 Hans Zandbelt <hzandbelt@pingidentity.com> 1.8.0-1
- Release 1.8.0.

* Thu Feb 5 2015 Hans Zandbelt <hzandbelt@pingidentity.com> 1.7.3-1
- Release 1.7.3.

* Wed Jan 21 2015 Hans Zandbelt <hzandbelt@pingidentity.com> 1.7.2-1
- Release 1.7.2.

* Fri Dec 12 2014 Hans Zandbelt <hzandbelt@pingidentity.com> 1.7.1-1
- Release 1.7.1.

* Thu Nov 6 2014 Hans Zandbelt <hzandbelt@pingidentity.com> 1.7.0-1
- Release 1.7.0.

* Fri Aug 29 2014 Terry Fleury <terrencegf@gmail.com> 1.5.5-1
- Release 1.5.5.

* Thu Aug 14 2014 Hiroyuki Wada <wadahiro@gmail.com> 1.5.4-1
- Release 1.5.4.

* Sat Jul 26 2014 Hiroyuki Wada <wadahiro@gmail.com> 1.5.2-1
- Initial packaging for CentOS6/RHEL6.
