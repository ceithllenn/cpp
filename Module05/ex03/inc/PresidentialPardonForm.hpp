#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class AForm;

class PresidentialPardonForm: public AForm
{
	private:
			const std::string target;
			PresidentialPardonForm();

	public:
			PresidentialPardonForm(std::string target);
			PresidentialPardonForm(PresidentialPardonForm &copy);

			PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

			~PresidentialPardonForm();

			std::string	getTarget() const;

			void		execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm *f);
