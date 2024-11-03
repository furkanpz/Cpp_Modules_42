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
    	std::stack<int> operands;
		bool isNumber(const std::string& s) const ;
		bool isOperator(const std::string& s) const ;
		int applyOperator(int operand1, int operand2, char op) const;
};

#endif