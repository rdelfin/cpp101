#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// These are all the words you can accept as "valid" when you press enter
std::vector<std::string> get_valid_wordle_words() {
    std::ifstream f("03_organise/homework/data/valid-wordle-words.txt");
    std::vector<std::string> words;
    std::string line;

    while (std::getline(f, line)) {
        words.push_back(line);
    }

    return words;
}

bool word_exists(const std::string &input, const std::vector<std::string> &vec) {
    return std::find(vec.begin(), vec.end(), input) != vec.end();
}

int main(int argc, char* argv[]) {
    std::string answer;
    bool answer_given = false;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "--answer") {
            answer_given = true;
            answer = argv[++i];
        }
    }

    if (!answer_given) {
        return 4;
    }

    std::vector<std::string> valid_words = get_valid_wordle_words();

    for (int i = 1; i <= 6; ++i) {
        std::string attempt;
        std::getline(std::cin, attempt);

        if (attempt.length() != 5) {
            return 2;
        }

        if (!word_exists(attempt, valid_words)) {
            return 3;
        }


        if (attempt == answer) {
            std::cout << "CORRECT" << std::endl;
            return 0;
        } else {
            std::cout << "WRONG" << std::endl;
        }
    }

    return 1;
}
