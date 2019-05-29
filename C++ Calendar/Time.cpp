// CS 271
// Program Name: Time.cpp
// Author: Joshua Rosencrans    
// Date: 10-20-17
// Purpose: These are all the functions going to be used in the time
//          class

#include <iostream>
#include <iomanip>
#include "Time.h"
// used for hours in a day
#define SIZE 23
// used for both second and minutes
#define SIZE2 59
// used as max hour limit for printing in 12 hour format
#define HOUR_LIMIT 12

using namespace std;

//  default constructor
Time::Time(){
   hour=0;
   minute=0;
   second=0;
}
// Constuctor where values can be inputed
Time::Time( int h, int m, int s ){
   setHour(h);
   setMinute(m);
   setSecond(s);
   }
// mutator for hour
void Time::setHour( int h ){
   if(h>SIZE)
      hour = hour;
   else
      hour = h; 
}
// mutator for minute
void Time::setMinute( int m ){
   if(m>SIZE2)
      minute = minute;
   else
      minute = m; 
}
// mutator for second
void Time::setSecond ( int s ){
   if(s>SIZE2)
      second = second;
   else
      second = s; 
}
// acessor for hour
int Time::getHour( ){
   return hour;
}
// accessor for minute 
int Time::getMinute( ){
   return minute;
}
// accessor for second
int Time::getSecond ( ){
   return second;
}
// print function that prints the time in 24 hour format
void Time::print(){
   cout << setfill('0') << setw(2) << getHour() << ":" << setw(2) << getMinute() << ":" << setw(2) << getSecond();
   cout << setfill (' ');
}
//  print function that prints the time in 12 hour format
void Time::print12(){
   cout << setfill('0') << ((getHour() == 0 || getHour() == HOUR_LIMIT) ? HOUR_LIMIT: getHour() % HOUR_LIMIT)
        << ":" << setw(2) << getMinute() << ":" << setw(2) << getSecond() << " " <<
        (getHour() < HOUR_LIMIT ? "AM" : "PM");
   cout << setfill(' '); 
}