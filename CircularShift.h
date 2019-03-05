/*
Software Design and Architecture
KeyWord-In-Context (KWIC) system

This .h file performs the circular shift combinations of the input sentence,
and stores the combinations made.

Juan Luis Flores Garza
Abril Marina González Ramírez
Sergio Díaz Navarro
Miguel Bazán Aviña

March 2019

*/
#ifndef CircularShift_h
#define CircularShift_h

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <cctype>
#include <fstream>

using namespace std;

class CircularShift {
public:
  vector <string> shiftedLines;

  // Constructor
  CircularShift(vector<string> lines) {
    for(int i=0; i < lines.size(); i++) {
      shiftSentence(lines[i]);
    }
  }

  // Function that converts a string to a vector
  vector<string> stringToVector(string sentence) {
    stringstream ss(sentence);
    vector<string> wordVector;
    string word;

    while(!ss.eof()){
      ss >> word;
      // Transform to lower case all chars
      for(int i=0; i < word.length(); i++) {
          word[i] = tolower(word[i]);
      }
      //cout << word << endl;
      wordVector.push_back(word);
    }
    return wordVector;
  }

  // Function that converts a vector to a string
  string vectorToString(vector<string> wordVector) {
    string outputString = "";

    for(int i=0; i < wordVector.size(); i++) {
      outputString += wordVector[i] + " ";
    }
    // Erase last whitespace in string
    outputString = outputString.substr(0, outputString.size()-1);
    return outputString;
  }

  // Rotates words in a sentence
  void shiftSentence(string sentence) {
    // Converts string to a vector
    vector<string> result = stringToVector(sentence);

    // Rotates the words in the vector
    for(int i=result.size(); i > 0; i--) {
      //cout << vectorToString(result) << endl;
      // Stores the created lines in the instance of the object
      this->shiftedLines.push_back(vectorToString(result));
      rotate(result.begin(), result.begin()+1, result.end());
    }
  }
};

#endif /* CircularShift_h */
