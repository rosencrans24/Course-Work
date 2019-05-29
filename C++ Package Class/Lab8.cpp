// CS 271
// Program Name: Lab8.cpp
// Author: Joshua Rosencrans    
// Date: 11-29-17
// Purpose: This file is the driver file testing both the Package and TwoDayPackage classes

#include <iostream>
#include <iomanip>
#include <string>
#include "Package.h"
#include "TwoDayPackage.h"

using namespace std;

int main(){
   //testng using constructor which also test mutators since they are called inside 
   Package firstPackage("Joshua Rosencrans", "8031 Raging bull pl", "Mesilla Park", "NM", "88047", "Adriana Freitas",
           "450 West Palmer", "Las Cruces", "NM", "88005", 5,1.50);
   //testng using TwoDayPackage constructor which also test mutators since they are called inside        
   TwoDayPackage secondPackage("Gabriel Rosencrans", "8031 Raging bull pl", "Mesilla Park", "NM", "88047", "Christina Freitas",
           "450 West Palmer", "Las Cruces", "NM", "88005", 20,2.50,5);
   // testing the ostream overloaded operator for both pakcage and TwoDay Package
   cout << firstPackage << endl;
   cout << endl <<secondPackage << endl;
   //  making sure the weight wont be changed if a negaive number is passed 
   firstPackage.setWeight(-2);
   secondPackage.setFlatFee(-12);
   cout << endl <<"Testing the mutators" << endl;
   cout << firstPackage.getWeight()<< endl << secondPackage.getFlatFee() << endl ;

}