#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include "CLI/CLI11.hpp"

bool compare(std::pair<std::string, int> p1, std::pair<std::string, int> p2) {
    if (p1.second != p2.second ) 
        return p1.second > p2.second ;
    return p1.first < p2.first;
}

int main(int argc, char* argv[]) {
    CLI::App app{"Word Counter"};
    std::string line;
    std::vector<std::string> input_sequence;
    std::vector<std::string> output;
    std::vector<int> repetitions;
    bool reverse_sequence;
    int num;
    int elements;


    app.set_help_all_flag("--help-all", "Expand all help");
    app.add_flag("-r,--reverse", reverse_sequence,
                 "Add this flag in if you want the reverse order");
    app.add_option("-n,--num", num, "Number of elements");
    CLI11_PARSE(app, argc, argv);

    while (std::getline(std::cin, line)) {
        input_sequence.push_back(line) ;
    }

    std::cout << std::endl;

    // Converts everything to lower case and remove end punctuations only
    for(int i=0; i < (int) input_sequence.size(); i++){
        transform(input_sequence[i].begin(), input_sequence[i].end(), input_sequence[i].begin(), ::tolower);
        if (ispunct(input_sequence[i].back())){
            input_sequence[i] = input_sequence[i].substr(0, input_sequence[i].length() - 1);
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
                    //std::cout << "i and j are " << i << " " <<  j << std::endl;
                    if(input_sequence[j].compare(input_sequence[i]) == 0){
                       count = count + 1;
                    }
                }        
            }
            output.push_back(input_sequence[i]);
            repetitions.push_back(count);
        } 
    }

    //std::cout << "Start sorting..." << std::endl;
    std::vector<std::pair<std::string, int>> sorted_pair;
    for(int i=0; i< (int)repetitions.size(); i++){
        sorted_pair.push_back(std::make_pair(output[i], repetitions[i]));
    }

    std::sort(sorted_pair.begin(), sorted_pair.end(), compare);

    if(num == 0){
        elements = (int)repetitions.size();
    }
    else{
        elements = num;
    }

    int x;
    if(reverse_sequence == true){
        x = repetitions.size() - 1;
    }
    else{
        x = 0;
    }

    for(int i=0; i < elements; i++){
        std::cout << sorted_pair[std::abs(x-i)].first << " " << sorted_pair[std::abs(x-i)].second << std::endl;
    }

    return 0;
}
