//Name: Christine Deidrich 
//Lab 7

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h> //atoi

const std::string FILENAME = "C:\\Users\\Christine Deidrich\\Downloads\\MOCK_DATA.csv";


int averageCalc(int sum, int count) {
	int avg;
	avg = sum / (count--);
	return avg;
}

int main() {

	// I don't like the initializing with 0
	int max = 0; 
	int min = 0; 
	int sum = 0; 
	int count = 0;
	int value;
	std::string file_header;

	std::ifstream infile (FILENAME); 

	if (!infile) {
		std::cout << "File Not Found";
	}
	else;

	// I don't like the way I solved this, but I got a bit stuck with the header.
	while (infile) {
		if (count == 0) {
			infile >> file_header;
			count++;
		}
		else {

			while (infile >> value) {
				count++;

				sum = sum + value;

				(value > max) ? max = value : max;
				// max = std::max(max, value);

				(value < min) ? min = value : min;
				// min = std::min(min, value);


			}
			int avg = averageCalc(sum, count);

			std::cout << "Maximum: " << max << "\n";
			std::cout << "Minimum: " << min << "\n";
			std::cout << "Sum: " << sum << "\n";
			std::cout << "Average: " << avg << "\n";
			infile.close();

		}
	}
	return 0;
}