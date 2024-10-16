#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("default"){}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src): AForm(src), _target(src._target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src){
	if (this != &src)
	{
		_target = src.getTarget();
	}
	return *this;
}

std::string RobotomyRequestForm::getTarget() const{
	return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{

	if (executor.getGrade() > getExGrade())
		throw AForm::GradeTooLowException();
	if (!getSign())
		throw AForm::FormNotSignedException();
	std::cout << "Drilling noises" << std::endl;
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << _target << " robotomization failed" << std::endl;
}