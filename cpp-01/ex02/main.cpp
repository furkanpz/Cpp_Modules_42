#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Str Adress :" << &str << std::endl 
	<< "stringPTR Adress :" << &*stringPTR << std::endl
	<< "stringREF Adress :" << &stringREF << std::endl;
	std::cout << "Str Value :" << str << std::endl 
	<< "stringPTR Value :" << *stringPTR << std::endl
	<< "stringREF Value :" << stringREF << std::endl;
}