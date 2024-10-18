#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	if (this != &other)
		*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;	 
}

void ScalarConverter::convert(const std::string &str)
{
	if (str.)
}

float stof98(const std::string& str) {
    std::stringstream ss(str);
    float result;
    ss >> result;
    
    if (ss.fail()) {
        throw std::invalid_argument("Invalid input string for float conversion"); // Ayarlancak
    }
    
    return result;
}

int stoi98(const std::string& str) {
    std::stringstream ss(str);
    int result;
    ss >> result;
    
    if (ss.fail()) {
        throw std::invalid_argument("Invalid input string for float conversion"); // Ayarlancak
    }
	return (result);
}


double stod98(const std::string& str) {
    std::stringstream ss(str);
    double result;
    ss >> result;
    
    if (ss.fail()) {
        throw std::invalid_argument("Invalid input string for float conversion"); // Ayarlancak
    }
	return (result);
}
