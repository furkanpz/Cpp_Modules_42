#ifndef RRF_HPP
# define RRF_HPP

#include  "AForm.hpp"


class RobotomyRequestForm: public AForm{

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const & src);
	~RobotomyRequestForm();
	RobotomyRequestForm & operator=(RobotomyRequestForm const & src);
	std::string getTarget() const;
	void execute(Bureaucrat const & executor) const;
private:
	std::string _target;

};


#endif