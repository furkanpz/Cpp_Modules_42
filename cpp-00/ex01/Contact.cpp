#include "Contact.hpp"

void Contact::setName(std::string name)
{
    this->name = name;
}

void Contact::setSurname(std::string surname)
{
    this->surname = surname;
}

void Contact::setUsername(std::string username)
{
    this->username = username;
}

void Contact::setNumber(long long number)
{
    this->number = number;
}

void Contact::setSecret(std::string darkestsecret)
{
    this->darkestsecret = darkestsecret;
}

std::string Contact::getName()
{
    return (this->name);
}

std::string Contact::getSurname()
{
    return (this->surname);
}

std::string Contact::getUsername()
{
    return (this->username);
}

long long Contact::getNumber()
{
    return (this->number);
}

std::string Contact::getSecret()
{
    return (this->darkestsecret);
}