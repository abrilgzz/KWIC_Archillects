/*
Software Design and Architecture
KeyWord-In-Context (KWIC) system

This .h file outputs the lines to console

Juan Luis Flores Garza 
Abril Marina González Ramírez
Sergio Díaz Navarro
Miguel Bazán Aviña

March 2019
*/

#ifndef Output_h
#define Output_h

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>

using namespace std;

class Output {
public:

  // Constructor
  Output(vector<string> &lines) {
    cout << "Final output: " << endl;
    for(int i=0; i < lines.size(); i++) {
      cout << lines[i] << endl;
    }
  }

};

#endif /* Output_h */