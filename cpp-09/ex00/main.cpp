#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	bool ColumnCheck = false;
	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	std::ifstream file(av[1]);
	if (file.fail())
	{
		std::cout << "Error: could not open file: " << av[1] << std::endl;
		return 1; 
	}
	std::string line;
	std::getline(file, line);
	if (!ColumnCheck)
	{
		if (((line.find('|') != std::string::npos) 
		&& line.substr(0, line.find('|') - 1) == "date")
		&& (line.find('|') != std::string::npos)
			&& line.substr(line.find('|') + 2) == "value")
			ColumnCheck = true;
	}
	if (!ColumnCheck)
	{
		std::cout << "Each line in this file must use the following format: 'date | value'" << std::endl;
		return 1; 
	}
	BitcoinExchange BTC;
	double value;
	std::string temp;
	const char *s;
	int x = 0;
	while (std::getline(file, line))
	{
		if (line.find('|') == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		else
		{
			try {
				s = line.substr(line.find('|') + 1).c_str();
				for (x = 0; s[x]; x++)
				{
					if (!std::isdigit(s[x]) && !(s[x] == 32 || (s[x] >= '\t' && s[x] <= '\r')))
						break;
				}
				if (s[x] && !std::isdigit(s[x]))
					{
						std::cout << "Error: bad input => " << line << std::endl;
						continue;
					}
				value = std::strtod(s, NULL);
				if (value < 0)
				{
					std::cout << "Error: not a positive number." << std::endl;
					continue;
				}
			}
			catch (std::exception &e)
			{
				std::cout << "Error: bad input => " << line << std::endl;
				continue;
			}
			temp = line.substr(0, line.find('|'));
			BTC.retData(temp, value);
		}
	}
}