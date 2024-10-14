#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat {

	private:
		const	std::string name;
		int		grade;
	
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator = (const Bureaucrat &other);
		std::string getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(Form &f);
	public:
		class GradeTooLowException: public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
		class GradeTooHighException: public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
}  ;

std::ostream &operator <<(std::ostream &out, const Bureaucrat &br);



#endif
