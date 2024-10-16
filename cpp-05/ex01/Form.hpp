#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	
	private:
		const std::string name;
		bool sign;
		const int signGrade;
		const int exGrade;

	public:
		Form();
		~Form();
		Form(const Form &other);
		Form& operator=(const Form &other);
		Form(const std::string &name,\
			const int &signGrade, const int &exGrade);
	public:
		int			getExGrade() const;
		int			getSignGrade() const;
		std::string	getName() const;
		bool		getSign() const;
		void		beSigned(Bureaucrat &br);
		void		setSign();

	public:
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

};

std::ostream & operator<<(std::ostream & out, const Form & br);
#endif
