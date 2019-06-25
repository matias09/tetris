#/usr/bin bash

mkdir build/ && cd build/
cmake ../ && make

cp tetris ../ && cd ../
