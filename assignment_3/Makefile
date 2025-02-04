.PHONY: all clean

CXX = g++
CXXFLAGS = --std=c++17 -O2 -Wall -o main

POWER_SRC = power.cpp main_power.cpp
MAXSUM_SRC = maxsum.cpp main_maxsum.cpp

all: power maxsum

power: $(POWER_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

maxsum: $(MAXSUM_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f power maxsum
