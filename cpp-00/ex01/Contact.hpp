#pragma once

#include <iostream>
#include <string>
#include <iomanip>


class Contact {
    private:
        std::string name;
		std::string surname;
		std::string username;
	    long long number;
		std::string darkestsecret;
	public:
        void setName(std::string name);
        void setSurname(std::string surname);
        void setUsername(std::string username);
        void setNumber(long long number);
        void setSecret(std::string darkestsecret);
        std::string getName();
        std::string getSurname();
        std::string getUsername();
        long long getNumber();
        std::string getSecret();
        
};