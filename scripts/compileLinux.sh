#!/bin/bash

cd ../source

g++ -c Logger/Piner.cpp -o ../build/objects/Piner.o

g++ -c Render/Frame.cpp -o ../build/objects/Frame.o

g++ -c Storage/Buffer.cpp -o ../build/objects/Buffer.o
g++ -c Storage/Stream.cpp -o ../build/objects/Stream.o

g++ -c MainTest.cpp -o ../build/objects/MainTest.o

cd ../build/objects
g++ Piner.o Frame.o Buffer.o Stream.o MainTest.o -o ../debug/main

cd ../../scripts
