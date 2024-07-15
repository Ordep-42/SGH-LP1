#!/bin/bash

cd build
wait
cmake ..
wait
make
./SGH-LP1
