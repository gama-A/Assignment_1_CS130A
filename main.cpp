// Gama Aristondo, 8404071
//
// Coding Assignment 1

#include <iostream>
#include <string>
#include <sstream>

// #include CLASS_NAME.h

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
    while(status) {
        welcomePrompt();
        cin >> input;
        if(input == 1) {
            // stub
        }else if(input == 2) {
            // stub
        }else if(input == 3) {
            // stub
        }else if(input == 4) {
            status = false;
        }else {
            cout << "wrong operation!\n";
            // stub
        }
    }
    return 0;
}
