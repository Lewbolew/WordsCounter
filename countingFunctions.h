//
// Created by bohdan on 5/27/17.
//
#include <string>
#include <vector>
#include <mutex>

#ifndef WORDSCOUNTER_COUNTINGFUNCTIONS_H
#define WORDSCOUNTER_COUNTINGFUNCTIONS_H

void wordsCount(std::vector<std::string> strings, std::map<std::string, int> &countedWords, std::mutex &m);
std::map<std::string, int> readFile(std::string fileName, int threadsNumber, int batchSize);

#endif //WORDSCOUNTER_COUNTINGFUNCTIONS_H

