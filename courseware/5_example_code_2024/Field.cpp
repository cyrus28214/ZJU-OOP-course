#include <iostream>
using namespace std;

class TicketMachine {
public:
    int balance; // This is the class member variable (field)

    // Constructor to initialize balance
    TicketMachine(int b) : balance(b) {}

    int refundBalance();
    
};

// Function refundBalance
int TicketMachine::refundBalance() {
    // int balance = 0; // This is a local variable with the same name as the field
    balance = 100; 
    return balance; 
}


int main() {
    TicketMachine tm(500); // Create a TicketMachine object with an initial balance of 500
    cout << "Refunded amount: " << tm.refundBalance() << endl; // Outputs 100 (the value of the local variable)
    cout << "Current balance: " << tm.balance << endl; // Outputs 500 (the value of the member variable)
    return 0;
}
