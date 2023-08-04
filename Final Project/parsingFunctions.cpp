//functions that make the data pretty for the user

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

//TODO: Update for Hardware data
struct HW_Data {
	std::string package_name = "";
	double package_cost = 0;
	double included_data = 0;
	double addtl_data_cost = 0;
};

//TODO: Update for Software data
struct SW_Data {
	std::string package_name = "";
	double package_cost = 0;
	double included_data = 0;
	double addtl_data_cost = 0;
};

std::string stringParse(std::string command_output, char delim) {
		std::istringstream iss(command_output);
		std::string token;
		while (std::getline(iss, token, delim))
		{
			std::cout << token << std::endl;
		}
		return token;
}

void hwDataDisplay(std::string hostname) {
	//TODO: make this prettier
	std::cout << "\nHardware Data\n";
	std::cout << "- - - - - - - - - - - - - - - -\n";
	std::cout << std::left << std::setw(19) << "Hostname: " << std::right << std::setw(8) << hostname << std::endl;
	//std::cout << std::left << std::setw(19) << "Memory: " << std::right << std::setw(8) << total_weight << '\n';
	//std::cout << std::left << std::setw(19) << "Storage:  " << std::right << std::setw(8) << prod_weight << '\n';
	//std::cout << std::left << std::setw(19) << "CPU Temperature: " << std::right << std::setw(8) << int_num_widgets << '\n';
	//std::cout << std::left << std::setw(19) << "CPU Operating Frequency: " << std::right << std::setw(8) << leftover_weight << '\n';
	
}

void swDataDisplay() {
	std::cout << "\nSoftware Data\n";
	std::cout << "- - - - - - - - - - - - - - - -\n";
	//std::cout << std::left << std::setw(19) << "Hostname: " << std::right << std::setw(8) << hostname << std::endl;
	//std::cout << std::left << std::setw(19) << "Operating System: " << std::right << std::setw(8) << total_weight << '\n';
	//std::cout << std::left << std::setw(19) << "Kernel:  " << std::right << std::setw(8) << prod_weight << '\n';
	//std::cout << std::left << std::setw(19) << "Number of Widgets: " << std::right << std::setw(8) << int_num_widgets << '\n';
	//std::cout << std::left << std::setw(19) << "Extra Weight: " << std::right << std::setw(8) << leftover_weight << '\n';

}