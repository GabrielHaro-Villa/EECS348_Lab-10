#include <iostream>
#include <fstream>
#include "calculator.hpp"

int main(int argc, char *argv[]) {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Could not open the file" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        // validate and parse the number
        if (valid_double(line)) {
            std::cout << "Valid number: " << line << std::endl;
            double result = add(line, "-123.456");
            std::cout << "Result of addition: " << result << std::endl;
        } else {
            std::cout << "Invalid number: " << line << std::endl;
        }
    }

    file.close();
    return 0;
}
