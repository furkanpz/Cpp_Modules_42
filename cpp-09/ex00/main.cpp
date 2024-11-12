#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange BTC;
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
	if (!ColumnCheck && !line.empty())
	{
		std::cout << "Error: Each line in this file must use the following format: 'date | value'" << std::endl;
		return 1;
	}
	if (line.empty())
	{
		std::getline(file, line);
		if (line.empty())
		{
			std::cout << "Error: This File Empty!" << std::endl;
			return 1;
		}
		else if (!ColumnCheck)
		{
			std::cout << "Error: Each line in this file must use the following format: 'date | value'" << std::endl;
			return 1;
		}
	}
	double value;
	std::string temp;
	const char *s;
	int x = 0, sep = 0, neg = 0, val = 0;
	while (std::getline(file, line))
	{
		sep = 0, neg = 0, val = 0;
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
					if (s[x] == '-' && ++x)
						neg++;
					if (s[x] == '.' && ++x)
						sep++;
					if (std::isdigit(s[x]))
						val++;
					if (!std::isdigit(s[x]) && (!(s[x] == 32 || (s[x] >= '\t' && s[x] <= '\r'))
					|| (sep > 1 || neg > 1)))
						break;
				}
				if ((s[x] && (!std::isdigit(s[x]) && (s[x] != 32 || !(s[x] >= '\t' && s[x] <= '\r')))) \
					|| (sep > 1 || neg > 1) || val == 0)
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
				if (value == 0)
				{
					std::cout << "Error: Enter a value between 0 and 1000" << std::endl;
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