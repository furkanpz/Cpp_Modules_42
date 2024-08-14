#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : size(0), dsize(0)  {}

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
	int	err;

	std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << std::endl;
	for (int x = 0; x < this->dsize; x++)
	{
		std::cout << std::setw(10) << x << "|" << std::setw(10) << SetColumn(this->Contact[x].name)
		<< "|" << std::setw(10) << SetColumn(this->Contact[x].surname) << "|"
		<< std::setw(10) << SetColumn(this->Contact[x].username) << std::endl;
	}
	while (1)
	{
		err = 0;
		std::cout << "The index you want to view :";
		std::cin >> index;
		for (int x = 0; index[x]; x++)
		{
			if (!isdigit(index[x]))
				err = 1;
			else if (x > 1)
				err = 1;
			else if ((index[0] - '0') >= this->dsize)
				err = 1;
		}
		if (err == 1)
			std::cout << "Incorrect index!" << std::endl;
		else
			break;
	}
	index2 = index[0] - '0';
	std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << 
		"|" << std::setw(10) << "Number" << "|" << std::setw(10) << "Secret" << std::endl;
	std::cout << std::setw(10) << index2 << "|" << std::setw(10) << SetColumn(this->Contact[index2].name)
	<< std::setw(10) << SetColumn(this->Contact[index2].name)
		<< "|" << std::setw(10) << SetColumn(this->Contact[index2].surname) << "|"
		<< std::setw(10) << SetColumn(this->Contact[index2].username) << "|"
		<< std::setw(10) << SetColumn(this->Contact[index2].number) << "|"
		<< std::setw(10) << SetColumn(this->Contact[index2].darkestsecret) << std::endl;

}

void PhoneBook::Exit()
{
	exit(0);
}