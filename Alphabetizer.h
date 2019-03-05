/*
Software Design and Architecture
KeyWord-In-Context (KWIC) system

This .h file sorts the lines alphabetically

Juan Luis Flores Garza 
Abril Marina González Ramírez
Sergio Díaz Navarro
Miguel Bazán Aviña

March 2019
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
    // Sorts lines alphabetically
    sort(lines.begin(), lines.end());
  }

};

#endif /* Alphabetizer_h */