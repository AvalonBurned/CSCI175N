//Name: Christine Deidrich 
//Lab 6a - Guessing Game 

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


const int MIN_VALUE = 1; 
const int MAX_VALUE = 100;


int main() {
	std::srand(time(0));
	int user_guess = 0; 
	int guess_counter = 0;
	char play_again = 'y';

// ask the user to guess a number
	while (play_again == 'y')
	{
		// Generate a pseudo-random number 

		int num = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
		std::cout << num << '\n';
		guess_counter = 0;
		do {
			std::cout << "Guess a number between " << MIN_VALUE << " and " << MAX_VALUE << "! (enter 0 to quit):\n";
			std::cin >> user_guess;
			// validate the user input
			if (user_guess >= 1 && user_guess <= MAX_VALUE) {
				// increment the number of guesses by 1
				guess_counter++;
				// compare the number to the target number
				if (user_guess > num) {
					std::cout << "Your guess is too high. Try again!\n";
				}
				else if (user_guess < num) {
					std::cout << "Your guess is too low. Try again!\n";
				}
				else;
				std::cout << "You have guessed " << guess_counter << " time(s).\n";
			}
			// check user input against the sentinel value (for quitting)
			else if (user_guess == 0) {
				std::cout << "The correct answer was " << num << ". Thanks for playing!\n";
				play_again = 'n';
				break;
			}
			else;
		} while (user_guess != num);

		if (user_guess == num) {
			std::cout << "Your guess was just right! Congratulations!!\n";
			std::cout << "Would you like to play again? (y/n)";
			std::cin >> play_again;
		}
	} 
	return 0;
}


