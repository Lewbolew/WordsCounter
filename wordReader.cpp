#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<thread>
#include <set>
#include <algorithm>
#include <iterator>
#include <mutex>
#include <string>
#include <algorithm>
#include <string>

using namespace std;

vector<string> readFile(string fileName, long int desiredLine, long int endLine) {
    vector<string> vectorWords;
    ifstream file;
    file.open (fileName);

    if (!file.is_open()){
        cerr << "Error opening file";
    }


    string word;
    for(int i =0;i < desiredLine;i++ ) {
        getline(file, word);
    }
    while (file >> word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        word.erase (std::remove_if (word.begin (), word.end (), ::ispunct), word.end ());
        vectorWords.push_back(word);
    }

    file.close();
    return vectorWords;
}