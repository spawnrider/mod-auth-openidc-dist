AC_INIT([mod_auth_openidc-dist],[1.0],[hzandbelt@pingidentity.com])

#AC_SUBST([MOD_AUTH_OPENIDC_VERSION], 1.8.10.1)
AC_SUBST([MOD_AUTH_OPENIDC_VERSION], [2.0.0rc0])
AC_SUBST([CJOSE_VERSION], [0.4.1])

AC_SUBST_FILE([CENTOS_CJOSE_SPEC_INC])
CENTOS_CJOSE_SPEC_INC=$srcdir/centos/cjose.spec.inc

AC_SUBST_FILE([CENTOS_MOD_AUTH_OPENIDC_SPEC_INC])
CENTOS_MOD_AUTH_OPENIDC_SPEC_INC=$srcdir/centos/mod_auth_openidc.spec.inc

AC_SUBST_FILE([CENTOS_6_INC])
CENTOS_6_INC=$srcdir/centos/6/centos6.inc

AC_SUBST_FILE([CENTOS_7_INC])
CENTOS_7_INC=$srcdir/centos/7/centos7.inc

AC_SUBST_FILE([CENTOS_BUILD])
CENTOS_BUILD=$srcdir/centos/build.inc

AC_SUBST_FILE([CENTOS_BUILD_CJOSE])
CENTOS_BUILD_CJOSE=$srcdir/centos/build.cjose

AC_SUBST_FILE([CENTOS_BUILD_MOD_AUTH_OPENIDC])
CENTOS_BUILD_MOD_AUTH_OPENIDC=$srcdir/centos/build.mod_auth_openidc

AC_SUBST_FILE([CENTOS_INSTALL_CJOSE])
CENTOS_INSTALL_CJOSE=$srcdir/centos/install.cjose

AC_SUBST_FILE([CENTOS_INSTALL_MOD_AUTH_OPENIDC])
CENTOS_INSTALL_MOD_AUTH_OPENIDC=$srcdir/centos/install.mod_auth_openidc

AC_CONFIG_FILES([centos/6/build/cjose.spec centos/6/build/mod_auth_openidc.spec centos/6/build/Dockerfile])
AC_CONFIG_FILES([centos/6/run/Dockerfile])

AC_CONFIG_FILES([centos/7/build/cjose.spec centos/7/build/mod_auth_openidc.spec centos/7/build/Dockerfile])
AC_CONFIG_FILES([centos/7/run/Dockerfile])

AC_OUTPUT