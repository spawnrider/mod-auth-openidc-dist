Name:		cjose
Version:	%{release}
Release:	1%{?dist}
Summary:	JOSE implementation for C

Group:		Networking/Daemons/HTTP
License:	Apache License Version 2.0
URL:		https://github.com/cisco/cjose
Source0:        cjose-%{version}.tar.gz

Requires:       openssl, jansson
BuildRequires:	openssl-devel, jansson-devel, check-devel

%description
JOSE implementation for C

%prep
%setup -q

%define debug_package %{nil}
%build

%configure
make test

%install
%make_install 

%clean
rm -rf $RPM_BUILD_ROOT

%files
%{_includedir}/cjose/base64.h
%{_includedir}/cjose/cjose.h
%{_includedir}/cjose/error.h
%{_includedir}/cjose/header.h
%{_includedir}/cjose/jwe.h
%{_includedir}/cjose/jwk.h
%{_includedir}/cjose/jws.h
%{_includedir}/cjose/util.h
%{_includedir}/cjose/version.h
%{_libdir}/libcjose.a
%{_libdir}/libcjose.la
%{_libdir}/libcjose.so
%{_libdir}/libcjose.so.0
%{_libdir}/libcjose.so.0.0.0
%{_libdir}/pkgconfig/cjose.pc

%changelog
