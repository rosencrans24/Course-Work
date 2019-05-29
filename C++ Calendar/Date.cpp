// CS 271
// Program Name: Date.cpp
// Author: Joshua Rosencrans    
// Date: 10-20-17
// Purpose: All of the functions being used in the date class

#include <iostream>
#include <iomanip>
#include "Date.h"
// used for the size of months in a year
#define SIZE 12
// used for amount of days in a month
#define SIZE2 31
// max year alowed
#define SIZE3 2100
// constant used for default year
#define DEFAULT 1980

using namespace std;  

// default constructor
Date::Date(){
   month = 1;
   day = 1;
   year = DEFAULT;
}
// constructor with ability to input values
Date::Date( int m, int d, int y ){
   setMonth(m);
   setDay(d);
   setYear(y);
}
// mutator for month
void Date::setMonth( int m ){
   if(m == 0 || m > SIZE)
      month = month;
   else
      month = m;
}
// mutator for day
void Date::setDay( int d ){
   if(d == 0 || d > SIZE2)
      day = day;
   else
      day = d;
} 
// mutatuor for year
void Date::setYear( int y ){
   if (y <= DEFAULT || y > SIZE3 )
      year = year;
   else
      year = y;
}
// acessor for month
int Date::getMonth( ){
   return month;
}
// accessor for day
int Date::getDay( ){
   return day;
}
// accessor for year
int Date::getYear ( ){
   return year;
}
// display function print 
void Date::print(){
   cout << setfill('0') << setw(2) << getMonth() << "/" << setw(2) << getDay() << "/" << setw(4) << getYear();
   cout << setfill(' ');
}