#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

class ScalarConverter {

private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter & operator = (const ScalarConverter &other);
public:
	static void convert(const std::string &str);
};


#endif