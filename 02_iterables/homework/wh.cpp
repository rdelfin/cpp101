#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

int main(int argc, char* argv[]) {
    std::string line;
    std::vector<std::string> input_sequence;
    std::vector<std::string> output;
    std::vector<int> repetitions;


    while (std::getline(std::cin, line)) {
        input_sequence.push_back(line) ;
    }

    //std::cout << std::endl;
    //std::cout << "The input is as follows: " << std::endl;
    //for (int i=0; i < (int)input_sequence.size(); i++){
    //    std::cout << input_sequence[i] << std::endl;
    //}

    //std::cout << "total elements are " << (int)input_sequence.size() << std::endl;
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
           // std::cout << "Found " << input_sequence[i] << "in output already" << std::endl;
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

    std::cout << std::endl;

    for(int i=0; i < (int)output.size(); i++){
        std::cout << output[i] << " " << repetitions[i] << std::endl;
    }
    //std::cout << "You've passed " << argc << " arguments" << std::endl;
    //std::cout << "The arguments are:" << std::endl;
    //for (int i = 0; i < argc; i++) {
    //    std::cout << argv[i] << std::endl;
    //}
    return 0;
}
