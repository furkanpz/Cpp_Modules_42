#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form(): name("Unnamed"), exGrade(150), signGrade(150), sign(false)
{
	std::cout << "Form Default Constructor Called!" << std::endl;
}

Form::~Form()
{
	std::cout << "Form Destructor Called!" << std::endl;
}

Form::Form(const Form &other) : name(other.getName()),
exGrade(other.getExGrade()), signGrade(other.getSignGrade()), sign(other.getSign())
{
	if (signGrade > 150 || exGrade > 150)
		throw Form::GradeTooLowException();
	else if (signGrade < 1 || exGrade < 1)
		throw Form::GradeTooHighException();
	std::cout << "Form Constructor Called!" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Form Copy Assigment Constructor Called!" << std::endl;
	if (this != &other)
		*this = other;
	return (*this);
}

Form::Form(const std::string &name, const int &signGrade, const int &exGrade): name(name),
sign(false), signGrade(signGrade), exGrade(exGrade)
{
	if (signGrade > 150 || exGrade > 150)
		throw Form::GradeTooLowException();
	else if (signGrade < 1 || exGrade < 1)
		throw Form::GradeTooHighException();
	std::cout << "Form Constructor called!" << std::endl;
}

int Form::getExGrade() const
{
	return (this->exGrade);
}

int Form::getSignGrade() const
{
	return (this->signGrade);
}

std::string Form::getName() const
{
	return (this->name);
}

bool Form::getSign() const
{
	return (this->sign);
}

void Form::beSigned(Bureaucrat & br)
{
	br.signForm(*this);
}

void Form::setSign()
{
	this->sign = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade Too High!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low!");
}

std::ostream & operator<<(std::ostream & out, const Form & br)
{
	out << "Name: " << br.getName() << ", Signed: " << br.getSign()
	<< ", SignGrade: " << br.getSignGrade() << ", ExecuteGrade: " << br.getExGrade();
	return (out);
}
