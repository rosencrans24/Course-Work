// CS 271
// Program Name: Package.h
// Author: Joshua Rosencrans    
// Date: 11-29-17
// Purpose: This is the header file containing the function prototypes for the package class

#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include <string>

using namespace std;

class Package {

friend ostream& operator<<(ostream&,const Package&);
public: 
	Package ( const string &, const string &, const string &, const string &, const string&, const string &, 
		  		 const string &, const string &, const string &,const string &, double = 0.0, double = 0.0 ); 

	Package& setSenderName(const string &);
   string getSenderName() const;

	Package& setSenderAddress(const string &);
  	string getSenderAddress() const ;

	Package& setSenderCity(const string &);
  	string getSenderCity() const;

	Package& setSenderState(const string &);
  	string getSenderState() const;
	
	Package& setSenderZipCode(const string &);
  	string getSenderZipCode() const;
      
	Package& setRecipientName(const string &);
  	string getRecipientName() const;

	Package& setRecipientAddress(const string &);
  	string getRecipientAddress() const;

	Package& setRecipientCity(const string &);
  	string getRecipientCity() const;

	Package& setRecipientState(const string &);
  	string getRecipientState() const;

	Package& setRecipientZipCode(const string &);
  	string getRecipientZipCode() const;

	Package& setWeight(double);
  	double getWeight() const;

	Package& setCostPerOunce(double);
   double getCostPerOunce() const;
      
	double calculateCost() const;


   private:
      	string senderName;
      	string senderAddress;
      	string senderCity;
     		string senderState;
      	string senderZip;
      
      	string recipientName;
      	string recipientAddress;
      	string recipientCity;
      	string recipientState;
      	string recipientZip;

      	double weight;
      	double costPerOunce;

};


#endif








