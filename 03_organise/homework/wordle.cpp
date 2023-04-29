#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "CLI/CLI11.hpp"

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

bool check_valid_answer_word(std::vector<std::string> valid_words, std::string correct_word){
    bool is_valid = false;

    for(int i=0; i < (int)valid_words.size(); i++){
        if(correct_word == valid_words[i]){
            is_valid = true;
            return is_valid;
        }
    }
    return is_valid;
}

bool check_legit_user_input(std::string word){
    bool is_legit_input = false;

    if(word.length() == 5){
        is_legit_input = true;
        return is_legit_input;
    }
    return is_legit_input;
}

std::string get_user_input(void){
    std::string user_word;
    std::cin >> user_word;
    return user_word;
}

void give_feedback_output(std::string input_word, std::string answer_word){
    int index;
    for(int i=0; i< (int)input_word.size(); i++){
        index = answer_word.find(input_word[i]);
        //std::cout << index << std::endl;
        if(index == i){
            std::cout << input_word[i] << " " << "V" << std::endl;
        }
        else if (index != i && index < input_word.length()){
            std::cout << input_word[i] << " " << "~" << std::endl;
        }
        else {
            std::cout << input_word[i] << " " << "X" << std::endl;
        }
    }
}

int main(int argc, char* argv[]) {

    std::string answer;
    bool feedback;
    std::string user_input;
    const int total_attempts = 6;

    CLI::App app{"Wordle"};
    app.set_help_all_flag("--help-all", "Expand all help");
    app.add_option("--answer, -a", answer,
                 "Add this flag to feed in the correct word");
    app.add_flag("-f,--feedback", feedback,
                 "Add this flag in if you want feedback");
    CLI11_PARSE(app, argc, argv);

    std::vector<std::string> valid_words = get_valid_wordle_words();

    if(!check_valid_answer_word(valid_words, answer)){
        std::cout << "Answer word not valid, please check again." << std::endl;
        return 3;
    }


    for(int i=0; i < total_attempts; i++){
        user_input = get_user_input();
        if(!check_legit_user_input(user_input)){
            std::cout << "User input not valid, please try again." << std::endl;
            return 2;
        }

        if(user_input == answer){
            std::cout << "CORRECT" << std::endl;
            return 0;
        }

        if(feedback == false){
            std::cout << "WRONG" << std::endl;
        }
        else if (feedback == true){
            give_feedback_output(user_input, answer);
        }
    }

    std::cout << "Attempts exceeded" << std::endl;
    


    return 1;
}
