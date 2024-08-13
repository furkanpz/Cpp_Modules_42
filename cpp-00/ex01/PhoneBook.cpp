#include "PhoneBook.hpp"

void PhoneBook::Add()
{
	int err;
	
	if (this->size == 8)
		this->size = 0;
	if (this->dsize != 8)
		this->dsize++;
	std::cout << "Name :";
	std::cin >> this->Contact[this->size].name;
	std::cout << "Surname :";
	std::cin >> this->Contact[this->size].surname;
	std::cout << "Username :";
	std::cin >> this->Contact[this->size].username;
	for (int a = 0; a != 1;)
	{
		err = 0;
		std::cout << "Phone Number :";
		std::cin >> this->Contact[this->size].number;
		for (int x = 0; this->Contact[this->size].number[x]; x++)
		{
			if (!isdigit(this->Contact[this->size].number[x]))
				err = 1;
		}
		if (err == 1)
			std::cout << "Please Number Only!" << std::endl;
		else
			a = 1;
	}
	std::cout << "Darkest Secret :";
	std::cin >> this->Contact[this->size].darkestsecret;
	this->size++;
}

void PhoneBook::Search()
{
        std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|"
                  << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << std::endl;

        for (size_t i = 0; i < Contact.size(); ++i) {
            std::cout << formatColumn(std::to_string(i)) << "|"
                      << formatColumn(contacts[i].firstName) << "|"
                      << formatColumn(contacts[i].lastName) << "|"
                      << formatColumn(contacts[i].nickname) << std::endl;
        }
    }
}