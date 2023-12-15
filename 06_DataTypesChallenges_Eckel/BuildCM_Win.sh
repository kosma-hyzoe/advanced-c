#!/bin/sh

TMP="tmp"
echo "+++++++++++++ BUILDING START ++++++++++++" &&\
	rm -rf $TMP &&\
echo "+++ cmake" &&\
	cmake -G "MinGW Makefiles" -DPLATFORM="WINDOWS" -B $TMP -D CMAKE_C_COMPILER=gcc -D CMAKE_CXX_COMPILER=g++ $1 &&\
echo "+++ make" &&\
	make -C $TMP &&\
echo "+++ clean metadata files" &&\
	rm -rf $TMP &&\
echo "+++++++++++++ BUILDING SUCCESSFUL ++++++++++++"
