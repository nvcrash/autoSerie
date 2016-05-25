#!/bin/bash

here=$(pwd -P)
cd $(dirname $0)
there=$(pwd -P)

cd $there

CCFILES=`echo *.cc`
echo $CCFILES
PRGS=`echo $CCFILES | tr ' ' '\n' | sed -E 's/[.]cc$//' | tr '\n' ' '`

echo $PRGS
cat <<EOF > $there/Makefile.am
AUTOMAKE_OPTIONS = -Wportability foreign subdir-objects
AM_CXXFLAGS = \$(INTI_CXXFLAGS) -Wall -Wextra -pedantic -std=c++17 -Wstack-protector -Winline -g3
AM_CPPFLAGS = -I. -Ilib -I\$(top_srcdir) -I\$(top_srcdir)/lib
ACLOCAL_AMFLAGS= -I m4cros
check_PROGRAMS=$PRGS
TESTS=\${check_PROGRAMS}
@VALGRIND_CHECK_RULES@
dist_TESTS =
VALGRIND_SUPPRESSIONS_FILES = $(echo $CCFILES | tr ' ' '\n' | sed -E 's/[.]cc$/.supp/' | tr '\n' ' ')
EXTRA_DIST = $(echo $CCFILES | tr ' ' '\n' | sed -E 's/[.]cc$/.supp/' | tr '\n' ' ')
EOF
for a in $PRGS
do
    echo "${a}_SOURCES=${a}.cc" >> $there/Makefile.am
    touch "${a}.supp"
done
