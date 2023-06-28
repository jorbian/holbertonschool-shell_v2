#!/usr/bin/bash

FLAGS="-Wall -Werror -Wextra -pedantic"
INC="-Iinclude"
LIB=lib/*

gcc $FLAGS *.c lib/* $INC
#gcc -static *.c lib/*.a -Iinclude