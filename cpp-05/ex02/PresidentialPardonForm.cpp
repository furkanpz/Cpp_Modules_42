#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("default"){}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src): AForm(src), _target(src.getTarget()){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src){
	if (this != &src)
	{
		_target = src.getTarget();
	}
	return *this;
}

std::string PresidentialPardonForm::getTarget() const{
	return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{

	if (executor.getGrade() > getExGrade())
		throw AForm::GradeTooLowException();
	if (!getSign())
		throw AForm::FormNotSignedException();
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}