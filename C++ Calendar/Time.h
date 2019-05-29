// CS 271
// Program Name: Time.h
// Author: Joshua Rosencrans    
// Date: 10-20-17
// Purpose: These are the function prototypes for the time class 

#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <iomanip>

using namespace std;

class Time {

public:
   Time();
   Time( int h, int m, int s );
   void setHour( int h );
   void setMinute( int m );
   void setSecond ( int s );
   int getHour( );
   int getMinute( );
   int getSecond ( );
   void print();
   void print12();
private:
   int hour;
   int minute;
   int second;
};

#endif