#pragma once

#include <string>
#include <iostream>
#include "colors.hpp"

class Bureaucrat
{
	private:
			const std::string	name;
			int					grade;

	public:
			Bureaucrat();
			Bureaucrat(int grade);
			Bureaucrat(const std::string name);
			Bureaucrat(const std::string name, int grade);
			Bureaucrat(const Bureaucrat &copy);

			Bureaucrat& operator=(const Bureaucrat &src);

			~Bureaucrat();

			void				incrementGrade();
			void				decrementGrade();

			const std::string	getName() const;
			int					getGrade() const;
			void				setGrade(int grade);

			class GradeTooLowException: public std::exception
			{
				public:
						virtual const char	*what() const throw();
			};

			class GradeTooHighException: public std::exception
			{
				public:
						virtual const char *what() const throw();
			};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat *a);
