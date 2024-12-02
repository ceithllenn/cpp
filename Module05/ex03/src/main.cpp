#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	AForm		*tmp = NULL;
	Bureaucrat	*bob = new Bureaucrat("Bob", 1);
	Intern		*i = new Intern();

	std::cout << std::endl;
	try
	{
		tmp = i->makeForm("RandomForm", "randomTarget");
	}
	catch (Intern::NoSuchFormException &e)
	{
		std::cerr << REDD << e.what() << "RandomForm" << RST << std::endl;
	}
	if (tmp)
	{
		bob->signForm(*tmp);
		bob->executeForm(*tmp);
		delete tmp;
		tmp = NULL;
	}
	std::cout << std::endl;

	try
	{
		tmp = i->makeForm("PresidentialPardonForm", "random guy");
	}
	catch (Intern::NoSuchFormException &e)
	{
		std::cerr << REDD << e.what() << "PresidentialPardonForm" << RST << std::endl;
	}
	if (tmp)
	{
		bob->signForm(*tmp);
		bob->executeForm(*tmp);
		delete tmp;
		tmp = NULL;
	}
	std::cout << std::endl;

	try
	{
		tmp = i->makeForm("RobotomyRequestForm", "random guy");
	}
	catch (Intern::NoSuchFormException &e)
	{
		std::cerr << REDD << e.what() << "RobotomyRequestForm" << RST << std::endl;
	}
	if (tmp)
	{
		bob->signForm(*tmp);
		bob->executeForm(*tmp);
		bob->executeForm(*tmp);
		delete tmp;
		tmp = NULL;
	}
	std::cout << std::endl;

	try
	{
		tmp = i->makeForm("ShrubberyCreationForm", "test");
	}
	catch (Intern::NoSuchFormException &e)
	{
		std::cerr << REDD << e.what() << "ShrubberyCreationForm" << RST << std::endl;
	}
	if (tmp)
	{
		bob->signForm(*tmp);
		bob->executeForm(*tmp);
		delete tmp;
		tmp = NULL;
	}
	std::cout << std::endl;

	delete bob;
	delete i;

	return (0);
}


