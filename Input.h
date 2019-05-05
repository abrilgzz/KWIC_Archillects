/*
Software Design and Architecture
KeyWord-In-Context (KWIC) system

This .h file reads the input file and creates a vector
of strings with these lines

Juan Luis Flores Garza
Abril Marina González Ramírez
Sergio Díaz Navarro
Miguel Bazán Aviña

May 2019

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
  vector<string> stopWords;
  vector<string> inputLines;

  // Constructor
  Input(string fileName, vector<string> stopWords) {
    this->fileName = fileName;
    this->stopWords = stopWords;
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
        line = removeStopWords(line);
        lines.push_back(line);
      }
    }
    else
      cout << "Error. File cannot be opened.";
    
    // Store processed lines as input lines
    this->inputLines = lines;
    return lines;
  }

  // Method that removes stop words from the line
  string removeStopWords(string line){
    vector<size_t> positions; // holds all the positions that sub occurs within str

    // Search through stopWords vector
    for(int i=0; i < this->stopWords.size(); i++){
      // If a stop word is found, delete it from line
      size_t pos = line.find(this->stopWords[i], 0);
  
      while(pos != string::npos)
      { 
        // DEBUGGING
        // cout << "Found a stop word: " << this->stopWords[i] << endl;
        line.erase(pos, this->stopWords[i].length());

        positions.push_back(pos);
        pos = line.find(this->stopWords[i], pos+1);
      }
    }
    return line;
  }

  // Method that deletes lines from the input lines
  void deleteInputLines(){
    vector <int> linesToDelete;
    int lineNumber = 0;

    // Get user input of lines to be deleted
    cout << "\nWhich line numbers do you want to delete from the Input? Indexing from 0 to n" << endl;
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
      this->inputLines.erase(this->inputLines.begin() + linesToDelete[i]);
    }

    // DEBUGGING
    // Printing inputLines
    // for(int i=0; i < this->inputLines.size(); i++){
    //   cout << this->inputLines[i] << endl;
    // }
    // cout << endl;
  } 

  // DEBUGGING
  // Printing stop words
  // void printStopWords(){
  //   cout << "\nStop words: " << endl;

  //   for(int i=0; i < this->stopWords.size(); i++){
  //     cout << this->stopWords[i] << " " << endl;
  //   }
  // }

};

#endif /* Input_h */

