//Name: Christine Deidrich 
//Lab 5 - Mobile Service Provider 

#include <iostream>
#include <string>

//struct definition
struct Phone_Package {
	std::string package_name = "";
	double package_cost = 0; 
	double included_data = 0;
	double addtl_data_cost = 0; 
};

// function definition
double costCalc(double user_data, Phone_Package pp) {
	double total_package_cost = pp.package_cost;
	double addtl_data = user_data - pp.included_data; 
	if (addtl_data > 0) {
		total_package_cost = (user_data - pp.included_data) * pp.addtl_data_cost + pp.package_cost;
	}
	else; 

	return total_package_cost;
};

int main() {

	char package;
	std::string package_name;
	double total_package_cost;
	double user_data;

	// ask a customer which package they have
	std::cout <<
		R"(
Package A. $39.99 per month, 4 gigabytes of data included. Additional data costs $10 per gigabyte.
Package B. $59.99 per month, 8 gigabytes of data included. Additional data costs $5 per gigabyte.
Package C. $69.99 per month, unlimited data included.
Please select which package you have (a/b/c).
)";
	package = tolower(std::cin.get());

	Phone_Package user_package;
	switch (package)
	{
	case 'a': {
		user_package.package_name = "Package A";
		user_package.package_cost = 39.99;
		user_package.included_data = 4;
		user_package.addtl_data_cost = 10;
		std::cout << "You selected " << user_package.package_name << ".\n";
		break;
	}
	case 'b': {
		user_package.package_name = "Package B";
		user_package.package_cost = 59.99;
		user_package.included_data = 8;
		user_package.addtl_data_cost = 10;
		std::cout << "You selected " << user_package.package_name << ".\n";
		break;
	}
	case 'c': {
		user_package.package_name = "Package C";
		user_package.package_cost = 69.99;
		user_package.included_data = 0; //how to account for this for unlimited data
		user_package.addtl_data_cost = 0; //how to account for this for unlimited data
		std::cout << "You selected " << user_package.package_name << ".\n";
		break;
	}
	default:
		std::cout << "You did not select a valid option. Exiting...\n";
		return 1;
	}

	std::cout << "Please enter how much data you used (in gigabytes).";
	std::cin >> user_data;

	// calculate the user's bill
	total_package_cost = costCalc(user_data, user_package);
	std::cout << total_package_cost;

	
	// calculate all the plans
	// if total cost is > cost of c, display savings 
	// if total cost is > cost of b, display 
}

/*A mobile phone service provider has three different data plans for its customers :

	Package A : For $39.99 per month, 4 gigabytes are provided. Additional data costs $10 per gigabyte.
	Package B : For $59.99 per month, 8 gigabytes are provided. Additional data costs $5 per gigabyte.
	Package C : For $69.99 per month, unlimited data is provided.

	Write a program that calculates a customer’s monthly bill.
	It should ask which package the customer has purchased and how many gigabytes were used.
	It should then display the total amount due.

	Input Validation : Be sure the user only selects package A, B, or C.

	it also displays how much money Package A customers would save if they purchased packages B
	or C, and how much money Package B customers would save if they purchased Package C.
	If there would be no savings, no message should be printed.

*/