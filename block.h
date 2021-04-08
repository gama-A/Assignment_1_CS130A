// Gama Aristondo, 8404071
//
// Header file for block chain class

#ifndef BLOCK_H
#define BLOCK_H

class block
{
    public:

    private:
        block *prev;       // points to previous block transaction
        int amount;        // stores the amount of money transferred
        string sender;     // name of sender of money
        string receiver;   // name of receiver of money
        string nonce;      // random string used to simulate PoW
        string hash;       // hash of the previous block contents

}

#endif
