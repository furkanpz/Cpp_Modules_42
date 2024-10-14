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
		Form(const std::string &name, const bool &sign,\
			const int &signGrade, const int &exGrade);
	public:
		int			GetExGrade() const;
		int			GetSignGrade() const;
		std::string	GetName() const;
		bool		GetSign() const;
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


#endif
