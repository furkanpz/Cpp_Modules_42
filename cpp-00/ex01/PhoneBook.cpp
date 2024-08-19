#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->size = 0;
	this->dsize = 0;
}

void PhoneBook::Add()
{
	long long number0;
	std::string name;
	std::string surname;
	std::string username;
	std::string number;
	std::string secret;
	int err;

	if (this->size == 8)
		this->size = 0;
	if (this->dsize != 8)
		this->dsize++;
	while (1)
	{
		std::cout << "Name :";
		std::getline(std::cin, name);
		if (std::cin.eof())
			std::exit(0);
		std::cout << "Surname :";
		std::getline(std::cin, surname);
		if (std::cin.eof())
			std::exit(0);
		std::cout << "Username :";
		std::getline(std::cin, username);
		if (std::cin.eof())
			std::exit(0);
		while (1)
		{
			err = 0;
			std::cout << "Phone Number :";
			std::getline(std::cin, number);
			if (std::cin.eof())
				std::exit(0);
			for (int x = 0; number[x]; x++)
			{
				if (!std::isdigit(number[x]))
				{
					std::cout << "Please number only!" << std::endl;
					err = 1;
					break;
				}
			}
			if (err == 1)
				continue;
			try {
				number0 = std::stoll(number);
			}
			catch (std::invalid_argument)
			{
				std::cout << "Please number only!" << std::endl;
				continue;
			}
			break;
		}
		std::cout << "Darkest Secret :";
		std::getline(std::cin, secret);
		if (std::cin.eof())
			std::exit(0);
		if (name.empty() || surname.empty() || username.empty() || secret.empty())
		{
			std::cout << "Error: Input cannot be empty. Please enter a valid value." << std::endl;
			continue;
		}
		break;
	}
	PhoneBook::Contact[this->size].setName(name);
	PhoneBook::Contact[this->size].setSurname(surname);
	PhoneBook::Contact[this->size].setUsername(username);
	PhoneBook::Contact[this->size].setNumber(number0);
	PhoneBook::Contact[this->size].setSecret(secret);
	this->size++;
}
std::string PhoneBook::SetColumn(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + '.';
	return (str);
}
void PhoneBook::Search()
{
	std::string index;
	int index2;

	if (this->dsize == 0)	
	{	
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << std::endl;
	for (int x = 0; x < this->dsize; x++)
	{
		std::cout << std::setw(10) << x << "|" << std::setw(10) << SetColumn(this->Contact[x].getName())
		<< "|" << std::setw(10) << SetColumn(this->Contact[x].getSurname()) << "|"
		<< std::setw(10) << SetColumn(this->Contact[x].getUsername()) << std::endl;
	}
	while (1)
	{
		std::cout << "The index you want to view :";
		std::getline(std::cin, index);
		std::cout << std::endl;
		if (std::cin.eof())
			std::exit(0);
		if (index.length() > 1)
		{
			std::cout << "Please number Only!" << std::endl;
			continue;
		}
		try {
			index2 = std::stoi(index);
		}
		catch (std::invalid_argument)
		{
			std::cout << "Please number Only!" << std::endl;
			continue;
		}
		if (index2 >= this->dsize)
		{
			std::cout << "Please number Only!" << std::endl;
			continue;
		}
		break;
	}
		std::cout << std::endl<< "Index :" << index2 << std::endl << "Name :" << this->Contact[index2].getName()
			<< std::endl << "Surname :" << this->Contact[index2].getSurname()
			<< std::endl << "Username :" << this->Contact[index2].getUsername()
			<< std::endl << "Number :" << this->Contact[index2].getNumber()
			<< std::endl << "Secret :" << this->Contact[index2].getSecret() << std::endl;
		std::cout << std::endl;
}

void PhoneBook::Exit()
{
	std::exit(0);
}