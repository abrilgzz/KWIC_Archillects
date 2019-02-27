/*
Software Design and Architecture
KeyWord-In-Context (KWIC) system

The KWIC index system accepts an ordered set of lines; 
each line is an ordered set of words, and each word is an ordered set of characters. 
Any line may be “circularly shifted” by repeatedly removing the first word and appending 
it at the end of the line. 

The KWIC index system outputs a list of all circular shifts of all lines in 
alphabetical order.

This .cpp file reads from console input the user's file to be readed, and instantiates
a an object KWIC which performs the needed operations. 

Abril Marina González Ramírez
Juan Luis Flores Garza 
Sergio Díaz Navarro
Miguel Bazán Aviña

February 2019
*/

#include <iostream>
#include <string>
#include <fstream>
#include "KWIC.h"

using namespace std;

//.i
int main(int argc, const char * argv[]) {
    string inputFile;
    getline(cin, inputFile);
    KWIC newKWIC(inputFile);

    newKWIC.openFile();
    newKWIC.print();
}