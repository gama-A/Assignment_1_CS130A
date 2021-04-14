// Gama Aristondo, 8404071
//
// Function definitions for "block.h"

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>

#include "block.h"

#include <openssl/sha.h>

using namespace std;

string block::hash256(const string str) {
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
    deleteChain(head);
}

void block::deleteChain(block *p) {
    if(!p) {
        return;
    }else {
        deleteChain(p->prev);
        delete p;
    }
}

string block::findNonce(int amount, string sender, string receiver) {
    char x,y,z;
    string nonce, h;
    stringstream ss;
    ss << amount;
    string a = ss.str();
    bool nonceFound = false;
    while(!nonceFound) {
        nonce = "";
        x = char(rand() % 26 + 97);
        y = char(rand() % 26 + 97);
        z = char(rand() % 26 + 97);
        nonce += x;
        nonce += y;
        nonce += z;
        h = hash256(a + sender + receiver + nonce);
        char back = h.back();
        if(back == '0') {
            nonceFound = true;
        }
    }
    return nonce;
}

void block::add(int amount, string sender, string receiver) {
    string N = findNonce(amount, sender, receiver);
    block *p = new block;
    p->amount = amount;
    p->sender = sender;
    p->receiver = receiver;
    p->nonce = N;
    if(this->head == NULL) {
        head = p;
        p->prev = NULL;
        p->hash = "NULL";
    }else {
        p->prev = this->head;
        this->head = p;
        stringstream ss;
        ss << p->prev->amount;
        string a = ss.str();
        p->hash = hash256(a + p->prev->sender + p->prev->receiver + p->prev->nonce + p->prev->hash);
    }
}

int block::getBalance(string name) {
    int balance = 50;
    block *p = this->head;
    while(p) {
        if(p->sender == name) {
            balance -= p->amount;
        }
        else if(p->receiver == name) {
            balance += p->amount;
        }
        p = p->prev;
    }
    return balance;
}

void block::printChain() {
    block *p = this->head;
    printChainHelper(p);
}

void block::printChainHelper(block* p) {
    if(p->prev) {
        printChainHelper(p->prev);
    }
    cout << "Amount: " << p->amount << endl;
    cout << "Sender: " << p->sender << endl << "Receiver: " << p->receiver << endl;
    cout << "Nonce: " << p->nonce << endl << "Hash: " << p->hash << endl;
}
