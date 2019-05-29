// CS 271
// Program Name: Term.cpp
// Author: Joshua Rosencrans    
// Date: 11-1-17
// Purpose: This is the header file for the Term class contaiing all the prototypes

#ifndef TERM_H
#define TERM_H

#include <iostream>
#include <iomanip>

using namespace std;
class Term
{
 friend ostream &operator<<( ostream &, const Term & );
 friend istream &operator>>( istream &, Term & );

 private:
   int coefficient;
   int exponent;
 public:
   Term ( int coef = 0, int ex = 0 );
   void setCoefficient ( int c );
   void setExponent ( int e );
   int getCoefficient () const ;
   int getExponent( ) const ;
   Term operator+ (const Term & ) const;
   Term operator- (const Term & ) const;
   Term operator* (const Term & ) const;
}; 

#endif