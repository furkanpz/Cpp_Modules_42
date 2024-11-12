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
	int a = 0;

	if (timeStamp == -1)
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return ;
	}
	if (val >= 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return ;
	}
	for (std::map<std::string, double>::iterator it = data.begin(); it != data.end(); it++)
	{
		temp2 = convertToTimestamp(it->first) - timeStamp;
		if (temp2 < 0)
		{
			temp2 *= -1;
			a = 1;
		}
		if (temp > temp2 && (a == 1 || temp2 < 86400))
		{
			temp = temp2;
			last = it->second;
			a = 0;
		}
	}
	std::cout << date << " => " << val << " = " << last * val << std::endl;
}
std::time_t BitcoinExchange::convertToTimestamp(const std::string& dateStr) {
	std::tm tm = {};
	std::istringstream ss(dateStr);
	std::time_t ret;
	std::string empty;

	std::string a;
	for (size_t i = 0, b = 0; i < dateStr.length(); i++)
	{
		if (dateStr[i] == '-')
			b++;
		if (b > 2)
			return -1;
	}
	ss >> std::setw(4) >> tm.tm_year;
	ss >> std::setw(1) >> empty;
    ss >> std::setw(2) >> tm.tm_mon;
	ss >> std::setw(1) >> empty;
    ss >> std::setw(2) >> tm.tm_mday;
	if (ss.fail())
		return (-1);
	tm.tm_year -= 1900;
	tm.tm_mon -= 1;
	ss >> a;
	if (a.length() != 0)
		return (-1);
	ret = std::mktime(&tm);
	try {
		std::tm* timeInfo = std::localtime(&ret);
		char BUF[11];
		BUF[10] = '\0';
		std::strftime(BUF, sizeof(BUF), "%Y-%m-%d", timeInfo);
		if (dateStr.compare(std::string(BUF)) == -1)
			return (-1);
	}
	catch (std::exception &e)
	{
		return -1;
	}
	if (1230847200 > ret || 1735678800 <= ret)
		return (-1);
	return ret;
}

const char *BitcoinExchange::DataException::what() const throw()
{
	return "Data.csv Not Found!";
}
