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
		void Exit();
		int size;
		int dsize;
		PhoneBook();
	private:
		std::string SetColumn(std::string str);
};