#ifndef __CALCULATOR_HPP
#define __CALCULATOR_HPP

#include <string>

// this function should expect that `expression` has already been
// validated and thus throw no exceptions
double parse_number(const std::string &expression);

// this function checks for the validity of a double
bool valid_double(const std::string& expression);

// this function adds two strings representing double numbers
double add(const std::string& num1, const std::string& num2);

#endif // __CALCULATOR_HPP
