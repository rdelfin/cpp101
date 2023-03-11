#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>
#include <functional>
#include "CLI/CLI11.hpp"

using namespace std;

int ispunct_not_quote(char letter) {
    return ispunct(letter) && (letter != '\'');
}


string word_lower(string word) {
    transform(word.begin(), word.end(), word.begin(), [](unsigned char c) {
        return tolower(c);
    });
    return word;
}


int main(int argc, char** argv) {
    CLI::App app{"A wordcounter"};
    int outcount = -1;
    bool reverse = false;

    app.set_help_all_flag("--help-all", "Expand all help");
    app.add_flag("-r", reverse, "Add this flag if you want the output reversed");
    app.add_option("-n", outcount, "Add this flag to limit the output count");
    CLI11_PARSE(app, argc, argv);

    string line;
    string word;
    unordered_map<string, int> wordcount;

    while (getline(cin, line)) {
        // Remove punctuation
        // Make an output iterator to write the result back into the new string
        string line_no_punc;
        auto myoutput_it = back_inserter(line_no_punc);
        remove_copy_if(
            line.begin(), line.end(), myoutput_it, //Store output           
            (&ispunct_not_quote)  
        );

        // istringsgream is great at streaming words separated by whitespace
        istringstream ss(line_no_punc);
        while (ss >> word) {
            // Either insert or increment the word count
            word = word_lower(word);
            auto key_it = wordcount.find(word);
            if (key_it == wordcount.end()) wordcount.emplace(word, 1); 
            else key_it->second++;
        }
    }

    // Now, turn the unordered map into a vector to allow it to be sorted
    vector<pair<string, int>> elems(wordcount.begin(), wordcount.end());
    if (reverse) {
        sort(elems.begin(), elems.end(), [](auto &left, auto &right) {
            if (left.second == right.second) 
                // If the counts are the same, order by string values
                return left.first.compare(right.first) < 0;
            else
                return left.second < right.second;
        });

    } else {
        sort(elems.begin(), elems.end(), [](auto &left, auto &right) {
            if (left.second == right.second) 
                // If the counts are the same, order by string values
                return left.first.compare(right.first) < 0;
             else return left.second > right.second;
        });
    }
    int i = 0;
    for (auto& x: elems) {
        if ((i >= outcount) && (outcount > 0)) break;
        cout << x.first << " " << x.second << endl;
        i++;
    }
}


/*

vector<string> parse_line(string line){
    // Surely there's a better way of doing this than having to manually iterate
    // through?
    vector<string> myvec;
    string word;
    char letter;
    
    int pos = -1;
    int len = 0;
    
    // This code actually has a problem, as it doesn't get the last word.
    for (int i = 0; i < line.length(); i++) {
        letter = line[i];
        if (isalpha(letter) || (letter == '\'')) len++;
        // We've hit a non letter, parse into a word and update the start 
        // pointer pos.
        else {
            if (len > 0) {
                word = line.substr(pos+1, len);
                myvec.push_back(word);
                cout << word << endl;
            }
            len = 0;
            pos = i;
        }
    }
    return myvec;
}
*/