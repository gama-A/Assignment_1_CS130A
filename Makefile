# Makefile

BINARIES: main

all: ${BINARIES}

main: main.o
	g++ -g -Wall -std=c++11 -o main main.cpp block.cpp -L/usr/local/opt/openssl@1.1/lib -lcrypto

clean:
	/bin/rm -f ${BINARIES} *.o main
