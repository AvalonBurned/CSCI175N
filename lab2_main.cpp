/* Name: Christine Deidrich
   Lab: Lab 2 */

#include <iostream>
#include <string>

// we are doing something here
// #define hx(v)  

const int GLOBAL_CONSTANT = 7;
// void show(std::string, std::string/*, std::string*/);

int main() {
	//declare your variables
	short s = 50000;
	int i = 60;
	float f_pi = 5.0e1;
	double d_pi = 22.0 / 7;
	char c = '5';

	// THE ACTUAL ASSIGNMENT
	std::cout << "Value of the variable is " << c /* variable */ << '\n';
	std::cout << "Address of the variable is " << &c /* &variable */ << '\n';
	std::cout << "Size of the variable is " << sizeof c /* sizeof variable */ << '\n';
	std::cout << "\0";

	//iterate the function for each variable
	// show("s", std::to_string(s)/*, std: to_string(sizeof s), std::to_string(&s)*/);
	// show("i", std::to_string(s)/*, std: to_string(sizeof s), std::to_string(&s)*/);
	// show("f_pi", std::to_string(s)/*, std: to_string(sizeof s), std::to_string(&s)*/);
	// show("d_pi", std::to_string(s)/*, std: to_string(sizeof s), std::to_string(&s)*/);

	// playing with a function for funsies 
	// void show(std::string var_name, std::string value) {
	//  std::cout << "Value of the variable is " << i /* variable */ << '\n';
	// 	std::cout << "Address of the variable is " << &i /* &variable */ << '\n';
	//	std::cout << "Size of the variable is " << sizeof i /* sizeof variable */ << '\n';
	//	}

}