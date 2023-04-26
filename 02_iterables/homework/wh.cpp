#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

int main() {
    std::string line;
    std::map<std::string, int> map_of_words;
    std::vector<std::pair<std::string, int>> vector_of_words;

    while (std::getline(std::cin, line)) {
        

        std::stringstream iss(line);

        std::string word;

        while (iss >> word) {
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
        
    std::sort(vector_of_words.begin(), vector_of_words.end(), [](std::pair<std::string, int> pair1, std::pair<std::string, int> pair2)
    { return ((pair1.second == pair2.second) && (pair1.first <= pair2.first)) || pair1.second > pair2.second; }
    );

    for (auto & element : vector_of_words) {
        std::cout << element.first << " " << element.second << std::endl;
    }
}
