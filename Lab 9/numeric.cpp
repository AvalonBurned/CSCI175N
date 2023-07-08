//Name: Christine Deidrich
/*A counter function that returns the number of times it has been called. 
Call the function at least 5 times.
An integer function that accepts two integers and returns an integer sum
Overload the previous to work for double precision numbers*/

#include <iostream>

// This function returns the number of times it has been called
int counterFunction() {
	static int staticNum; 
	staticNum++;
	std::cout << "Static Num is: " << staticNum << "\n";
	return staticNum;
}

// This function accepts two integers and returns an integer sum
int integerSum(int num1, int num2) {
	int intSum = num1 + num2;
	std::cout << intSum << "\n";
	return intSum;
}

// This function accepts two doubles and returns and prints a double sum
double integerSum(double num1, double num2) {
	double doubleSum = num1 + num2;
	std::cout << doubleSum << "\n";
	return doubleSum;
}