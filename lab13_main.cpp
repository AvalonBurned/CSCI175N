//Name: Christine Deidrich 
//Lab 13 - Constants and Vowels


#include <iostream>
#include <cstring>


int countLetters(char* str, char* letter) {
	int letter_count = 0;
	char* pos = nullptr;
	for (int v = 0; v < strlen(letter); v++) { 
		pos = std::strchr(str, letter[v]);
		while (pos != NULL) {
			pos = std::strchr(pos+1, letter[v]);
			letter_count++;
		}
	}
	return letter_count;
}

const int SIZE = 50;

int main() {
	char option = 0;
	char exit = 'n';
	char str[SIZE] = {};
	char vowel[] = "aeiou";
	char consonents[] = "bcdfghjklmnpqrstvwxyz";
	int i = 0;
	int consot_count = 0;
	int vowel_count = 0;

	std::cout << "Please enter a string of no more than " << (SIZE - 1) << " characters:" << std::endl;
	std::cin.getline(str, SIZE);
	// This checks if there is overflow from the getline operation. If so, warns the user and clears the buffer.
	// Note: does not protect the user from this
	if (std::cin.gcount() == SIZE - 1 && std::strlen(str) == SIZE - 1) {
		std::cout << "WARNING: String length execeeds maximum length. Some data may be lost." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<char>::max(), '\n');
	}
	
	std::cout << "You entered: " << str << "\n";

	//cast the line to lower
	while (str[i]) {
		str[i] = tolower(str[i]);
		i++;
	}

	do {
		std::cout <<
			R"(
	A) Count the number of vowels in the string
	B) Count the number of consonants in the string
	C) Count both the vowels and consonants in the string
	D) Enter another string
	E) Exit the program
	Please select an option above (a/b/c/d/e).
	)";
		option = tolower(std::cin.get());
		// Clearing the input buffer
		std::cin.ignore(std::numeric_limits<char>::max(), '\n');

		switch (option)
		{
		case 'a': {
			std::cout << "You selected counting the vowels" << std::endl;
			vowel_count = countLetters(str, vowel);
			std::cout << "This string has " << vowel_count << " vowel(s).";
			break;
		}
		case 'b': 
			std::cout << "You selected counting the consonants." << std::endl;
			consot_count = countLetters(str, consonents);
			std::cout << "This string has " << consot_count << " consonant(s).";
			break;
		case 'c': {
			std::cout << "You selected counting the vowels and the consonants." << std::endl;
			int vowel_count = countLetters(str, vowel);
			std::cout << "\n";
			int consot_count = countLetters(str, consonents);
			std::cout << "This string has " << vowel_count << " vowel(s) and " << consot_count << " consonents." << std::endl;
			break;
		}
		case 'd': {
			std::cout << "You selected entering another string" << std::endl;
			std::cout << "Please enter a string of no more than " << (SIZE - 1) << " characters:" << std::endl;
			std::cin.getline(str, SIZE);
			// This checks if there is overflow from the getline operation. If so, warns the user and clears the buffer.
			// Note: does not protect the user from this
			if (std::cin.gcount() == SIZE - 1 && std::strlen(str) == SIZE - 1) {
				std::cout << "WARNING: String length execeeds maximum length. Some data may be lost." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<char>::max(), '\n');
			}
			std::cout << "You entered: " << str << std::endl;
			break;
		}
		case 'e': 
			std::cout << "Exiting...";
			exit = 'y';
			break;
	
		default:
			std::cout << "You did not select a valid option. Exiting..." << std::endl;
			return 1;
		}
	}
	while (exit != 'y');

	return 0;
}