//Name: Christine Deidrich 
//Lab 11 - Addresses and Pointers

#include <iostream>
#include <string>

// Function Definitions
void my_swap(int* x, int* y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void ptr_display(int SIZE, double arr[]) {
	double* arr_ptr = nullptr;
	arr_ptr = arr;
	for (int i = 0; i < SIZE; i++)
		std::cout << "Array Element: " << i << " Array Value (pointer): " << arr_ptr[i] << "\n" << " Array Value (subscript): " << *(arr_ptr + i) << "\n";
}

int main() {
	// Interger Pointers
	int a = 1, b = 2;
	int* a_ptr = nullptr;
	int* b_ptr = nullptr;
	a_ptr = &a;
	b_ptr = &b;

	std::cout << "Address of a:  " << &a << " Value of a: " << a << "\n";
	std::cout << "Address of b:  " << &b << " Value of b: " << b << "\n";

	std::cout << "Value of a: " << a_ptr << " Contents of a: " << *a_ptr << "\n";
	std::cout << "Value of b: " << b_ptr << " Contents of b: " << *b_ptr << "\n";

	//Code your own swap function to swap the values of the variables and call it.
	my_swap(&a, &b);
	std::cout << "The value of a is: " << a << "\n";
	std::cout << "The value of b is: " << b << "\n";

	//String Pointers
	std::string str = "an arbitrary string";
	std::string* str_ptr = nullptr;
	str_ptr = &str;

	std::cout << "Address of string is:  " << &str << " Value of string: " << str << "\n";
	std::cout << "Value of string: " << str_ptr << " Contents of string: " << *str_ptr << "\n";

	//Pointers with arrays or vectors
	const int SIZE = 3;
	double arr[SIZE] = {1.2, 2.3, 3.4};
	double* arr_ptr = nullptr;
	arr_ptr = arr;

	ptr_display(SIZE, arr);
	
	//Change the 3rd element of the array to - 123.456 using pointer notation.
	*(arr_ptr + 2) = -123.456;

	ptr_display(SIZE, arr);

	return 0; 
}




