Name:		mod_token_binding
Version:	%{release}
Release:	1%{?dist}
Summary:	Token Binding module for the Apache 2.4 HTTP server

Group:		Networking/Daemons/HTTP
License:	Apache License Version 2.0
URL:		https://github.com/zmartzone/mod_token_binding
Source0:    mod_token_binding-%{version}.tar.gz

Requires:       httpd, openssl
BuildRequires:	httpd-devel, openssl-devel

%description
This module enables Token Binding for an Apache 2.4 web server.

%prep
%setup -q

%define debug_package %{nil}
%build
export APXS2_OPTS="-S LIBEXECDIR=$RPM_BUILD_ROOT%{_libdir}/httpd/modules/" 
autoreconf
./configure --with-token-binding=/opt/rpmbuild/token_bind
make

%clean
rm -rf $RPM_BUILD_ROOT

%changelog

%files
%doc LICENSE.txt ChangeLog 
%{_libdir}/httpd/modules/mod_token_binding.so
