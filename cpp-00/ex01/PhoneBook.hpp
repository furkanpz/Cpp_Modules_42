#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	public:

		void Add();
		void Search();
		void Exit();
		PhoneBook();
	private:
		int dsize;
		int size;
		Contact Contact[8];
		std::string SetColumn(std::string str);
};

#endif