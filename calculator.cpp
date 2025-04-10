#include "calculator.hpp"
#include <iostream>
#include <fstream>

bool valid_double(const std::string& str) {
    size_t i = 0; // start from the beginning of the string
    bool decimal_point = false;
    bool digit_after_decimal = false;

    // Handle optional sign
    if (str[i] == '+' || str[i] == '-') { // check for sign
        i++; // move to the next character
    }

    bool digit_before_decimal = false;
    while (i < str.size() && std::isdigit(str[i])) { // while the character is less than size and is a digit
        i++; // move to the next character
        digit_before_decimal = true; 
    }

    // checks for a decimal point
    if (i < str.size() && str[i] == '.') {
        decimal_point = true;
        i++;

        // Process digits after the decimal point
        while (i < str.size() && std::isdigit(str[i])) {
            i++;
            digit_after_decimal = true;
        }
    }

    // If there's no digit before the decimal or no digit after it's invalid
    return (digit_before_decimal || digit_after_decimal) && 
           (!decimal_point || digit_after_decimal) && i == str.size();
}

double parse_number(const std::string &expression) {
    if (!valid_double(expression)) { // Check if the expression is a valid double
        std::cerr << "Invalid double: " << expression << std::endl;
        return 0.0;
    }

    bool is_negative = false;
    size_t i = 0;
    // checks for sign at beginning and skips it
    if (expression[i] == '-') {
        is_negative = true;
        i++;
    }else if (expression[i] == '+') {
        i++;
    }

    // Parse the integer part
    while (i < expression.size() && expression[i] == '0') {
        i++;
    }

    // parse integer part
    double result = 0.0;
    // while the character is less than size and is a digit
    while (i < expression.size() && std::isdigit(expression[i])) {
        result = result * 10 + (expression[i] - '0');
        i++;
    }

    // parse decimal part if there is one
    if (i < expression.size() && expression[i] == '.') {
        i++;
        double decimal_factor = 0.1; // start with 0.1 for the first decimal place
        while (i < expression.size() && std::isdigit(expression[i])) {
            result += (expression[i] - '0') * decimal_factor;
            decimal_factor *= 0.1;
            i++;
        }
    }

    return is_negative ? -result : result; // return the result
}

// This function adds two strings representing double numbers
// and returns the result as a double
double add(const std::string& num1, const std::string& num2) {
    // Parse the numbers from strings
    double number1 = parse_number(num1);
    double number2 = parse_number(num2);

    // Add the numbers and return the result
    return number1 + number2;
}