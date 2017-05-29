//
// Created by bohdan on 5/28/17.
//
#include <fstream>
#include <iostream>
#include <sstream>
#include "configurationReader.h"
using namespace std;

vector<string> configurationReader(string filename) {
    vector<string> words;
    fstream fin(filename); //full path to the file
    if (!fin.is_open()) {
        cout << "error reading from file";
        return words;
    }

    string line;

    while (getline(fin, line)) {
        std::istringstream iss(line);
        string word;
        while (iss >> word) {
            words.push_back(word);
        }

    }
    return words;
}

string betweenQuotes(string s) {

    unsigned int firstQuotePos = (unsigned int) s.find_first_of("\"");
    unsigned int secondQuotePos = (unsigned int) s.find_first_of("\"", firstQuotePos + 1);
    return s.substr(firstQuotePos + 1, secondQuotePos - firstQuotePos - 1);
}