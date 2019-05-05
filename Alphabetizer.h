/*
Software Design and Architecture
KeyWord-In-Context (KWIC) system

This .h file sorts the lines alphabetically

Juan Luis Flores Garza 
Abril Marina González Ramírez
Sergio Díaz Navarro
Miguel Bazán Aviña

May 2019
*/

#ifndef Alphabetizer_h
#define Alphabetizer_h

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <cctype>
#include <fstream>
#include <algorithm>
#include <cctype>

using namespace std;

class Alphabetizer {
public:

  // Constructor
  Alphabetizer(vector<string> &lines) {
    int sortType = 0;

    // Asks the user what kind of sort he wants asc = 0, desc = 1
    cout << "\nPlease select which type of sort." << endl;
    cout << "Sort ascending = 0, sort descending = 1" << endl;
    cin >> sortType;

    // Sorts lines according to input
    if (sortType == 0)
      sort(lines.begin(), lines.end());
    else
      sort(lines.rbegin(), lines.rend());
  }

};

#endif /* Alphabetizer_h */