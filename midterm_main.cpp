// Example program
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

int main()
{
	std::string search_value;
	std::string value;
	int counter = 0;

	const std::string FILENAME = "C:\\Users\\Christine Deidrich\\Downloads\\demo.txt";

	std::cout << "Please enter your search value: ";
	std::cin >> search_value;

	std::ifstream infile(FILENAME);
	if (!infile) {
		std::cout << "File Not Found";
		std::exit;
	}
	else;

	while (infile >> value) {
		if (value == search_value) { counter++; }
		else;
	}

	std::cout << "Your search value: " << search_value << " was counted " << counter << " times in the file.";
}