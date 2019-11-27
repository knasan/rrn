#!/bin/bash

# Buildscript helper for macOSx and Linux

flags="-std=c++17 -lboost_system -lboost_filesystem -lboost_program_options"
includes="-I/usr/local/lib/include/"
bindir="build/bin"
mkdir -p $bindir
rm -f $bindir/rrn

clang++ \
	main.cpp \
	rrn.cpp \
	$flags \
	$includes \
	-Wall \
	-o $bindir/rrn

if [ -f $bindir/rrn ]; then
  echo "Build Success"
fi
