AC_INIT([mod_auth_openidc-dist],[1.0],[hans.zandbelt@zmartzone.eu])

AC_SUBST([MOD_AUTH_OPENIDC_VERSION], [2.3.3rc0])
AC_SUBST([CJOSE_VERSION], [0.5.1])

#
# CentOS
#

AC_SUBST_FILE([CENTOS_CJOSE_SPEC_INC])
CENTOS_CJOSE_SPEC_INC=$srcdir/centos/cjose.spec.inc

AC_SUBST_FILE([CENTOS_MOD_AUTH_OPENIDC_SPEC_INC])
CENTOS_MOD_AUTH_OPENIDC_SPEC_INC=$srcdir/centos/mod_auth_openidc.spec.inc

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

# CentOS 6

AC_SUBST_FILE([CENTOS_6_INC])
CENTOS_6_INC=$srcdir/centos/6/centos6.inc

AC_CONFIG_FILES([centos/6/build/cjose.spec centos/6/build/mod_auth_openidc.spec centos/6/build/Dockerfile])
AC_CONFIG_FILES([centos/6/run/Dockerfile])

# CentOS 7

AC_SUBST_FILE([CENTOS_7_INC])
CENTOS_7_INC=$srcdir/centos/7/centos7.inc

AC_CONFIG_FILES([centos/7/build/cjose.spec centos/7/build/mod_auth_openidc.spec centos/7/build/Dockerfile])
AC_CONFIG_FILES([centos/7/run/Dockerfile])

#
# Debian
#

AC_SUBST_FILE([DEBIAN_BUILD])
DEBIAN_BUILD=$srcdir/debian/build.inc

AC_SUBST_FILE([DEBIAN_BUILD_CJOSE])
DEBIAN_BUILD_CJOSE=$srcdir/debian/build.cjose

AC_SUBST_FILE([DEBIAN_BUILD_MOD_AUTH_OPENIDC])
DEBIAN_BUILD_MOD_AUTH_OPENIDC=$srcdir/debian/build.mod_auth_openidc

AC_SUBST_FILE([DEBIAN_INSTALL_CJOSE])
DEBIAN_INSTALL_CJOSE=$srcdir/debian/install.cjose

AC_SUBST_FILE([DEBIAN_INSTALL_MOD_AUTH_OPENIDC])
DEBIAN_INSTALL_MOD_AUTH_OPENIDC=$srcdir/debian/install.mod_auth_openidc

# Debian Jessie

AC_SUBST_FILE([DEBIAN_JESSIE_INC])
DEBIAN_JESSIE_INC=$srcdir/debian/jessie/jessie.inc

AC_CONFIG_FILES([debian/jessie/build/debian-cjose/changelog debian/jessie/build/debian-mod_auth_openidc/changelog debian/jessie/build/Dockerfile])
AC_CONFIG_FILES([debian/jessie/run/Dockerfile])

# Debian Wheezy

AC_SUBST_FILE([DEBIAN_WHEEZY_INC])
DEBIAN_WHEEZY_INC=$srcdir/debian/wheezy/wheezy.inc

AC_CONFIG_FILES([debian/wheezy/build/debian-cjose/changelog debian/wheezy/build/debian-mod_auth_openidc/changelog debian/wheezy/build/Dockerfile])
AC_CONFIG_FILES([debian/wheezy/run/Dockerfile])

# Debian Stretch

AC_SUBST_FILE([DEBIAN_STRETCH_INC])
DEBIAN_STRETCH_INC=$srcdir/debian/stretch/stretch.inc

AC_CONFIG_FILES([debian/stretch/build/debian-cjose/changelog debian/stretch/build/debian-mod_auth_openidc/changelog debian/stretch/build/Dockerfile])
AC_CONFIG_FILES([debian/stretch/run/Dockerfile])

#
# Ubuntu
#

# Ubuntu Precise

AC_CONFIG_FILES([ubuntu/precise/run/Dockerfile])

# Ubuntu Trusty

AC_SUBST_FILE([UBUNTU_TRUSTY_INC])
UBUNTU_TRUSTY_INC=$srcdir/ubuntu/trusty/trusty.inc

AC_CONFIG_FILES([ubuntu/trusty/build/debian-cjose/changelog ubuntu/trusty/build/debian-mod_auth_openidc/changelog ubuntu/trusty/build/Dockerfile])
AC_CONFIG_FILES([ubuntu/trusty/run/Dockerfile])

# Ubuntu Wily

AC_SUBST_FILE([UBUNTU_WILY_INC])
UBUNTU_WILY_INC=$srcdir/ubuntu/wily/wily.inc

AC_CONFIG_FILES([ubuntu/wily/build/debian-cjose/changelog ubuntu/wily/build/debian-mod_auth_openidc/changelog ubuntu/wily/build/Dockerfile])
AC_CONFIG_FILES([ubuntu/wily/run/Dockerfile])

# Ubuntu Xenial

AC_CONFIG_FILES([ubuntu/xenial/run/Dockerfile])

# Ubuntu Yakkety

AC_CONFIG_FILES([ubuntu/yakkety/run/Dockerfile])

#
# the end
#

AC_OUTPUT
