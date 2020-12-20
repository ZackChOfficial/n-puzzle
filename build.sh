#! /bin/sh

$DIRECTORY=./build

if [ ! -d "$DIRECTORY" ]; then
  cmake -B ./build
fi
cd ./build && make
