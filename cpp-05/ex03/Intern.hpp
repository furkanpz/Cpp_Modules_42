#ifndef INTERN_HPP
# define INTERN_HPP


#include "AForm.hpp"


class AForm;


class Intern {

public:
	Intern();
	Intern(Intern const & src);
	~Intern();
	Intern & operator=(Intern const & src);
	AForm *makeForm(std::string name, std::string target);
public:
    class EmptyTargetException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
    class NoFormException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
};


#endif