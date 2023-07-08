//Name: Christine Deidrich 
//Lab 9 - Function Sampler

#include <iostream>
#include <string>

#include "stub.h"
#include "message.h"
#include "numeric.h"
#include "reference.h"


int main() {
	//stub.cpp functions
	std::cout << "Calling messageStub from stub.cpp. This should print a cout message\n";
	messageStub();

	//message.cpp functions
	std::cout << "Calling displayMessage from message.cpp. This should accept a string to display\n";
	std::string message = "Look at this cool string get printed by this cool function!!";
	displayMessage(message);

	std::cout << "Calling messageLength from message.cpp This should display the length of a message.\n";
	messageLength(message);

	std::cout << "Calling promptResponse from message.cpp. This should accept user input prompt or substitute a default one\n";
	promptResponse();
	std::cout << "Please enter a prompt or press d for the default: ";
	std::getline(std::cin, message);
	promptResponse(message);

	//numeric.cpp functions
	std::cout << "Calling counterFunction from numeric.cpp. This should return the number of times the program has been called. \n";
	for (int i = 0; i <= 4; i++)
		counterFunction();

	std::cout << "Calling integerSum from numeric.cpp. This should accept two integers and print and return the sum\n";
	int num1 = 9, num2 = 4;
	integerSum(num1, num2);

	std::cout << "Calling integerSum from numeric.cpp. This should accept two doubles and print and return the sum\n";
	double num3 = 1.25, num4 = .50;
	integerSum(num3, num4);

	//reference.cpp functions
	std::cout << "Calling addrDisplay from reference.cpp. This should accept a value and print and return the address.\n ";
	addrDisplay(num1);
	std::cout << "The address of the variable (from main) is: " << &num1 << "\n";

	std::cout << "Calling concatName from reference.cpp. This should accept two names, concatonate them, print and return that value, and update reference variable\n";
	std::string first_name = "Christine", last_name = "Deidrich", full_name;
	concatName(first_name, last_name, full_name);
	std::cout << "Full name (from main) is: " << full_name << "\n";

	return 0;
}