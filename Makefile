progname=partition_numbers
builddir=build
srcdir=src

.PHONY: build clean

default: build

build:
	if [ ! -e ${builddir} ];then mkdir ${builddir};fi
	gcc -O2 -o ${builddir}/${progname} ${srcdir}/${progname}.c -lgmp
clean:
	rm build/*
