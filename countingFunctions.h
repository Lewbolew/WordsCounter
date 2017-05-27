//
// Created by bohdan on 5/27/17.
//
#include "countingFunctions.cpp"
#ifndef WORDSCOUNTER_COUNTINGFUNCTIONS_H
#define WORDSCOUNTER_COUNTINGFUNCTIONS_H

void wordsCount(vector<string> strings, map<string, int> &countedWords, mutex &m);
map<string, int> readFile(string fileName, int threadsNumber, int batchSize);

#endif //WORDSCOUNTER_COUNTINGFUNCTIONS_H

