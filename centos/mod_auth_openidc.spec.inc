Name:		mod_auth_openidc
Version:	%{release}
Release:	1%{?dist}
Summary:	Authentication/Authorization module for the Apache 2.x HTTP server that allows users to authenticate using an OpenID Connect enabled Identity Provider

Group:		Networking/Daemons/HTTP
License:	Apache License Version 2.0
URL:		https://github.com/pingidentity/mod_auth_openidc
Source0:        mod_auth_openidc-%{version}.tar.gz

Requires:       httpd, openssl, curl, jansson, hiredis, pcre, cjose
BuildRequires:	httpd-devel, openssl-devel, curl-devel, jansson-devel, hiredis-devel, pcre-devel, cjose

%description
This module enables an Apache 2.x web server to operate as an OpenID Connect Relying Party and/or OAuth 2.0 Resource Server.

%prep
%setup -q

%define debug_package %{nil}
%build
export APXS2_OPTS="-S LIBEXECDIR=$RPM_BUILD_ROOT%{_libdir}/httpd/modules/" 
autoreconf
%configure
make test

%clean
rm -rf $RPM_BUILD_ROOT

%changelog

%files
%doc LICENSE.txt ChangeLog 
%{_libdir}/httpd/modules/mod_auth_openidc.so
