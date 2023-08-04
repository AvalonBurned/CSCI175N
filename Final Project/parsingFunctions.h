#pragma once

#ifndef PARSING_H
#define PARSING_H

//TODO: Update for Hardware data
/*
struct HW_Data {
	std::string hostname = "";
	double  = 0;
	double included_data = 0;
	double addtl_data_cost = 0;
};
*/

//TODO: Update for Software data
struct SW_Data {
	std::string package_name = "";
	double package_cost = 0;
	double included_data = 0;
	double addtl_data_cost = 0;
};

std::string stringParse(std::string command_output, char delim);

void hwDataDisplay(std::string hostname);

void swDataDisplay(std::string hostname);

#endif
