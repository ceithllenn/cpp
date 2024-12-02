#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:

	public:
			Intern();
			Intern(const Intern &copy);

			Intern &operator=(const Intern &src);

			~Intern();

			AForm	*makeForm(const std::string form, const std::string target);

			class NoSuchFormException: public std::exception
			{
				public:
						virtual const char *what() const throw();
			};
};
