#! /bin/sh

DIRECTORY="build"

if [ ! -d $DIRECTORY ]; then
  cmake -B $DIRECTORY
fi
cd ./build && make
