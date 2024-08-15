#pragma once

#include "Contact.hpp"

class PhoneBook {
	public:
		Contact Contact[8];

		void Add();
		void Search();
		void Exit();
		int size;
		int dsize;
		PhoneBook();
	private:
		std::string SetColumn(std::string str);
};