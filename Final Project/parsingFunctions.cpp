//Functions that make the data pretty and ready to display

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

// This approach has scalability concerns and relies on a knowledge of how the 
// data is returned by the system
std::string stringParse(std::string command_output, char delim) {
		std::istringstream iss(command_output);
		std::string token;
		while(std::getline(iss, token, delim)); //returns last token
		return token;
}

// removes leading and trailing spaces 
std::string removeSpace(std::string command_output) {

	std::string::iterator it;
	it = std::find_if_not(command_output.begin(), command_output.end(), isspace);
	command_output.erase(command_output.begin(), it);

	std::string::reverse_iterator r_it;
	r_it = std::find_if_not(command_output.rbegin(), command_output.rend(), isspace);
	// need .base() to access the interator
	command_output.erase(r_it.base(), command_output.end());

	return command_output;
}

