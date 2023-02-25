#include <iostream>

int main() {

    int num_of_elements;
    int input;
    uint32_t count;
    std::cout << "Enter elements number of elements you wish to enter: "; // Type a number and press enter
    std::cin >> num_of_elements; // Get user input from the keyboard

    if (num_of_elements <=0){
        std::cout << "Please enter positive number of elements" << std::endl;
    }
    for(int i=0; i<num_of_elements; i++){
        std::cin >> input;
        if(input <=0){
            std::cout << "Please enter a non-zero positive integer!" << std::endl;
        }
        else{
            uint32_t number = input;
            count = 0;
            while(number !=1){
                if(number%2 == 0){
                    number = number / 2;
                    count = count + 1;
                }
                else{
                    number = number*3 + 1;
                    count = count + 1;
                }
            }
            std::cout << input << "'s Collatz'z sequence has " << count << " elements" << std::endl;
        }
    }
    return 0;
}
