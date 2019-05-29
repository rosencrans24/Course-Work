// CS 271
// Program Name: Term.cpp
// Author: Joshua Rosencrans    
// Date: 11-1-17
// Purpose:This is the driver program for the Term class
#include <iostream>
#include <iomanip>
#include "Term.h"

using namespace std;

int main (){
   // testing the constructor
   Term one(5,6);
   Term two(2,6);
   Term three;
   // testing the stream extraction overloaded operator
   cout << "please enter a number for the coefficient and exponent" << endl;
   cin >> three;
   // testing the stream insertion overloaded operator
   cout  << "Testing the stream insertion overloaded operator"<< endl;
   cout << one << endl << two << endl << three << endl;
   // testing the addition overloaded operator with same and different exponents
   cout << endl << "Testing addition of two Term objects" << endl;
   cout <<"The sum of " << one << " and " << two << " is " << one + two << endl;
   cout << one + three << endl;
   // testing the subtraction overloaded operator with same and differnt exponents
   cout << endl << "Testing subtraction of two Term objects" << endl;
   cout <<"The differnce of " << one << " and " << two << " is " << one - two << endl;
   cout << one - three << endl;
   // testing the multiplicaion overloaded operator with same and differnt exponents
   cout << endl << "Testing the multiplication of two Term objects" << endl;
   cout << "The product of "<< one << " and " << two << " is " << one * two << endl;
   cout << "The product of "<< one << " and " << three << " is " << one * three << endl;

   // testing the mutatuor and acessor for both coefficient and exponent
   cout << endl << "Testing the mutatuor and acessor for both coefficient and exponent" << endl;
   cout << "Original " << one << endl;
   one.setCoefficient(2);
   cout << "Changed coefficient " << one.getCoefficient() << endl;
   one.setExponent(10);
   cout << "Changed exponent " << one.getExponent() << endl;
   cout << "After mutators " << one << endl;

}