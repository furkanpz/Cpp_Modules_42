#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {

private:
	const	std::string name;
	int		grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat & operator = (const Bureaucrat &other);
	std::string getName() const;
	int getGrade() const;

}  ;


#endif
