#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	
	private:
		const std::string name;
		bool sign;
		const int signGrade;
		const int exGrade;

	public:
		AForm();
		virtual ~AForm();
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		AForm(const std::string &name, \
			const int &signGrade, const int &exGrade);
	public:
		int			GetExGrade() const;
		int			GetSignGrade() const;
		std::string	GetName() const;
		bool		GetSign() const;
		void		beSigned(Bureaucrat &br);
		void		setSign();
		virtual void execute(Bureaucrat const & executor) const = 0;

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
		class FormNotSignedException: public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

};

std::ostream & operator<<(std::ostream & out, const AForm & br);
#endif
