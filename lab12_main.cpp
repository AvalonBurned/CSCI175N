//Name: Christine Deidrich 
//Lab 12 - Random Statistics 

/*
Code a function that dynamically allocates an integer array of between 10 and 25 elements. Store the number of elements in the first element of the array, then populate the remaining elements of the array with random integers between 0 and 3, inclusive.

Call the function and use pointers to point to the median value (if possible), calculate the mean, and point to the first instance of the mode.

The median value will either be a pointer to the median value in the array, or the calculated value of the median
The mean will be a double precision variable with the calculated value of the mean
The mode will be a pointer to the first instance of the mode. For example, if the values are 1,2,3,4,4,5 the mode would be a pointer to the first 4.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm> //for sort function

//Function Definitons

// Populate an array 
int* populateArray(int arr_len, int MAX_ARR_VALUE, int MIN_ARR_VALUE) {
	
	//does this have issues with lifecycle of this array? - if not, why?
	// Initialize an array in a way that gets around a not constant array length value
	int* arrptr = new int[arr_len];
	arrptr[0] = arr_len;

	for (int j = 1; j < arr_len; j++) {
		int y = rand() % (MAX_ARR_VALUE + 1 - MIN_ARR_VALUE) + MIN_ARR_VALUE;
		arrptr[j] = y;
	}
	return arrptr;
}


// Sort an array by increasing values
void sortArray(int* arrptr, int arr_len) {
	std::sort(arrptr + 1, arrptr + arr_len); // Sorts starting at the second value

}

// Calculate the mean of an array
float calcMean(int* arrptr, int arr_len) {
	float mean = 0;
	for (int i = 1; i < arr_len; i++) { //again, skips the first item in the array
		mean += arrptr[i];
	}
	return mean / (arr_len - 1);
}

// Calculate the mode of an array
// If there are two modes, this function returns the lower of the values
int calcMode(int* arrptr, int arr_len, int MAX_ARR_VALUE) {
	int* count = new int[MAX_ARR_VALUE + 1];
	int mode = 0;
	int j = 0;
	
	for (int i = 0; i < (MAX_ARR_VALUE + 1); i++) {
		count[i] = 0;
		if (arrptr[i] <= MAX_ARR_VALUE) {
			count[arrptr[i]]++; //increment counter for value
		}
	}

	for (int i = 1; i < (MAX_ARR_VALUE + 1); i++) {
		if (count[i] > j) {
			j = count[i];
			mode = i;
		}
	}
	return mode;
}

int* firstMode(int* arrptr, int arr_len, int mode) {

	//Point to the first instance of the mode
	for (int i = 0; i < arr_len; i++) {
		if (arrptr[i] == mode) {
			return &arrptr[i];
		}
	}
}

// Calculate the median of an array
float calcMedian(int* arrptr, int arr_len) {
	int values = arr_len - 1;
	int middle = values / 2;
	float median;

	if (values % 2 == 0) {
		median = ((static_cast<float>(arrptr[middle + 1]) + arrptr[middle]) / 2);
	}
	else {
		median = arrptr[middle + 1];
	}
	// I could return the pointer to the value in the array by using & on the arrptr expression for odd sets
	// but then would have to overload the function based on the "values" value
	return median;
};

const int MIN_VALUE = 10;
const int MAX_VALUE = 25;
const int MAX_ARR_VALUE = 15;
const int MIN_ARR_VALUE = 0;

int main() {
	//pick a random number between 10 and 25
	//srand(time(0));
	int arr_len = rand() % (MAX_VALUE + 1 - MIN_VALUE) + MIN_VALUE;

	// Create and Populate the Array
	int* arrptr = populateArray(arr_len, MAX_ARR_VALUE, MIN_ARR_VALUE);

	// Sort the Array
	sortArray(arrptr, arr_len);

	//for continued sanity checking
	
	for (int i = 0; i < arr_len; i++) {
		std::cout << arrptr[i] << ", ";
	}

	// Calculate the Median
	float median = calcMedian(arrptr, arr_len);
	std::cout << "The median is: " << median << std::endl;

	// Count the Mode
	int mode = calcMode(arrptr, arr_len, MAX_ARR_VALUE);
	int* mode_position = firstMode(arrptr, arr_len, mode);
	std::cout << "The mode is: " << mode << std::endl;

	//Calculate the Mean
	float mean = calcMean(arrptr, arr_len);
	std::cout << "The mean is: " << mean << std::endl;

	delete arrptr;
	arrptr = nullptr;

	return 0;
}