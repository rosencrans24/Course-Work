// CS 271
// Program Name: Package.cpp
// Author: Joshua Rosencrans    
// Date: 11-29-17
// Purpose:This file contains all the funcion implementations from constructor to accessors and mutators for the package class

#include <iostream>
#include <iomanip>
#include <string>
#include "Package.h"

using namespace std;
// constructor 
Package::Package ( const string &sname, const string &saddress, const string &scity, const string &sstate, const string &szip, const string &rname, 
		  		 const string &raddress, const string &rcity, const string &rstate,const string &rzip, double w, double c  ){
   setSenderName(sname);
   setSenderAddress(saddress);
   setSenderCity(scity);
   setSenderState(sstate);
   setSenderZipCode(szip);
   setRecipientName(rname);
   setRecipientAddress(raddress);
   setRecipientCity(rcity);
   setRecipientState(rstate);
   setRecipientZipCode(rzip);
   setWeight(w);
   setCostPerOunce(c);
} 
// both accessor and mutator for sender name
Package&  Package::setSenderName(const string &sname){
   senderName=sname;
   return *this;
}   
string Package::getSenderName() const{
   return senderName;
}
//both acessor and mutator for sender address
Package& Package::setSenderAddress(const string &saddress){
   senderAddress=saddress;
   return *this;
}   
string  Package::getSenderAddress() const {
   return senderAddress;
}   
//both acessor and mutator for sender city
Package&  Package::setSenderCity(const string &scity){
   senderCity=scity;
   return *this;
}   

string  Package::getSenderCity() const{
   return senderCity;
}
//both acessor and mutator for sender state   
Package&  Package::setSenderState(const string &sstate){
   senderState= sstate;
   return *this;
}   

string  Package::getSenderState() const{
   return senderState;
}
//both acessor and mutator for sender zip code   
Package&  Package::setSenderZipCode(const string &szip){
   senderZip = szip;
   return *this;
}

string  Package::getSenderZipCode() const{
      return senderZip;
}
//both acessor and mutator for recipiant name    
Package&  Package::setRecipientName(const string &rname){
   recipientName = rname;
   return *this;
}
string  Package::getRecipientName() const{
   return recipientName;
}
//both acessor and mutator for recipient address
Package&  Package::setRecipientAddress(const string &raddress){
   recipientAddress = raddress;
   return *this;
}
string  Package::getRecipientAddress() const{
   return recipientAddress;
}
//both acessor and mutator for recipient city
Package&  Package::setRecipientCity(const string &rcity){
   recipientCity = rcity;
   return *this;
}
string Package::getRecipientCity() const{
   return recipientCity;
}
//both acessor and mutator for recipient state
Package&  Package::setRecipientState(const string &rstate){
   recipientState = rstate;
   return *this;
}
string  Package::getRecipientState() const{
   return recipientState;
}
//both acessor and mutator for recipient zip code
Package&  Package::setRecipientZipCode(const string &rzip){
   recipientZip = rzip;
   return *this;
}
string  Package::getRecipientZipCode() const{
   return recipientZip;
}
//mutator for weight making sure it is not negative
Package&  Package::setWeight(double w){
   if (w<0){
      weight = weight;
   }
   else
      weight = w;
   return *this;
}
// accessor for weight
double  Package::getWeight() const{
   return weight;
}
// mutator for cost per ounce making sure that it stays positive
Package&  Package::setCostPerOunce(double c){
   if(c<0){
      costPerOunce = costPerOunce;
   }
   else
      costPerOunce = c;
   return *this;
}
// accessor for cost per ounce
double  Package::getCostPerOunce() const{
   return costPerOunce;
}
// function that calculates the cost to ship a package
double  Package::calculateCost() const{
   return weight * costPerOunce;
}
// overloaded ostream operator making printing look nice 
ostream &operator<<(ostream& out, const Package& p){
   out <<"Sender Information"<< endl <<p.getSenderName() << endl << p.getSenderAddress() << endl 
       << p.getSenderCity() << "  " << p.getSenderState() << "  " << p.getSenderZipCode() << endl
       <<"Recipient Information" << endl << p.getRecipientName() << endl << p.getRecipientAddress()
       << endl << p.getRecipientCity() << "  " << p.getRecipientState() << "  " << p.getRecipientZipCode()
       << endl << "Shipping information" << endl << "Weight: " << p.getWeight() << endl << "Cost per Ounce: "
       << p.getCostPerOunce()<< endl << "Cost to ship: $" << p.calculateCost() ;
   return out;
}