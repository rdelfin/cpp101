#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include "CLI/CLI11.hpp"

bool my_compare_descending(std::pair<std::string, int> p1, std::pair<std::string, int> p2) {
    if (p1.second != p2.second ) 
        return p1.second > p2.second ;
    return p1.first < p2.first;
}

bool my_compare_ascending(std::pair<std::string, int> p1, std::pair<std::string, int> p2) {
    if (p1.second != p2.second ) 
        return p1.second < p2.second ;
    return p1.first < p2.first;
}

int main(int argc, char* argv[]) {
    CLI::App app{"Word Counter"};
    std::string line;
    std::vector<std::string> user_input;
    std::vector<std::string> input_sequence;
    std::vector<std::string> output;
    std::vector<int> repetitions;
    bool reverse_sequence;
    int num;
    int elements;
    int punct_count_per_word;

    app.set_help_all_flag("--help-all", "Expand all help");
    app.add_flag("-r,--reverse", reverse_sequence,
                 "Add this flag in if you want the reverse order");
    app.add_option("-n,--num", num, "Number of elements");
    CLI11_PARSE(app, argc, argv);

    //std::cout << " I got: " << std::endl;
    //std::cout << reverse_sequence << std::endl;
    //std::cout << num << std::endl;

    while (std::getline(std::cin, line)) {
        user_input.push_back(line) ;
    }

    if(user_input.empty()){
        return 0;
    }

    for(int i=0; i< (int)user_input.size(); i++){
        std::string word;
        std::stringstream ss(user_input[i]);
        while (ss >> word){
            punct_count_per_word = 0;
            for(int i=0; i < word.length(); i++){
                if(ispunct(word[i])){
                    punct_count_per_word = punct_count_per_word + 1;
                }
            }
            if (punct_count_per_word != word.length()) {input_sequence.push_back(word);}
        }
    }

    // Converts everything to lower case and remove end punctuations only
    for(int i=0; i < (int) input_sequence.size(); i++){
        transform(input_sequence[i].begin(), input_sequence[i].end(), input_sequence[i].begin(), ::tolower);

        while(input_sequence[i].length() && ispunct(input_sequence[i].back())){
            input_sequence[i].pop_back();
        }

        while(input_sequence[i].length() && ispunct(input_sequence[i].front())){
            input_sequence[i] = input_sequence[i].substr(1, input_sequence[i].length());
        }
    }

    for (int i=0; i < (int)input_sequence.size(); i++){
        int count = 1;
        auto itr = std::find(output.begin(), output.end(), input_sequence[i]);
        if (itr != output.end()) {
        }
        else {
            for(int j=0; j < (int)input_sequence.size(); j++){
                if(j != i){
                    if(input_sequence[j].compare(input_sequence[i]) == 0){
                       count = count + 1;
                    }
                }        
            }
            output.push_back(input_sequence[i]);
            repetitions.push_back(count);
        } 
    }

    std::vector<std::pair<std::string, int>> sorted_pair;
    for(int i=0; i< (int)repetitions.size(); i++){
        sorted_pair.push_back(std::make_pair(output[i], repetitions[i]));
    }

    if(reverse_sequence == true){
        std::sort(sorted_pair.begin(), sorted_pair.end(), my_compare_ascending);
    }
    else {
        std::sort(sorted_pair.begin(), sorted_pair.end(), my_compare_descending);
    }

    if(num == 0){
        elements = (int)repetitions.size();
    }
    else{
        elements = num;
    }

    for(int i=0; i < elements; i++){
       std::cout << sorted_pair[i].first << " " << sorted_pair[i].second << std::endl;
    }

    return 0;
}
