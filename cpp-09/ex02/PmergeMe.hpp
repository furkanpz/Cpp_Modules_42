#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>
#include <deque>
extern int comparaisons;
class PmergeMe
{
	public:
		PmergeMe(std::string input);
		void parseString();
		
		void forwardRecursionVector();
		void unpairVector();
		void backwardsRecursionVector(std::vector<int> remain);
		void marrySinglesVector();
		void jacobSthalInsertionVector(std::vector<std::vector<int> >& mainChain, std::vector< std::vector<int> >& pend);

		void forwardRecursionDeque();
		void unpairDeque();
		void backwardsRecursionDeque(std::deque<int> remain);
		void marrySinglesDeque();
		void jacobSthalInsertionDeque(std::deque<std::deque<int> >& mainChain, std::deque< std::deque<int> >& pend);
		
		std::vector< std::vector<int> > getNumbers() const;
		std::deque< std::deque<int> > getDeque() const;
		std::string getInput() const;
		~PmergeMe();
	private:
		std::string input;
		std::vector< std::vector<int> > numbers;
		std::deque<std::deque<int> > myDeque;
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
};

std::string concat(char **args);
void printContainer(std::vector<std::vector<int> > container);

#endif
