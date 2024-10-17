#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): name("Unnamed"), grade(150)
{
	std::cout << "Bureaucrat Default Constructor Called!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
	try
	{
		if (getGrade() < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (getGrade() > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		e.what();
		this->grade = 150;
		std::cout << "Bureaucrat " << getName() << " is now set to default grade : 150" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		e.what();
		this->grade = 150;
		std::cout << "Bureaucrat " << getName() << " is now set to default grade : 150" << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Default Destructor Called!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.getName())
{
	std::cout << "Bureaucrat Copy Constructor Called!" << std::endl;
	if (this != &other)
		*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat Copy Assigment Constructor Called!" << std::endl;
	if (this != &other)
		this->grade = other.getGrade();
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

void Bureaucrat::signForm(Form &f)
{
	if (this->grade > f.getSignGrade())
	{	
		std::cout << this->getName() << " couldn’t sign " << f.getName() 
		<< " because " << "Bureaucrat grade too low to sign!" << std::endl;
		return ;
	}
	else if (f.getSign() == true)
	{
		std::cout << this->getName() << " couldn’t sign " << f.getName() 
		<< " because " << "Already signed!" << std::endl;
		return ;
	}
	else
	{
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
		f.setSign();
	}
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low!");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High!");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &br)
{
	out << br.getName() << ", bureaucrat grade " << br.getGrade();
	return out; 
}
