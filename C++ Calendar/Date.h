// CS 271
// Program Name: Date.h
// Author: Joshua Rosencrans    
// Date: 10-20-17
// Purpose: These are the function prototypes for the date class

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <iomanip>

using namespace std;

class Date {

public:
   Date();
   Date( int m, int d, int y );
   void setMonth( int m );
   void setDay( int d );
   void setYear( int y );
   int getMonth( );
   int getDay( );
   int getYear ( );
   void print();
private:
   int month;
   int day;
   int year;
};

#endif