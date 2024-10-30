#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
	private:
		std::map<std::string, double> data;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const std::string &file);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator = (const BitcoinExchange &other);
	public:
	

};



#endif