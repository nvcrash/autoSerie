AUTOMAKE_OPTIONS = -Wportability foreign subdir-objects
AM_CXXFLAGS = $(INTI_CXXFLAGS) -Wall -Wextra -pedantic -std=c++17 -Wstack-protector -Winline -g3
AM_CPPFLAGS = -I. -Ilib -I$(top_srcdir) -I$(top_srcdir)/lib
ACLOCAL_AMFLAGS= -I m4cros
check_PROGRAMS=execute serial serial_string serial_tuple serial_vector 
TESTS=${check_PROGRAMS}
@VALGRIND_CHECK_RULES@
dist_TESTS =
VALGRIND_SUPPRESSIONS_FILES = execute.supp serial.supp serial_string.supp serial_tuple.supp serial_vector.supp 
EXTRA_DIST = execute.supp serial.supp serial_string.supp serial_tuple.supp serial_vector.supp 
execute_SOURCES=execute.cc
serial_SOURCES=serial.cc
serial_string_SOURCES=serial_string.cc
serial_tuple_SOURCES=serial_tuple.cc
serial_vector_SOURCES=serial_vector.cc
