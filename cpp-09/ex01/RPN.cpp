#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) {*this = other;}

RPN &RPN::operator=(const RPN &other) {return *this;}

void RPN::RpnConvert(std::string &rpnstr)
{
    std::stack<int> stack;
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
                int operand2 = stack.top(); stack.pop();
                int operand1 = stack.top(); stack.pop();
                int result = applyOperator(operand1, operand2, token[0]);
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
        std::cout << stack.top();
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

int RPN::applyOperator(int operand1, int operand2, char op) const {
        switch (op) {
            case '+': return operand1 + operand2;
            case '-': return operand1 - operand2;
            case '*': return operand1 * operand2;
            case '/':
                if (operand2 == 0) throw std::runtime_error("Hata: Sıfıra bölme.");
                return operand1 / operand2;
            default:
                throw std::runtime_error("Geçersiz operatör.");
        }
}