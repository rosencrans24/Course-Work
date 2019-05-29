// CS 271
// Program Name: lab5.cpp
// Author: Joshua Rosencrans    
// Date: 10-11-17 
// Purpose: This is the test file for the BankAccount class, testing everything inside the class

#include <iostream>
#include <iomanip>
#include "BankAccount.h"

using namespace std;

int main(){
    // testing default constructor and display
    cout <<"Testing default constructor" << endl;
    BankAccount joshChecking;
    joshChecking.display();

    //testing other constructor and display
    cout <<"Testing other constructor" << endl;
    BankAccount joesChecking("Joe","Smith",1234);
     joesChecking.display();

    // Testing mutators
    cout << endl << "Testing mutators" << endl << "Bank account before " << endl;
    joshChecking.display();
    joshChecking.setFirstName("Joshua");
    joshChecking.setLastName("Rosencrans");
    joshChecking.setAccountNumber(5678);
    cout << "Bank account after" << endl;
    joshChecking.display();
    cout << endl;

    // testing accessors
    cout <<"Testing accessors" << endl;
    cout <<"First name is: " << joshChecking.getFirstName() << endl << 
         "Last name is: " << joshChecking.getLastName() << endl << 
         "Acount number is: " << joshChecking.getAccountNumber() << endl;
} // end main 