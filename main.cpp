#include <iostream>
#include <map>
#include <thread>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <deque>
#include "linesCounter.h"
#include "countingFunctions.h"
#include "configurationReader.h"
#include "outPutFunc.h"
using namespace std;

int main(int argc, char *argv[]) {
    vector<string> arguments = configurationReader(argv[1]);
    string nameInputFile = betweenQuotes(arguments[0]);
    string nameOutputFileAlphabet = betweenQuotes(arguments[1]);
    string nameOupputFileNumber = betweenQuotes(arguments[2]);
    int threadsNumber = intParser(arguments[3]);
    cout << threadsNumber;
    long int linesNumber = linesCounter(nameInputFile);
    int batches_number = int(ceil((double)linesNumber / (double)threadsNumber));
    map<string, int> result = readFile(nameInputFile, threadsNumber, batches_number);
    writeByAlphabet(result, nameOutputFileAlphabet);
    writeByNumber(result, nameOupputFileNumber);


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

