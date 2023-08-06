//Functions to handle user input and validation

#include <iostream>
#include <string>

const char EXITING = '0';
const char HW_RETURN = '1';
const char SW_RETURN = '2';
const char BLINKY = '3';
const char CUSTOM = '4';
const char SECRET = '5';
const char VALID_CHOICES[] = { EXITING, HW_RETURN, SW_RETURN, BLINKY, CUSTOM, SECRET };

void displayMenu() {
    std::cout <<
        R"(
1. Get Hardware Information (Hostname, SN, CPU Temperature/Operating Frequency)
2. Get Software Information (Hostname, OS Version, Kernel Version)
3. Make the LED go blinky!
4. Enter and Run a Custom Command
Please make your selection (0 to exit program):
)";
}

std::string getInput() {
    std::string input = "";
    std::getline(std::cin, input);
    return input;
}

char getChoice() {
    char choice;
    while (true) {
        std::cin >> choice;

        if (std::strchr(VALID_CHOICES, choice) != NULL) {
            return choice;
        }
        std::cout << "Invalid Entry. Please enter another value." << std::endl;
        std::cin.clear();
        displayMenu();
    }
}