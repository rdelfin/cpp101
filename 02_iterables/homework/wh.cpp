#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

bool compare(std::pair<std::string, int> p1, std::pair<std::string, int> p2) {
    if (p1.second != p2.second ) 
        return p1.second > p2.second ;
    return p1.first < p2.first;
}

int main(int argc, char* argv[]) {
    std::string line;
    std::vector<std::string> input_sequence;
    std::vector<std::string> output;
    std::vector<int> repetitions;


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

    for(int i=0; i < (int)repetitions.size(); i++){
        std::cout << sorted_pair[i].first << " " << sorted_pair[i].second << std::endl;
    }

    //std::sort(repetitions.begin(), repetitions.end());

    //std::cout << "You've passed " << argc << " arguments" << std::endl;
    //std::cout << "The arguments are:" << std::endl;
    //for (int i = 0; i < argc; i++) {
    //    std::cout << argv[i] << std::endl;
    //}
    return 0;
}
