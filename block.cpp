// Gama Aristondo, 8404071
//
// Function definitions for "block.h"

#include <iostream>
#include <string>
#include <sstream>

#include "block.h"

using namespace std;

block::block() {
    // stub
}

block::~block() {
    clear();
}

void block::add(int amount, string sender, string receiver) {
    // stub
}

int block::getBalance(string name) {
    return 0;
}

string block::printChain() {
    return "";
}

void block::clear() {
    block *p = head;
    if(p->prev) {
        head = p->prev;
        delete p;
        p = head;
    }
}
