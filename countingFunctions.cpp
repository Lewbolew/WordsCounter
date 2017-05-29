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
#include <sstream>

using namespace std;
void wordsCount(vector<string> strings, map<string, int> &countedWords, mutex &m) {
    lock_guard<mutex> lock(m);
    for(size_t i = 0; i<strings.size(); ++i) {
        countedWords[strings[i]] += 1;
    }
};

map<string, int> readFile(string fileName, int threadsNumber, int batchSize) {
    mutex mutex1;
    vector<string> vectorWords;
    ifstream file;
    file.open (fileName);
    map<string, int> countedWords;

    if (!file.is_open()){
        cerr << "Error opening file";
    }
    thread threads[threadsNumber];
    for(int i = 0; i < threadsNumber; i++) {
        vector<string> words;
        for(int j = 0; j<batchSize; j++) {
            string s;
            getline(file, s);
            stringstream ss(s);
            istream_iterator<string> begin(ss);
            istream_iterator<string> end;
            vector<string>v(begin, end);
            words.insert(words.end(), v.begin(), v.end());
        }
        for (int k=0;k < words.size();k++) {
            transform(words[k].begin(), words[k].end(), words[k].begin(), ::tolower);
            words[k].erase (remove_if (words[k].begin (), words[k].end (), ::ispunct), words[k].end ());
        }
        threads[i] = thread(wordsCount,words, ref(countedWords), ref(mutex1));
    }
    file.close();
    for(int l = 0; l < threadsNumber;l++) {
        threads[l].join();
    }
    return countedWords;
}

