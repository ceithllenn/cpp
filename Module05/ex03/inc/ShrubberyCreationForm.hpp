#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

class AForm;

class ShrubberyCreationForm: public AForm
{
	private:
			const std::string target;
			ShrubberyCreationForm();

	public:
			ShrubberyCreationForm(std::string target);
			ShrubberyCreationForm(ShrubberyCreationForm &copy);

			ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

			~ShrubberyCreationForm();

			std::string	getTarget() const;

			void		execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm *f);