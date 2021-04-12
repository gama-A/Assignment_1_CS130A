// Gama Aristondo, 8404071
//
// Function definitions for "block.h"

#include <iostream>
#include <string>
#include <sstream>

#include "block.h"

using namespace std;

block::block() {
    this->head = NULL;
}

block::~block() {
    clear();
}

void block::add(int amount, string sender, string receiver) {
    block *p = new block;
    p->amount = amount;
    p->sender = sender;
    p->receiver = receiver;
    string N = *p.findNonce(amount, sender, receiver);
    p->nonce = N;
    if(this->head == NULL) {
        head = p;
        p->prev = NULL;
    }else {
        p->prev = head->prev;
        head = p;
    }
}

int block::getBalance(string name) {
    return 0;
}

string block::printChain() {
    return "";
}

void block::clear() {
    block *p = this;
    if(p->prev) {
        head = p->prev;
        delete p;
        p = head;
    }
}
