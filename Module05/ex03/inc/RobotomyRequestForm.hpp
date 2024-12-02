#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class AForm;

#define DRILLING_NOISE "BZZZZZZZZZZZZZZZZZZZZZZZZZ\nGRRRRRRRRRRRRRRRRRRRRRRRRR\nBRRRRRRRRRRT! BRRRRRRRRT!\nCHUNK CHUNK CHUNK!\nWHIIIIIIIIIIIIIIIRRRRRRRRRRRRRRR!\n"
class RobotomyRequestForm: public AForm
{
	private:
			const std::string target;
			RobotomyRequestForm();

	public:
			RobotomyRequestForm(std::string target);
			RobotomyRequestForm(RobotomyRequestForm &copy);

			RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

			~RobotomyRequestForm();

			std::string	getTarget() const;

			void		execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm *f);