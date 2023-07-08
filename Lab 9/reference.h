//Name: Christine Deidrich
/* A function that accepts a reference to a variable and displays the address.
Display the address in main as well.
A function that accepts first and last name and returns them concatenated with a space between them
A function that accepts first and last name and updates a reference variable with them
concatenated as full name (returning the value would be preferred, but this is a lab)*/

#pragma once
#ifndef REFERENCE_H
#define REFERENCE_H

#include <string>

void addrDisplay(int&); //reference to a var, displays addr

std::string concatName(std::string, std::string, std::string&); //first_name, last_name, full_name

#endif
