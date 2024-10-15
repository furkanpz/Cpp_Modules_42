#ifndef SCF_HPP
# define SCF_HPP


#include "AForm.hpp"


class Intern {
public:
	Intern();
	Intern(Intern const & src);
	~Intern();
	Intern & operator=(Intern const & src);
	AForm *makeForm(std::string name, std::string target);
};


#endif