#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) {*this = other;}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other)
		*this = other;
	return *this;
}

void RPN::RpnConvert(std::string &rpnstr)
{
		std::istringstream tokens(rpnstr);
		std::string token;

		while (tokens >> token) {
			if (isNumber(token)) {
				stack.push(std::stoi(token));
			} else if (isOperator(token)) {
				if (stack.size() < 2) {
					std::cout << "Error" << std::endl;
					return ;
				}
				double operand2 = stack.top(); stack.pop();
				double operand1 = stack.top(); stack.pop();
				double result;
				switch (token[0]) {
					case '+': result = operand1 + operand2; break;
					case '-': result = operand1 - operand2; break;
					case '*': result = operand1 * operand2; break;
					case '/':
					{	if (operand2 == 0)
						{
							std::cout <<  "Error: Division by zero" << std::endl; 
							return ;
						}
						result = operand1 / operand2;
						break;
					}
					default:
						std::cout << "Error: Invalid operator" << std::endl; return ;
				}
				stack.push(result);
			} else {
				std::cout << "Error" << std::endl;
				return ;
			}
		}
		if (stack.size() != 1) {
			std::cout << "Error" << std::endl;
			return ;
		}
		std::cout << stack.top() << std::endl;
	}

bool RPN::isNumber(const std::string& s) const {
		for (size_t i = 0; i < s.length(); ++i) {
			if (!std::isdigit(s[i])) return false;
		}
		return true;
	}

bool RPN::isOperator(const std::string& s) const {
		return s == "+" || s == "-" || s == "*" || s == "/";
}
