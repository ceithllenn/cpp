#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main(void)
{
	{
		Bureaucrat *a = new Bureaucrat();
		AForm *b = new PresidentialPardonForm("default");
		std::cout << std::endl;

		std::cout << a;
		std::cout << b;
		std::cout << std::endl;

		try
		{
			b->beSigned(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << REDD << a->getName() << " was not able to sign " << b->getName() << ": " << e.what() << RST << std::endl;
		}

		std::cout << std::endl;
		std::cout << b;
		delete a;
		delete b;
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		Bureaucrat *a = new Bureaucrat("Assistant", 145);
		Bureaucrat *b = new Bureaucrat("CEO", 1);
		AForm *c = new PresidentialPardonForm("some dude");
		std::cout << std::endl;

		std::cout << a;
		std::cout << b;
		std::cout << c;
		std::cout << std::endl;

		try
		{
			c->execute(*b);
		}
		catch (AForm::FormNotSignedException &e)
		{
			std::cerr << REDD << a->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << RST << std::endl;
		}
		std::cout << std::endl;
		try
		{
			c->beSigned(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << REDD << a->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << RST << std::endl;
		}
		std::cout << std::endl;
		std::cout << c;
		try
		{
			c->beSigned(*b);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << REDD << b->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << RST << std::endl;
		}
		std::cout << std::endl;
		std::cout << c;
		b->signForm(*c);

		try
		{
			c->execute(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << REDD << a->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << RST << std::endl;
		}
		std::cout << std::endl;
		try
		{
			c->execute(*b);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << REDD << b->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << RST << std::endl;
		}
		std::cout << std::endl;

		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;
		Bureaucrat *a = new Bureaucrat("Emperor", 1);
		PresidentialPardonForm *b = new PresidentialPardonForm("this other dude");
		PresidentialPardonForm *c = new PresidentialPardonForm(*b);
		std::cout << std::endl;

		std::cout << a;
		std::cout << b;
		std::cout << c;
		std::cout << std::endl;
		b->beSigned(*a);
		a->signForm(*c);
		b->execute(*a);
		a->executeForm(*c);
		std::cout << std::endl;

		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	{
		std::cout << std::endl;

		Bureaucrat *a = new Bureaucrat("Emperor", 1);
		RobotomyRequestForm *b = new RobotomyRequestForm("Bender");
		ShrubberyCreationForm *c = new ShrubberyCreationForm("christmas");
		std::cout << std::endl;

		std::cout << a;
		std::cout << b;
		std::cout << c;
		std::cout << std::endl;

		b->beSigned(*a);
		a->signForm(*c);
		for (int i= 0; i < 10; i++)
			b->execute(*a);
		c->execute(*a);
		std::cout << std::endl;

		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	return (0);
}