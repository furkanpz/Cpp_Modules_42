#include "Span.hpp"

int main() 
{

    /* SUBJECT */
    std::cout << "SUBJET" << std::endl;
    
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "SP: Shortest Span is "<< sp.shortestSpan() << std::endl;
    std::cout << "SP: Longest Span is "<< sp.longestSpan() << std::endl;
    
    std::cout << "10000 Numbers" << std::endl;
    
    Span a(10000);
    std::srand(time(0));
    for(int i = 0; i < 10000; i++)
        a.addNumber(rand() % 16);
    std::cout << "A: Shortest Span is "<< a.shortestSpan() << std::endl;
    std::cout << "A: Longest Span is "<< a.longestSpan() << std::endl;
    
    std::cout << "Improved addNumber()" << std::endl;

    std::vector<int> b;
    b.push_back(20);
    b.push_back(3);
    b.push_back(5);
    b.push_back(6);
    try
    {
        Span x(5);
        x.addNumber(24);
        x.addNumber(b.begin(), b.end());
        std::cout << "X: Longest Span is = " << x.longestSpan() << std::endl;
        std::cout << "X: Shortest Span is = " << x.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    /* Error Checking */
    std::cout << "---------Error Checking---------" << std::endl;

    /* 1- Add Number When Full */
    std::cout <<  std::endl << "1- Add Number When Full" << std::endl;
    try
    {
        Span c(2);
        c.addNumber(42);
        c.addNumber(55);
        c.addNumber(22);

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    /* 2- Find  span for vector with elem <=1  */
    std::cout << std::endl << "2- Find Span When empty" << std::endl;
    try
    {
        Span b(20);
        b.addNumber(10);
        std::cout << "Longest Span is = " << b.longestSpan() << std::endl;
        std::cout << "Shortest Span is = " << b.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}