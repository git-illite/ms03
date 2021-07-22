//==============================================
// Name:           Abdalla Aden
// Student Number: 021720057
// Email:          aaaden1@myseneca.ca
// Section:        NDD
// Date:           Jul 10 2021
//==============================================
// Project MS1 
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
   bool debug = false;
   
   // made global in utils.h
   int getTime() {  
      int mins = -1;
      if (debug) {
         Time t(0);
         cout << "Enter current time: ";
         do {
            cin.clear();
            cin >> t;   // needs extraction operator overloaded for Time
            if (!cin) {
               cout << "Invalid time, try agian (HH:MM): ";
               cin.clear();
            }
            else {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }
   int getInt(const char* prompt)
   {
       int num=0;
       bool valid=false;
       if (prompt != nullptr) { cout << prompt; }
       
       do{
          
           cin >> num;
           if (cin.fail()) {
               cin.clear();
               cin.ignore(1000, '\n');
               cout << "Bad integer value, try again: ";

           }
           else if (cin.get() != '\n') {
               cin.clear();
               cin.ignore(1000, '\n');
               cout << "Enter only an integer, try again: ";
           }
           else valid = true;
       } while (!valid);

       return num;
   }
   int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
   {
       int num=0;
       bool valid = false;
       if (prompt != nullptr) { cout << prompt; }
       
       do {
           num=getInt();
          if (num <min || num>max) {
               //if (showRangeAtError) cout << "Invalid option [" << min << " <= value <= " << max << "]: ";
               if (showRangeAtError) cout << errorMessage << "[" << min << " <= value <= " << max << "]: ";
               else cout << errorMessage;
          }
           else valid = true;

       } while (!valid);

       return num;
   }
   char* getcstr(const char* prompt, std::istream& istr, char delimiter)
   {
       if (prompt != nullptr) { cout << prompt; }
       string str;
       getline(cin, str, delimiter);
       char* s = new char[str.length() + 1];
       strcpy(s,str.c_str());
       
       return s;
   }
}