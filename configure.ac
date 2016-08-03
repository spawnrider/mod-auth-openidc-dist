AC_INIT([mod_auth_openidc-dist],[1.0],[hzandbelt@pingidentity.com])

#AC_SUBST([MOD_AUTH_OPENIDC_VERSION], 1.8.10.1)
AC_SUBST([MOD_AUTH_OPENIDC_VERSION], [2.0.0rc0])
AC_SUBST([CJOSE_VERSION], [0.4.0])

AC_SUBST_FILE([CENTOS_6_DOCKER_INCLUDE])
CENTOS_6_DOCKER_INCLUDE=$srcdir/centos/6/Dockerfile.include

AC_SUBST_FILE([CENTOS_CJOSE_SPEC])
CENTOS_CJOSE_SPEC=$srcdir/centos/cjose.spec

AC_CONFIG_FILES([centos/6/build/cjose.spec])
AC_CONFIG_FILES([centos/6/build/Dockerfile])
AC_CONFIG_FILES([centos/6/run/Dockerfile])

AC_OUTPUT
