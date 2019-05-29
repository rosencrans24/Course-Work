// CS 271
// Program Name: TwoDayPackage.h
// Author: Joshua Rosencrans    
// Date: 11-29-17
// Purpose:This is the header file containing the function prototypes for the TwoDayPackage class

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H
#include "Package.h"
#include <iostream>
#include <string>

using namespace std;

class TwoDayPackage : public Package {

      friend ostream &operator<<(ostream &,const TwoDayPackage &);
      public:
            TwoDayPackage( const string &, const string &, const string &, const string &, const string&, const string &, const string &, 
		     	   const string &, const string &, const string &, double = 0.0, double = 0.0, double = 0.0 );
            TwoDayPackage& setFlatFee( double );
            double getFlatFee( ) const;
            double calculateCost( ) const;
      private:
      double flatFee;

};
#endif
 
