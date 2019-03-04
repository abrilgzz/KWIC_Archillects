/*
Software Design and Architecture
KeyWord-In-Context (KWIC) system

The KWIC index system accepts an ordered set of lines; 
each line is an ordered set of words, and each word is an ordered set of characters. 
Any line may be “circularly shifted” by repeatedly removing the first word and appending 
it at the end of the line. 

The KWIC index system outputs a list of all circular shifts of all lines in 
alphabetical order.

This .h file contains the structure of the KWIC class. 

Abril Marina González Ramírez
Juan Luis Flores Garza 
Sergio Díaz Navarro
Miguel Bazán Aviña

February 2019
*/

#ifndef KWIC_h
#define KWIC_h

#include <iostream>
#include <string>
#include <cctype>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <fstream>

using namespace std;

class KWIC{
    public:
    string inputFile;
    vector<vector<string>> inputLines;
    vector<string> outputLines;

    //Constructor
    KWIC(string inputFile){
        this->inputFile = inputFile;
    }

    private:
    // Get lines from file
    void readLines(){
        ifstream ifs(this->inputFile);
        string linea;
        vector<string> palabras;

        if(ifs.is_open()){
            getline(ifs, linea);
            stringstream ss(linea);
            string palabra;
            while(ss >> palabra){
                palabras.push_back(palabra);
                if(ss.peek() == ' ')
                    ss.ignore();
            }
        }
        else{
            cout << "Error al abrir el archivo." << endl;
        }
    }

    //Circular shift
    void circularShift(){

    }

    // Sort alphabetically
    void sortAlphabetically(){

    }

    // Print
    void printLines(){

    }

}