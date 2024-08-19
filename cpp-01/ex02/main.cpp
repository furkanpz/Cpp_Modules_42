#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "===========" << std::endl;
	std::cout << "string Adress :" << &str << std::endl 
	<< "stringPTR Adress :" << &*stringPTR << std::endl
	<< "stringREF Adress :" << &stringREF << std::endl;
	std::cout << "===========" << std::endl;
	std::cout << "string Value :" << str << std::endl 
	<< "stringPTR Value :" << *stringPTR << std::endl
	<< "stringREF Value :" << stringREF << std::endl;
	std::cout << "===========" << std::endl;
}