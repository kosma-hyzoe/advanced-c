#!/bin/bash

gcc -shared -o libstrfun.so -fPIC src/strfun.c
gcc -o run -Iincl -L. -lstrfun src/main.c
