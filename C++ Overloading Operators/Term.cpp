// CS 271
// Program Name: Term.cpp
// Author: Joshua Rosencrans    
// Date: 11-1-17
// Purpose: This program contains all the function definitions used in the Term class

#include <iostream>
#include <iomanip>
#include "Term.h"

using namespace std;

// default constructor
Term::Term (int coef, int ex){
   setCoefficient(coef);
   setExponent(ex);
}
// mutator for setting the coefficent
void Term::setCoefficient(int c){
   coefficient = c;
}
//mutator for setting the exponent
void Term::setExponent(int e){
   exponent = e ;
}
// acessor for getting the value of the coefficient 
int Term::getCoefficient()const{
   return coefficient;
}
// acessor for getting the value of the exponent
int Term::getExponent()const{
   return exponent;
}
// operator overload for the addition operator
Term Term::operator+(const Term& second) const{
   int coef;
   int expon;
   if(exponent == second.getExponent()){
      coef = coefficient + second.getCoefficient();
      expon = exponent;
      Term answer(coef,expon);
      return answer;
   }
   else{ 
      cout << "Could not add objects exponents are not the same " << second << " and ";
      Term answer(coefficient,exponent);
      return answer;
   }    
}   
// operator overload for the subtraction operator
Term Term::operator-(const Term& sec) const{
   int coef;
   int expon;
   if(exponent == sec.getExponent()){
      coef = coefficient - sec.getCoefficient();
      expon = exponent;
      Term answer(coef,expon);
      return answer;
   }
   else{ 
      cout << "Could not subtract objects exponents are not the same " << sec << " and ";
      Term answer(coefficient,exponent);
      return answer;
   }
}
// overload operator for multiplication
Term Term::operator*(const Term & mul)const{
   int coef = coefficient * mul.getCoefficient();
   int expon = exponent + mul.getExponent();
   Term answer(coef,expon);
   return answer;
}
// overlad operator for stream instertion
ostream &operator<<(ostream& out, const Term& x){
   out << x.getCoefficient() << "x^" << x.getExponent();
   return out;
}
//overload operator for the stream extraction
istream &operator>>(istream &in,Term& y){
   int coef;
   int expon;
   in >> coef >> expon;
   y.setCoefficient(coef);
   y.setExponent(expon);
   return in;
}