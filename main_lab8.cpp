//Name: Christine Deidrich 
//Lab 8 - Present Value Function

#include <iostream>
#include <tuple>
#include <cmath>
#include <iomanip>

//Function Prototypes - note: type functionName (type, type,...);
std::tuple<double, double, int> getParams(); 
double presentValue(std::tuple<double, double, int>);


int main() {
	char answer = 'n';
	double present_value;
	do {
		std::tuple <double, double, int> params = getParams();
		std::cout << "The values entered are:\n"
			<< "Future Value : $" << std::get<1>(params) << "\n"
			<< "Annual Interest Rate: " << std::get<0>(params) << "%\n"
			<< "Number of Years: " << std::get<2>(params) << "\n";

		present_value = presentValue(params);
		std::cout << "The amount you would have to deposit today is: $" << present_value << "\n";

		std::cout << "Would you like to modify values and re-run the calculation? (y/n): ";
		std::cin >> answer;
		answer = std::tolower(answer);
	}
	while (answer == 'y');
	return 0; 
}

//Function Definitions

// Calcualte the present value from 
double presentValue(std::tuple<double, double, int> user_params) {
	double interest_rate, future_value, denominator;
	int years;
	std::tie(interest_rate, future_value, years) = user_params;
	interest_rate = interest_rate / 100;
	denominator = pow((1 + interest_rate), years);
	if (denominator == 0) {
		std::cout << "ERROR: Divide by 0 error!";
		std::exit(0);
	}
	else;
	double present_value = future_value / denominator ; 
	return present_value;
}
// Get the User-entered params 
std::tuple<double, double, int> getParams() {
	double interest_rate = 0, future_value = 0;
	int years = 0;
	std::tuple<double, double, int> params;
	std::cout << "Please enter the target future value for the account (in dollars).\n";
	std::cin >> future_value;
	std::cout << "Please enter the number of years.\n";
	std::cin >> years;
	std::cout << "Please enter the annual interest rate (in percentage).\n";
	std::cin >> interest_rate;
	return std::make_tuple(interest_rate, future_value, years);
 
}