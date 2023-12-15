#!/bin/sh

TMP="tmp"
echo "+++++++++++++ BUILDING START ++++++++++++" &&\
	rm -rf $TMP &&\
	mkdir $TMP &&\
	cd $TMP &&\
echo "+++ cmake" &&\
	cmake -DPLATFORM="LINUX" .. &&\
echo "+++ make" &&\
	make &&\
echo "+++ clean metadata files" &&\
	cd .. &&\
	rm -rf $TMP &&\
echo "+++++++++++++ BUILDING SUCCESSFUL ++++++++++++"
