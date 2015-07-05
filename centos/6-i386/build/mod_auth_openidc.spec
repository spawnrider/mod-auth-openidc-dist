Name:		mod_auth_openidc
Version:	%{release}
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
