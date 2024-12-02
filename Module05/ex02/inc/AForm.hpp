#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
			const std::string	name;
			bool				isSigned;
			const int			toSign;
			const int			toEx;

	public:
			AForm();
			AForm(std::string name);
			AForm(std::string name, int toSign, int toEx);
			AForm(int toSign, int toEx);
			AForm(const AForm &copy);

			AForm& operator=(const AForm &src);

			virtual ~AForm();

			void				beSigned(const Bureaucrat &b);
			virtual void		execute(const Bureaucrat &b) const = 0;

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

		class FormNotSignedException: public std::exception
		{
			public:
					virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, AForm *f);