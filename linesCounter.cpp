//
// Created by bohdan on 5/26/17.
//
#include <string>
#include <fstream>
#include <cmath>
#include "linesCounter.h"
using namespace std;

long int linesCounter(string fileName) {
    ifstream file;
    file.open(fileName);
    string word;
    long int linesNumber = 0;
    while(getline(file, word)) {
        ++linesNumber;
    }
    return linesNumber;
}

