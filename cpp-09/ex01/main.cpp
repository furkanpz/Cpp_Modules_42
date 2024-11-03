#include "RPN.hpp"


int main(int ac, char **av) {
    if (ac != 2)
    {
        std::cout << "Usage: ./RPN \"RPN\"";
        return 1;
    }
    RPN calculator;
    std::string rpnstr(av[1]);
    calculator.RpnConvert(rpnstr);
    return 0;
}