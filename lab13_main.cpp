//Name: Christine Deidrich 
//Lab 13 - Constants and Vowels


#include <iostream>
#include <cstring>


int countVowels(char* prompt) {
	int vowel_count = 0;
	char vowel[] = "aeiouAEIOU"; // caps could be removed with addition of tolower code block
	// int potato = sizeof(vowel);
	// std::cout << potato;
	char* pos = nullptr;
	for (int v = 0; v < 10; v++) { // once caps are removed change to max of array (TODO - find better way)
		pos = std::strchr(prompt, vowel[v]);
		while (pos != NULL) {
			pos = std::strchr(pos+1, vowel[v]);
			vowel_count++;
		}
	}
	std::cout << "This string has " << vowel_count << " vowel(s).";
	return vowel_count;
}

int countConsot(char* prompt) {
	int consot_count = 0;
	char consot[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ"; // caps could be removed with addition of tolower code block
	char* pos = nullptr;
	for (int c = 0; c < 42; c++) { // once caps are removed change to max of array(TODO - find better way)
		pos = std::strchr(prompt, consot[c]);
		while (pos != NULL) {
			pos = std::strchr(pos + 1, consot[c]);
			consot_count++;
		}
	}
	std::cout << "This string has " << consot_count << " consonant(s).";
	return consot_count;
}

const int SIZE = 3;

int main() {
	char option = 0;
	char exit = 'n';
	char prompt[SIZE] = {};
	//int i = 0;

	//have the user enter a string
	std::cout << "Please enter a string of no more than " << (SIZE - 1) << " characters:\n";
	std::cin.getline(prompt, SIZE);
	if (std::cin.gcount() > 0) {
		std::cout << "WARNING: String length execeeds maximum length. Some data may be lost.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<char>::max(), '\n');
	}
	
	std::cout << "You entered: " << prompt << "\n";
	/*
	// instructions don't say cast the line to lower - so commenting this out for now
	//cast the line to lower
	while (prompt[i]) {
		char x;
		x = prompt[i];
		x = tolower(x);
		prompt[i] = x;
		i++;
	}
	std::cout << prompt;
	*/


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
		case 'a': 
			std::cout << "You selected counting the vowels" << ".\n";
			countVowels(prompt);
			break;
	
		case 'b': 
			std::cout << "You selected counting the consonants" << ".\n";
			countConsot(prompt);
			break;
	
		case 'c': 
			std::cout << "You selected counting the vowels and the consonants" << ".\n";
			countVowels(prompt);
			std::cout << "\n";
			countConsot(prompt);
			break;
	
		case 'd': 
			std::cout << "You selected entering another string" << ".\n";
			std::cout << "Please enter a string of no more than " << (SIZE - 1) << " characters:\n";
			std::cin.getline(prompt, SIZE);
			std::cout << "You entered: " << prompt << "\n";
			break;
	
		case 'e': 
			std::cout << "Exiting...";
			exit = 'y';
			break;
	
		default:
			std::cout << "You did not select a valid option. Exiting...\n";
			return 1;
		}
	}
	while (exit != 'y');

	return 0;
}