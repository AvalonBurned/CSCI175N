//Functions that make the data pretty and ready to display
#pragma once

#ifndef PARSING_H
#define PARSING_H

#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

std::string stringParse(std::string command_output, char delim);

std::string removeSpace(std::string command_output);

#endif
