/*
Software Design and Architecture
KeyWord-In-Context (KWIC) system

The KWIC index system accepts an ordered set of lines; 
each line is an ordered set of words, and each word is an ordered set of characters. 
Any line may be “circularly shifted” by repeatedly removing the first word and appending 
it at the end of the line. 

The KWIC index system outputs a list of all circular shifts of all lines in 
alphabetical order.

This main.cpp file calls the necesary instances of classes and the functions needed to perform
the reading of the input file, make circular shift combinations, 
order these alphabetically and output them to console.

Version 2: Allows the user to enter a list of stop words (words to be deleted from lines),
 select which type of sorting (asc or desc), and delete lines from input lines or output lines

Juan Luis Flores Garza 
Abril Marina González Ramírez
Sergio Díaz Navarro
Miguel Bazán Aviña

May 2019
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include "Input.h"
#include "CircularShift.h"
#include "Alphabetizer.h"
#include "Output.h"

using namespace std;

int main(int argc, const char * argv[]) {
  string inputFileName;
  cout << "\nEnter file name:" << endl;
  cin >> inputFileName;

  // Reads stop words from user input
  vector<string> stopWords;
  string word = "";

  cout << "\nEnter stop words." << endl;
  cout << "Type \"end\" to finish stop words." << endl; 

  while(cin >> word){
    if(word == "end")
      break;
    else {
      stopWords.push_back(word);
    }
  }

  // Open file and read its content
  Input newInput(inputFileName, stopWords);
  vector <string> lines;
  lines = newInput.getLines();
  newInput.deleteInputLines();

  // Create an instance of the class that will create the shifted lines
  CircularShift newCircularShift(newInput.inputLines);

  // Alphabetize the new, shifted lines
  Alphabetizer newAlphabetizer(newCircularShift.shiftedLines);

  // Output the final result to console
  Output newOutput(newCircularShift.shiftedLines);
  newOutput.deleteOutputLines();
  newOutput.printResult();

  cout << "\nGoodbye!" << endl;

  return 0;
}
