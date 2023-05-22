#!/bin/bash

# compile the shared object
gcc -shared -o lib/libstrfun.so -fPIC src/strfun.c
# compile the object file for main
gcc -o obj/main.o -I ./incl -c src/main.c
# link the library and compile the executable

gcc -o run obj/main.o -L./lib -lstrfun # on windows: `-llibstrfun.dll`
# `export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH` if -L is not used