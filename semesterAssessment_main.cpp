//Christine Deidrich 
//Semester Assessment Pt 2

/*
Write a C++ program that allows a user to enter a character string or press Enter to exit.
The program must display each letter, the ASCII value in hex, display the total of all the ASCII values 
and display the result.A function must be used to get the string from the user and to calculate the sum of the ASCII values.
*/

#include <iostream>
#include <string>

//Function Prototypes
std::string getUserInput();

int asciiCalc(std::string input);

int main() {
	std::cout << "Welcome to the ASCII Adder!" << std::endl;
	do {
		std::string input = getUserInput();
		int total = asciiCalc(input);
		std::cout << "The total of the ASCII Values is: " << total << std::endl;
	} while (true);
	return 0;
}

std::string getUserInput() {
	std::string input = "";
	std::cout << "Input a string to calculate (Press Enter to Exit)" << std::endl;
	while (std::getline(std::cin, input)) {
		if (input.empty()) {
			std::cout << "Exiting..." << std::endl;
			exit(EXIT_SUCCESS);
		}
		return input;
	}
}

int asciiCalc(std::string input) {
	int total = 0;
	int hex = 0;
	for (int i = 0; i < input.length(); i++) {
		hex = input[i];
		std::cout << input[i] << " " << std::hex << hex << std::endl;
		total += input[i];
	}
	return total;
}