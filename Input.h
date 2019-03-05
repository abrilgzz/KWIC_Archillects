/*
Software Design and Architecture
KeyWord-In-Context (KWIC) system

This .h file reads the input file and creates a vector
of strings with these lines

Juan Luis Flores Garza
Abril Marina González Ramírez
Sergio Díaz Navarro
Miguel Bazán Aviña

March 2019

*/
#ifndef Input_h
#define Input_h

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

class Input {
public:
  string fileName;

  // Constructor
  Input(string fileName) {
    this->fileName = fileName;
  }
  // Method that reads each line of the input file
  vector <string> getLines() {
    ifstream file (this->fileName);
    vector <string> lines;
    if (file.is_open()) {
      while(!file.eof()) {
        string line;
        getline(file, line);
        // Remove beginning and end quotes and period
        if(line.front() == '"') {
            line.erase(0,1);
            line.erase(line.length()-2);
        }
        lines.push_back(line);
      }
    }
    else
      cout << "Error. File cannot be opened.";
    return lines;
  }
};

#endif /* Input_h */

