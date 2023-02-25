#include <iostream>

int main() {

    int user_input;
    uint32_t count = 0;
    std::cout << "Type number: "; // Type a number and press enter
    std::cin >> user_input; // Get user input from the keyboard
    std::cout << "Your number is: " << user_input << std::endl; // Display the input val   


    if(user_input <=0){
        std::cout << "Please enter a non-zero positive integer!" << std::endl;
    }
    else{
        uint32_t number = user_input ;
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
    }
    std::cout << "Collatz's sequence has " << count << " elements" << std::endl;
    return 0;
}
