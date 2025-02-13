CXX = g++
CXXFLAGS = --std=c++17 -O2 -Wall -o main

default: build

UNIONFIND_SRC = unionfind.cpp

build: main.cpp $(UNIONFIND_SRC)
	$(CXX) $(CXXFLAGS) main.cpp $(UNIONFIND_SRC)

clean:
	@rm main
