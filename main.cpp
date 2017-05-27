#include <iostream>
#include <map>
#include <thread>
#include <string>
#include <sstream>
#include "linesCounter.h"
#include "countingFunctions.h"

int main() {
    int threadsNumber = 4; // argument
    string fileName = "example.txt"; // argument
    long int linesNumber = linesCounter("example.txt");
    int batches_number = int(ceil((double)linesNumber / (double)threadsNumber));
    long int currentLine = 0;
    map<string, int> result = readFile("example.txt", threadsNumber, batches_number);
//    for (const auto &p : result) {
//        std::cout <<p.first << ": " << p.second << '\n';
//    }
    cout<<result.size();

//------------------------ OLD WERSION WITHOUT THREADS-----------------------
//    for(int j = 0; j < 10) {
//        long int currentLine = 0;
//    }
//    vector<string> a = readFile("example.txt",0, 3);
//    map<string, int> b = wordCount(a);
//    for (const auto &p : b) {
//        std::cout <<p.first << ": " << p.second << '\n';
//    }
//----------------------------------------------------------------------------
}

