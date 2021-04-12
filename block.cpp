// Gama Aristondo, 8404071
//
// Function definitions for "block.h"

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>

#include "block.h"

#include <opensll/sha.h>

using namespace std;

string block::hash(const string str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}
/*
 * The above function was found on stack overflow at the following link:
 *
 * https://stackoverflow.com/questions/2262386/generate-sha256-with-openssl-and-c/10632725?fbclid=IwAR01U9DCi2rLvNwMOVWtClfPpvCkEI2ES32YND-OvqESF0TDgZHqwyafNUA
 * 
 * All credits to the original author
 */


block::block() {
    this->head = NULL;
}

block::~block() {
    this->clear();
}

string block::findNonce(int amount, string sender, string receiver) {
    bool notFound = true;
    char x;
    string concatenation, h;
    stringstream ss;
    ss << amount;
    string a = ss.str();
    while(notFound) {
        x = char(rand() % 26 + 97);
        string n(1,x);
        concatenation = a + sender + receiver + n;
        h = hash(concatenation);
        char back = h.back();
        if(back == "0") {
            notFound = false;
        }
    }
    return n;
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
        p->hash = "";
    }else {
        p->prev = head->prev;
        head = p;
        // stub (need to hash previous transaction)
    }
}

int block::getBalance(string name) {
    block *p = head;
    while(p) {
        // stub
    }
}

string block::printChain() {
    return "";
}

void block::clear() {
    block *p = this->head;
    if(p->prev) {
        head = p->prev;
        delete p;
        p = head;
    }
}
