#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm{

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const & src);
	~PresidentialPardonForm();
	PresidentialPardonForm & operator=(PresidentialPardonForm const & src);
	std::string getTarget() const;
	void execute(Bureaucrat const & executor) const;

private:
	std::string _target;
};


#endif