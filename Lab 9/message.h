//Name: Christine Deidrich 
//Lab 9 - Function Sampler

//Name: Christine Deidrich
/*A void function that accepts a message to display
An integer function that accepts a message to display and returns the length of the message
A string function that accepts a prompt and returns the user's response
A string function with a default prompt */

#pragma once
#ifndef MESSAGE_H
#define MESSAGE_H
#include <iostream>
#include <string>

void displayMessage(std::string message);

int messageLength(std::string message);

std::string promptResponse(std::string message = "This is the default message.");


#endif
