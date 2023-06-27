//Name: Christine Deidrich 
//Lab 8 - 

#include <iostream>
#include <tuple>
#include <cmath>

//Function Prototypes - note: type functionName (type, type,...);
std::tuple<double, double, int> getParams(); 
double presentValue(std::tuple<double, double, int>);
/*Write a program that has a function named presentValue that performs this calculation. 
The function should accept the future value, annual interest rate, and number of years as arguments. 
It should return the present value, which is the amount that you need to deposit today. 
Demonstrate the function in a program that lets the user experiment with different values for the formula’s terms.*/

int main() {
	//CAN I DO THIS IN A DO-WHILE LOOP?
	//get user input
	char answer = 'n';
	double present_value;
	std::tuple <double, double, int> params = getParams();
	std::cout << "The values input are:\n"
		<< "Future Value: " << std::get<0>(params) << "\n"
		<< "Interest Rate: " << std::get<1>(params) << "\n"
		<< "Number of Years: " << std::get<2>(params) << "\n";
	//do the calculation
	present_value = presentValue(params);
	std::cout << "The amount you would have to deposit today is: $" << present_value << "\n";

	//display the result
	//ask if the user wants to update any values 
	std::cout << "Would you like to modify values and re-run the calculation? (y/n): "; 
	std::cin >> answer;
	answer = std::tolower(answer);
	if (answer == 'y') {
		std::tuple <double, double, int> params = getParams();
		std::cout << "The values input are:\n"
			<< "Future Value: " << std::get<0>(params) << "\n"
			<< "Interest Rate: " << std::get<1>(params) << "\n"
			<< "Number of Years: " << std::get<2>(params) << "\n";
		present_value = presentValue(params);
		std::cout << "The amount you would have to deposit today is: $" << present_value << "\n";
	}
	else; 

	//if y - update values and re-run calculation 
	//else n
	return 0; 
}

//Function Definitions

//Calculate the present value using the prescribed formula
//THE MATH DO NOT BE MATHING
double presentValue(std::tuple<double, double, int> tup1) {
	double interest_rate, future_value;
	int years;
	//TODO: Check for divide by 0
	std::tie(interest_rate, future_value, years) = tup1;
	double present_value = future_value / pow((1 + interest_rate), years); 
	return present_value;
}
//Get the user-entered parameters
std::tuple<double, double, int> getParams() {
	double interest_rate = 0, future_value = 0;
	int years = 0;
	std::tuple<double, double, int> params;
	//TODO: Fix the wording here
	std::cout << "Please input the target future value for the account.\n";
	std::cin >> future_value;
	std::cout << "Please input how many years.\n";
	std::cin >> years;
	std::cout << "Please input the desired interest rate.\n";
	std::cin >> interest_rate;
	return std::make_tuple(interest_rate, future_value, years);
 
}