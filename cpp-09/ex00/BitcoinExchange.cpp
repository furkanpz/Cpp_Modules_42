#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream _data("data.csv");
	if (_data.fail())
		throw DataException();
	std::string line;
	std::getline(_data, line);
	while (std::getline(_data, line))
		this->data[line.substr(0, 10)] = std::strtod(line.substr(11, line.length()).c_str(), NULL);
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	if (this != &other)
		*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		this->data = getData();
	return (*this);
}

std::map<std::string, double> BitcoinExchange::getData() const
{
	return (this->data);
}

void BitcoinExchange::retData(std::string &date, double val)
{
	std::time_t timeStamp = convertToTimestamp(date);
	std::time_t temp = LONG_MAX;
	std::time_t temp2 = 0;
	double last = 0;

	if (timeStamp == -1)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return ;
	}
	if (val >= INT_MAX)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return ;
	}
	for (std::map<std::string, double>::iterator it = data.begin(); it != data.end(); it++)
	{
		temp2 = convertToTimestamp(it->first) - timeStamp;
		if (temp2 < 0)
			temp2 *= -1;
		if (temp > temp2)
		{
			temp = temp2;
			last = it->second;
		}
	}
	std::cout << date << " => " << val << " = " << last * val;
}
std::time_t BitcoinExchange::convertToTimestamp(const std::string& dateStr) {
	std::tm tm = {};
	std::istringstream ss(dateStr);
	std::time_t ret;

	ss >> std::get_time(&tm, "%Y-%m-%d");
	
	if (ss.fail())
		return (-1);
	ret = mktime(&tm);
	if (1230847200 > ret || 1735678800 <= ret)
		return (-1);
	return ret;
}

const char *BitcoinExchange::DataException::what() const throw()
{
	return "Data.csv Not Found!";
}
