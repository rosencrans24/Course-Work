// CS 271
// Program Name: myprogram.cpp
// Author: Joshua Rosencrans    
// Date: 10-11-17 
// Purpose: This program has the implementation and testing of the functions highTwo and longestWord

#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

void highTwo ( double array[ ], int size ) {
   double first = array[0], second = first;
   for(int i = 0; i < size; i++){
      if(first < array[i]){
         second = first;
         first = array[i];
      }// end if   
      if(second < array[i] && first != second){
         second = second;
      } // end if 
        
   } // end for 
   cout << "The two highest elements are: " << first << " and " << second<<
        endl;
}   
int longestWord(char *cPtr ) {
   int length = 0, longestLength = 0;
   for (int index = 0; index <= strlen(cPtr); index++ ){
      
   }    
  return longestLength;
}

int main(){
   double array [10];
   int size=10;
   string str1;
   // only way i could find to convert a string to a char pointer
   char *cPtr = (char*)str1.c_str();

   

   for(int i = 0; i < size; i++){
      cout << "Please enter a double value for the array " << endl;
      cin >> array[i];
   }   
   for(int i = 0; i < size; i++){
      cout << array[i] << " ";
   }   
   cout << endl;
   highTwo(array,size);

   cout << "Please enter a string " << endl;
   // this makes sure that cin is not stuck on the new line
   cin.ignore();
   getline(cin,str1);
   cout << "The longest word has length: "<< longestWord(cPtr) << endl;
   
   
}
