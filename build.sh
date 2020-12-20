#! /bin/sh

$DIRECTORY=out/build

if [ ! -d "$DIRECTORY" ]; then
  cmake -B out/build
fi
cd out/build && make
