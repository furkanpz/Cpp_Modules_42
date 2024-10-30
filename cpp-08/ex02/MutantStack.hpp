#ifndef MS_HPP
# define MS_HPP

#include <stack>
#include <deque>

template <typename T, class container = std::deque<T> >
class MutantStack : public std::stack<T, container>
{
	public:
		MutantStack() {}
		MutantStack(const MutantStack &other) {
			if (this != &other)
				*this = other;
		}
		~MutantStack() {}

	public:
		MutantStack &operator = (const MutantStack &other) {
			std::stack<T, container>::operator=(other);
			return (*this);
		}
	public:
        typedef typename container::iterator iterator;
        typedef typename container::const_iterator const_iterator;
        typedef typename container::reverse_iterator reverse_iterator;
        typedef typename container::const_reverse_iterator const_reverse_iterator;
	public:
	    iterator begin() {return this->c.begin();}
        iterator end() {return this->c.end();}

        const_iterator cbegin() const {return this->c.cbegin();}
        const_iterator cend() const {return this->c.cend();}

        reverse_iterator rbegin() {return this->c.rbegin();}
        reverse_iterator rend() {return this->c.rend();}

        const_reverse_iterator crbegin() const {return this->c.crbegin();}
        const_reverse_iterator crend() const {return this->c.crend();}
};

#endif