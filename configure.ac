AC_INIT([dgtnix], [1.9.1], [dgtnix-devel@lists.sourceforge.net])
AC_PREREQ([2.60])
AC_CHECK_LIB([pthread], [pthread_create], [PTHREADLIB=-lpthread], [echo dgtnix require the pthread librairie.; exit])
AC_CONFIG_MACRO_DIR([m4])
AX_SET_VERSION_INFO[]
AC_SUBST([PTHREADLIB])
AC_CONFIG_SRCDIR(src/dgtnix.c)
AC_CONFIG_AUX_DIR(build-aux)
AM_INIT_AUTOMAKE([-Wall -Werror 1.9.6])
AC_PROG_CC
AC_PROG_CXX
AC_PROG_LIBTOOL
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile utils/Makefile man/Makefile])
AC_OUTPUT
