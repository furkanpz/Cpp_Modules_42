#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>

class RPN {
	public:
		RPN();
		~RPN();
		RPN(const RPN &other);
		RPN& operator = (const RPN &other);
	public:
		void RpnConvert(std::string &rpnstr);
	private:
    	std::stack<double> stack;
		bool isNumber(const std::string& s) const ;
		bool isOperator(const std::string& s) const ;
};


#endif
