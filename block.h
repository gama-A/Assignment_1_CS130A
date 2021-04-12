// Gama Aristondo, 8404071
//
// Header file for block chain class

#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <string>

class block
{
    public:
        block();
        // Default constructor

        ~block();
        // Decstructor for block transaction-chain

        void add(int amount, std::string sender, std::string receiver);
        // Adds a transaction to the chain
        // View as a constructor

        int getBalance(std::string name);
        // Gets the balance of the given person 

        std::string printChain();
        // Prints the entire contents of the chain

    private:
        block *head;       // points to the head of the chain

        block *prev;       // points to previous block transaction
        int amount;        // stores the amount of money transferred
        string sender;     // name of sender of money
        string receiver;   // name of receiver of money
        string nonce;      // random string used to simulate PoW
        string hash;       // hash of the previous block contents

        void clear();      // will aid in the deletion of chain
}

#endif
