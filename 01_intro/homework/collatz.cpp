#include <iostream>
#include <string>


int main() {

    int user_input;
    std::cout << "Type a number: "; // Type a number and press enter
    std::cin >> user_input; // Get user input from the keyboard
    std::cout << "Your number is: " << user_input << std::endl; // Display the input val   

    if(user_input <=0){
        std::cout << "Please enter a non-zero positive number!" << std::endl;
    }
    else{
        int number = user_input ;
        while(number !=1){
            if(number%2 == 0){
                number = number / 2;
                std::cout << number << std::endl;
            }
            else{
                number = number*3 + 1;
                std::cout << number << std::endl;
            }
        }
    }
    return 0;
}
