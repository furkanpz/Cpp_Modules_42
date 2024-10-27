#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

class Span{
	private:
		unsigned int		N;
		std::vector<int>	vec;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span& operator = (const Span &other);
		~Span();
	
	public:
		void	addNumber(std::vector<int>::iterator, std::vector<int>::iterator);
		void addNumber(int nbr);
		int shortestSpan();
        int longestSpan();
		int getN() const;
		std::vector<int> getVector() const;

		class SpanMaxRange: public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class SpanLowRange: public std::exception {
			public:
				virtual const char *what() const throw();
		};
};


#endif
