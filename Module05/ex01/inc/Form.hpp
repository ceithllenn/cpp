#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
			const std::string	name;
			bool				isSigned;
			const int			toSign;
			const int			toEx;

	public:
			Form();
			Form(std::string name);
			Form(std::string name, int toSign, int toEx);
			Form(int toSign, int toEx);
			Form(const Form &copy);

			Form& operator=(const Form &src);

			~Form();

			void				beSigned(const Bureaucrat &b);

			const std::string	getName() const;
			bool				getSignStatus() const;
			int					getToSign() const;
			int					getToEx() const;

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
};

std::ostream &operator<<(std::ostream &o, Form *f);