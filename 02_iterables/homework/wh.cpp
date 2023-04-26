#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <cctype>

std::string removePunctuation(std::string str) {
    const std::string punctuation = "*()[]{}/,:;'.\\#\"£$%^&*=";
    while (str.find_first_of(punctuation) == 0){
        str.erase(0,1);
    }

    while (str.find_last_of(punctuation) == str.length() - 1) {
        str.erase(str.find_last_of(punctuation));
    }
    return str;
}

int main(int argc, char* argv[]) {
    int n = -1;
    bool reverse_order = false;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-n") {
            if (i + 1 < argc) {
                n = std::stoi(argv[++i]);
            } else {
                std::cerr << "Error: -n requires an argument" << std::endl;
                return 1;
            }
        }

        if (arg == "-r") {
            reverse_order = true;
        }
    }


    std::string line;
    std::map<std::string, int> map_of_words;
    std::vector<std::pair<std::string, int>> vector_of_words;

    while (std::getline(std::cin, line)) {
        std::stringstream iss(line);
        std::string word;

        while (iss >> word) {
            word = removePunctuation(word);

            for (auto &c : word) {
                c = static_cast<char>(std::tolower(c));
            }

            if (map_of_words.find(word) == map_of_words.end()) {
                map_of_words.insert_or_assign(word, 1);
            } else {
                int count = map_of_words.at(word) + 1;
                map_of_words.insert_or_assign(word, count);
            }
        }
        
    }

    for(std::map<std::string, int>::const_iterator it = map_of_words.begin(); it != map_of_words.end(); ++it) {
        vector_of_words.push_back(std::make_pair(it->first, it->second));
    }

    if (reverse_order) {
        std::sort(vector_of_words.begin(), vector_of_words.end(), [](std::pair<std::string, int> pair1, std::pair<std::string, int> pair2)
        { return ((pair1.second == pair2.second) && (pair1.first >= pair2.first)) || pair1.second < pair2.second; }
        );

    } else {
        std::sort(vector_of_words.begin(), vector_of_words.end(), [](std::pair<std::string, int> pair1, std::pair<std::string, int> pair2)
        { return ((pair1.second == pair2.second) && (pair1.first <= pair2.first)) || pair1.second > pair2.second; }
        );
    }

    int i = 0;
    for (auto & element : vector_of_words) {
        std::cout << element.first << " " << element.second << std::endl;
        i++;
        if (i == n) {
            break;
        }
    }
}
