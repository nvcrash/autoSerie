#!/bin/sh
aclocal \
    && automake --gnu --add-missing \
    && autoconf \
    && autoheader \
    && ./configure --enable-valgrind
