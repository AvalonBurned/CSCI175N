/* A void function that accepts a message to display
An integer function that accepts a message to display and returns the length of the message
A string function that accepts a prompt and returns the user's response
A string function with a default prompt*/

#include <iostream>
#include <string>
#include "message.h"

// This function will accept a message to display
void displayMessage(std::string message) {
	std::cout << message << "\n";
}

// This function will accept a message 
// It will print and return the length of the message
int messageLength(std::string message) {
	std::cout << message.length() << "\n";
	return message.length();
}

// This message will accept a user input prompt or substitute a default one.
// It will print out and return the message.
std::string promptResponse(std::string message) {
	std::cout << "Your message is: " << message << "\n";
	return message;
}