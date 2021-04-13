# Makefile

BINARIES: main

all: ${BINARIES}

main: main.o
	g++ -g -Wall -std=c++11 -o main main.cpp block.cpp -I/usr/lib64/ -I/usr/local/lib64/python3.8/site-packages/tensorflow/include/external/boringssl/src/include/ -l:libcrypto.so.1.1

clean:
	/bin/rm -f ${BINARIES} *.o
