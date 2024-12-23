#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm(): name("Unnamed"), exGrade(150), signGrade(150), sign(false)
{
	std::cout << "AForm Default Constructor Called!" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm Destructor Called!" << std::endl;
}

AForm::AForm(const AForm &other) : name(other.getName()),
exGrade(other.getExGrade()), signGrade(other.getSignGrade()), sign(other.getSign())
{
	if (signGrade > 150 || exGrade > 150)
		throw AForm::GradeTooLowException();
	else if (signGrade < 1 || exGrade < 1)
		throw AForm::GradeTooHighException();
	std::cout << "AForm Constructor Called!" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "AForm Copy Assigment Constructor Called!" << std::endl;
	if (this != &other)
		*this = other;
	return (*this);
}

AForm::AForm(const std::string &name, const int &signGrade, const int &exGrade): name(name),
sign(false), signGrade(signGrade), exGrade(exGrade)
{
	if (signGrade > 150 || exGrade > 150)
		throw AForm::GradeTooLowException();
	else if (signGrade < 1 || exGrade < 1)
		throw AForm::GradeTooHighException();
	std::cout << "AForm Constructor called!" << std::endl;
}

int AForm::getExGrade() const
{
	return (this->exGrade);
}

int AForm::getSignGrade() const
{
	return (this->signGrade);
}

std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getSign() const
{
	return (this->sign);
}

void AForm::beSigned(Bureaucrat & br)
{
	br.signForm(*this);
}

void AForm::setSign()
{
	this->sign = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade Too High!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low!");
}

std::ostream & operator<<(std::ostream & out, const AForm & br)
{
	out << "Name: " << br.getName() << ", Signed: " << br.getSign()
	<< ", SignGrade: " << br.getSignGrade() << ", ExecuteGrade: " << br.getExGrade();
	return (out);
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form Not Signed!");
}