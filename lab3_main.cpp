// LAB 3 
// Name: Christine Deidrich
#include <iostream>
#include <iomanip>

// declare widget weight
const float WIDGET_WEIGHT = 12.5;
 
int main() {

	// instantiate vars
	/*could do this with some doubles and some ints, but would rather start with 
	more precision since data entry is ambigous. Could be space for optimization */
	double pallet_weight, total_weight, prod_weight, num_widgets, leftover_weight;

	// get pallet weight 
	// get total weight (pallet + widgets)
	std::cout << "Please enter the weight of just the pallet? ";
	std::cin >> pallet_weight;
	std::cout << "Please enter the total weight of the pallet: ";
	std::cin >> total_weight;

	// get weight of just product on pallet 
	prod_weight = total_weight - pallet_weight;

	// how many WHOLE widgets on the pallet
	num_widgets = prod_weight / WIDGET_WEIGHT;
	int int_num_widgets; 
	int_num_widgets = static_cast<int>(num_widgets);
	
	// calculate leftover weight (fractions of widgets)
	// two ways to do the same thing
	// leftover_weight = total_weight - ((int_num_widgets * WIDGET_WEIGHT) + pallet_weight);
	leftover_weight = fmod(prod_weight, WIDGET_WEIGHT);

	//make it pretty for funsies 
	std::cout << "\nYukon Widget Company Calculator\n"; 
	std::cout << "- - - - - - - - - - - - - - - -\n";
	std::cout << std::left << std::setw(19) << "Pallet Weight: " << std::right << std::setw(8) << pallet_weight << '\n';
	std::cout << std::left << std::setw(19) << "Total Weight: " << std::right << std::setw(8) << total_weight << '\n';
	std::cout << std::left << std::setw(19) << "Product Weight: " << std::right << std::setw(8) << prod_weight << '\n';
	std::cout << std::left << std::setw(19) << "Number of Widgets: " << std::right << std::setw(8) << int_num_widgets << '\n';
	std::cout << std::left << std::setw(19) << "Extra Weight: " << std::right << std::setw(8) << leftover_weight  << '\n';

	return 0;




}


