//
// Created by bohdan on 5/29/17.
//
#include <string>
#include <map>
#ifndef WORDSCOUNTER_OUTPUTFUNC_H
#define WORDSCOUNTER_OUTPUTFUNC_H

void writeByAlphabet(std::map<std::string,int> m, std::string filepath);
void writeByNumber(std::map<std::string, int> m, std::string filepath);
std::vector<std::vector<std::string>> mapToVector(std::map<std::string, int> m1);
bool compareFunc(const std::vector<std::string>& v1, const std::vector<std::string>& v2);



#endif //WORDSCOUNTER_OUTPUTFUNC_H
