# Makefile

CXX = g++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

# CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

BINARIES: main

all: ${BINARIES}

main: main.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o
