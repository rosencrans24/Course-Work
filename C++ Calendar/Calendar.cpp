// CS 271
// Program Name: Calendar.cpp
// Author: Joshua Rosencrans    
// Date: 10-20-17
// Purpose: Driver program testing both the date and time classes together 

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "Date.h"
#include "Time.h"
#define ARRAY_SIZE 5

using namespace std;

int main (){
   //variable declaration
   const int MAX = 24;
   const int MAX2 = 60;
   const int MAX_MONTH = 12;
   const int MAX_DAY = 31;
   const int MAX_YEAR = 2100;
   const int RANGE = 121;
   // num must be a regular int becaue it is constantly changing with random numbers generated
   int num;
   srand(time(NULL));
   // Testing default time constructor
   Time t[ARRAY_SIZE];
   // testing other time constructor
   Time x(14,22,48);
  // testing default date constructor
   Date d[ARRAY_SIZE];
   //Testing other date constructor
   Date p(11,10,1992);
   
   // filling a time object array with random values and testing mutators 
   for(int i = 0; i < ARRAY_SIZE; i++){
      num = rand() % MAX + 1;
      t[i].setHour(num);
      num = rand() % MAX2 + 1;
      t[i].setMinute(num);
      num = rand() % MAX2 + 1;
      t[i].setSecond(num);
   }
   // printing the time array in 24 hour format which uses acessors
   cout << endl;
   cout << "Time array being printed in 24 hour format" << endl;
   for(int i = 0; i < ARRAY_SIZE; i++){
      t[i].print();
      cout <<endl;
   }
   // printing the time array in 12 hour format which uses acessors
   cout << endl;
   cout << "Time array being printed in 12 hour format" << endl;
   for(int i = 0; i < ARRAY_SIZE; i++){
      t[i].print12();
      cout <<endl;
   }
   // filling the date array with random values and testing mutators
   for(int i = 0; i < ARRAY_SIZE; i++){
      num = rand() % MAX_MONTH + 1;
      d[i].setMonth(num);
      num = rand() % MAX_DAY + 1;
      d[i].setDay(num);
      num = rand() % RANGE + 1980;
      d[i].setYear(num);
   }   
   // testing the print function in date which uses the accessors
   cout << endl;
   cout << "Date array being printed using print function" << endl;
   for(int i = 0; i < ARRAY_SIZE; i++){
      d[i].print();
      cout <<endl;
   } 
   
     // testing other consturctor for time 
     cout << endl << "Testing the other constructor for Time" << endl;
     x.print();
     cout << endl;
     x.print12();
  
     // testing other costructor for date
     cout << endl << "Testing the other constructor for Date" << endl;
     p.print();
     cout << endl << endl;
}