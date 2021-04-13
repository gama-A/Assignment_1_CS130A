// Gama Aristondo, 8404071
//
// Coding Assignment 1

#include <iostream>
#include <string>
#include <sstream>

#include "block.h"

using namespace std;

void welcomePrompt() {
    string output = "Welcome to the transaction-chain application....\n"
                    "1) Add a transaction to the chain.\n"
                    "2) Find balance of a person.\n"
                    "3) Print the chain.\n"
                    "4) Exit.\n"
                    "Which operation do you want to make? (1,2,3,4):\n";
    cout << output;
}

int main() {
    bool status = true;
    block t_Chain;
    int input, a, balance;
    string s, r, name;
    while(status) {
        welcomePrompt();
        cin >> input;
        if(input == 1) {
            cout << "Integer amount of money:\n";
            cin >> a;
            cout << "Sender name\n";
            cin >> s;
            cout << "Receiver name\n";
            cin >> r;
            t_Chain.add(a,s,r);
        }else if(input == 2) {
            cout << "Person Name\n";
            cin >> name;
            balance = t_Chain.getBalance(name);
            cout << balance << endl;
        }else if(input == 3) {
            t_Chain.printChain();
        }else if(input == 4) {
            status = false;
        }else {
            cout << "wrong operation!\n";
        }
    }
    return 0;
}
