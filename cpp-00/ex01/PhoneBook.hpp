#pragma once

#include <iostream>
#include <string>
#include <readline/readline.h>
#include <readline/history.h>
#include <iomanip>

class Contact {
	public:
		std::string name;
		std::string surname;
		std::string username;
		std::string number;
		std::string darkestsecret;
};

class PhoneBook {
	public:
		Contact Contact[8];
		void Add();
		void Search();
		int size;
		int dsize;
		PhoneBook() : size(0), dsize(0) {}

};