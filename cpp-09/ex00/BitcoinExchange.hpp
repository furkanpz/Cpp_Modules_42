#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP


#include <map>
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>	
#include <sstream>


class BitcoinExchange {
	private:
		std::map<std::string, double> data;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator = (const BitcoinExchange &other);
	public:
		std::map<std::string, double> getData() const;
		void retData(std::string &date, double val);
		void readData(std::string &date, double val);
		std::time_t convertToTimestamp(const std::string& dateStr);
		class DataException: public std::exception {
			virtual const char *what() const throw();
		}
};



#endif