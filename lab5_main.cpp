//Name: Christine Deidrich 
//Lab 5 - Mobile Service Provider 

#include <iostream>
#include <string>
#include <iomanip>

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
	if (addtl_data) {
		total_package_cost = (user_data - pp.included_data) * pp.addtl_data_cost + pp.package_cost;
	}
	else; 

	return total_package_cost;
};

int main() {

	char package;
	std::string package_name;
	double total_package_cost_user;
	double user_data;
	double total_package_cost_a;
	double total_package_cost_b;
	double total_package_cost_c;
	double user_savings;

	// ask a customer which package they have
	std::cout <<
		R"(
Package A. $39.99 per month, 4 gigabytes of data included. Additional data costs $10 per gigabyte.
Package B. $59.99 per month, 8 gigabytes of data included. Additional data costs $5 per gigabyte.
Package C. $69.99 per month, unlimited data included.
Please select which package you have (a/b/c).
)";
	package = tolower(std::cin.get());
	Phone_Package package_a = { "Package A", 39.99, 4, 10 };
	Phone_Package package_b = { "Package B", 59.99, 8, 5 };
	Phone_Package package_c = { "Package C", 69.99, 0, 0 };

	Phone_Package user_package;
	switch (package)
	{
	case 'a': {
		user_package = package_a;
		std::cout << "You selected " << user_package.package_name << ".\n";
		break;
	}
	case 'b': {
		user_package = package_b;
		std::cout << "You selected " << user_package.package_name << ".\n";
		break;
	}
	case 'c': {
		user_package = package_c;
		std::cout << "You selected " << user_package.package_name << ".\n";
		break;
	}
	default:
		std::cout << "You did not select a valid option. Exiting...\n";
		return 1;
	}

	std::cout << "Please enter how much data you used (in gigabytes).";
	std::cin >> user_data;
	std::cout << "You entered " << user_data << " gigabytes.\n";


	// calculate the user's bill
	total_package_cost_user = costCalc(user_data, user_package);
	std::cout << "Your bill is $" << total_package_cost_user << "\n";

	// calculate all the plans with user data
	total_package_cost_a = costCalc(user_data, package_a);
	total_package_cost_b = costCalc(user_data, package_b);
	total_package_cost_c = costCalc(user_data, package_c);

	// if the user can save money by switching to a different plan, display savings
	if (total_package_cost_user >= total_package_cost_b && user_package.addtl_data_cost != 0) {
		user_savings = total_package_cost_user - total_package_cost_b;
		if (user_savings) {
			std::cout << "If you switched to " << package_b.package_name << " you could save $" << user_savings << "!!\n";
		}
		else;
	}
	else;

	if (total_package_cost_user > total_package_cost_c) {
		user_savings = total_package_cost_user - total_package_cost_c;
		std::cout << "If you switched to " << package_c.package_name << " you could save $" << user_savings << "!!\n";
	}
	return 0;
}
