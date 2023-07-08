//Name: Christine Deidrich
/* A function that accepts a reference to a variable and displays the address. 
Display the address in main as well.
A function that accepts first and last name and returns them concatenated with a space between them
A function that accepts first and last name and updates a reference variable with them 
concatenated as full name (returning the value would be preferred, but this is a lab)*/


#include <iostream>

void addrDisplay(int &var) {
	std::cout << "The address of the variable (from function) is: " << &var << "\n";
}

std::string concatName(std::string first_name, std::string last_name, std::string &full_name) {
	full_name = first_name + " " + last_name;
	std::cout << "Full Name (in function) is: " << full_name << "\n";
	return full_name;
}