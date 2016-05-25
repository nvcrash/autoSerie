# Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/>
#
# Everyone is permitted to copy and distribute verbatim copies
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.



# file created  by Tom SCHNEIDER <dev.tomschneider@gmail.com>
# file modified by ...



AC_INIT([autoSerie], [0.0.1])
# if testing



[MISSING_PROGS=1]
[MISSING_HEADERS=2]
[MISSING_LIB=3]

AC_PREREQ([2.69])

dnl #AM_SILENT_RULES([yes])

m4_include([doxygen/acinclude.m4])
m4_include([m4/ax_valgrind_check.m4])
AC_CONFIG_HEADERS([include/config.h:include/config.h.in])
AC_DEFINE(DEVEL, 1,[0 if release, debug level otherwise])
AC_DEFINE(SHARED_PAGE_SIZES_BITS, [11], log2 of the network share page size)
#AC_DEFINE(SHARED_PAGE_SIZES_BITS, [11], log2 of the network share page size)
AC_DEFINE(DEBUG_STREAM, std::cerr, [enabled if DEVEL is not 0, cerr by default for std::cerr, can be 'cout' for std::cout otherwise])
AC_DEFINE(DEBUG_SERIAL, true, [enabled if DEVEL is not 0, true by default])
AC_CONFIG_MACRO_DIR(aclocal)
# compiler option
# Checks for the compiler.
AC_PROG_CC_STDC
AC_PROG_CXX
AC_PROG_RANLIB

AC_LANG([C++])

# required programs for testing
[if test "$DEVEL" = "1"; then]
./tests/gentest.sh
AC_CHECK_PROGS([VALGRIND], [valgrind])
AC_CHECK_PROGS([GDB], [gdb])
AC_CHECK_PROGS([QUEMU], [QUEMU-])
[fi]

AX_VALGRIND_CHECK

#AC_CONFIG_SRCDIR([src/main.cc])


AM_INIT_AUTOMAKE
######################################################################
# DOXYGEN SUPPORT
######################################################################

DX_HTML_FEATURE(ON)
DX_CHM_FEATURE(OFF)
DX_CHI_FEATURE(OFF)
DX_MAN_FEATURE(OFF)
DX_RTF_FEATURE(OFF)
DX_XML_FEATURE(OFF)
DX_PDF_FEATURE(OFF)
DX_PS_FEATURE(OFF)

DX_INIT_DOXYGEN([$PACKAGE_NAME],[doxygen/doxygen.cfg],[doc])

######################################################################

AC_CONFIG_FILES([Makefile test/Makefile])

AC_PROG_CXX


AC_OUTPUT
