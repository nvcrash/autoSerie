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

# Makefile.am inspired from bison Makefile.am


# file created  by Tom SCHNEIDER <dev.tomschneider@gmail.com>
# file modified by ...



SUBDIRS = test
AUTOMAKE_OPTIONS = -Wportability foreign subdir-objects
AM_CXXFLAGS = $(INTI_CXXFLAGS) -Wall -Wextra -pedantic -std=c++17 -Wstack-protector
AM_CPPFLAGS = -I. -Ilib -I$(top_srcdir) -I$(top_srcdir)/lib
ACLOCAL_AMFLAGS= -I m4cros

BUILT_SOURCES =
CLEANFILES =
DISTCLEANFILES =
# DOXYGEN SUPPORT
include $(top_srcdir)/doxygen/aminclude.am

EXTRA_DIST = doxygen/doxygen.cfg gaogi.supp
# EXTRA_DIST += $(dist_TESTS)
MOSTLYCLEANDIRS =
MOSTLYCLEANFILES =
SUFFIXES =
# TESTS = $(dist_TESTS)

VALGRIND_SUPPRESSIONS_FILES = gaogi.supp




#include src/local.mk
#include lib/local.mk
