#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int n) : N(n) {}

Span::Span(const Span &other)
{
	if (this != &other)
		*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->N = other.getN();
		this->vec = other.getVector();
	}
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int nbr)
{
	if (vec.size() >= this->N)
		throw SpanMaxRange();
	vec.push_back(nbr);
}

int Span::shortestSpan()
{
{
		if (vec.size() < 2)
			throw SpanLowRange();
		std::vector<int> sortedNumbers = vec;
		std::sort(sortedNumbers.begin(), sortedNumbers.end());

		int shortest = std::numeric_limits<int>::max();
		for (size_t i = 1; i < sortedNumbers.size(); ++i) {
			int span = sortedNumbers[i] - sortedNumbers[i - 1];
			if (span < shortest) {
				shortest = span;
			}
		}
		return shortest;
	}
}
void	Span::addNumber(std::vector<int>::iterator bg, std::vector<int>::iterator en)
{
	if(static_cast<size_t> (en - bg) > (this->N - this->vec.size()))
		throw SpanMaxRange();
	for(std::vector<int>::iterator start = bg; start != en; start++)
		vec.push_back(*start);
}

int Span::longestSpan()
{
	if (vec.size() < 2)
		throw SpanLowRange();
	std::vector<int> sortedNumbers = vec;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	return (sortedNumbers[sortedNumbers.size() - 1] - sortedNumbers[0]);
}

int Span::getN() const
{
	return (this->N);
}

std::vector<int> Span::getVector() const
{
	return (this->vec);
}

const char *Span::SpanMaxRange::what() const throw()
{
	return ("You can't add more numbers!");
}
const char *Span::SpanLowRange::what() const throw()
{
	return ("Not enough numbers to find a span");
}
