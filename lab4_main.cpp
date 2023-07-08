//Name: Christine Deidrich 
//Lab 4 - Speed of Sound 

#include <iostream>
#include <string>
#include <iomanip>

//global because if these change...physics have changed
const float AIR_SPEED = 1100; //feet per sec
const float WATER_SPEED = 4900; //feet per sec
const float STEEL_SPEED = 16400; //feet per sec

int main() {
	//ask user to pick air, water, or steel
	//ask user to enter how far something travels in the medium 
	char medium;
	float distance;
	float selected_medium;
	float time;
	std::string medium_name = "";

	std::cout << 
R"(
Please select a medium from the following list.
A. Air
B. Water
C. Steel
)";

	std::cin >> medium;
	medium = toupper(medium);

	switch (medium)
	{
	case 'A': 
		std::cout << "You selected Air.\n";
		selected_medium = AIR_SPEED;
		medium_name = "air";
		break;
	case 'B': 
		std::cout << "You selected Water.\n";
		selected_medium = WATER_SPEED;
		medium_name = "water";
		break;
	case 'C': 
		std::cout << "You selected Steel.\n";
		selected_medium = STEEL_SPEED;
		medium_name = "steel";
		break;
	default: 
		std::cout << "You did not select a valid option. Exiting...\n";
		return 1;
	}

	std::cout << "Please input the distance (in feet) you want the sound wave to travel.\n";
	std::cin >> distance;

	//validate the user input
	if (distance >= 0) {
		std::cout << "You entered " << distance << " feet\n";
	}
	else {
		std::cout << "Invalid distance entered. Exiting...";
		return 1;
	}
	
	//calculate how long it will take for the sound to travel the distance 
	//!!! all of these have to be floats or int math gets truncuated before cast to variable !!!
	time = distance / selected_medium;

	std::cout << "It will take " << std::setprecision(4) << time << " seconds for a sound to travel " << distance << " feet through " << medium_name << ".";
	return 0;
}