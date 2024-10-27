#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>

class Span{
	private:
		unsigned int N;
	
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span& operator = (const Span &other);
		~Span();
	
	public:
		void addNumber();
		

}


#endif
