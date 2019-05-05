/*
Software Design and Architecture
KeyWord-In-Context (KWIC) system

This .h file outputs the lines to console

Juan Luis Flores Garza 
Abril Marina González Ramírez
Sergio Díaz Navarro
Miguel Bazán Aviña

May 2019
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
  vector<string> outputLines;

  // Constructor
  Output(vector<string> &lines) {
    this->outputLines = lines;
  }

  void deleteOutputLines(){
    vector <int> linesToDelete;
    int lineNumber = 0;

    // Get user input of lines to be deleted
    cout << "\nWhich line numbers do you want to delete from the Output? Indexing from 0 to n" << endl;
    cout << "Type \"-1\" to finish line numbers." << endl; 

    while(cin >> lineNumber){
      if(lineNumber == -1)
        break;
      else {
        linesToDelete.push_back(lineNumber);
      }
    }

    // Delete lines from inputLines
    for(int i=0; i < linesToDelete.size(); i++){
      this->outputLines.erase(this->outputLines.begin() + linesToDelete[i]);
    }
  }

  // Prints remaining lines from outputLines
  void printResult(){
    cout << "\nFinal output: " << endl;
    for(int i=0; i < this->outputLines.size(); i++) {
      cout << this->outputLines[i] << endl;
    }
  }

};

#endif /* Output_h */