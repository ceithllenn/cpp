#include "Intern.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * Intern destructor
 */
Intern::~Intern()
{
	std::cout << BLUE << "Intern destructor called" << RST << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * Intern default constructor
 */
Intern::Intern()
{
	std::cout << BLUE << "Intern default constructor called" << RST << std::endl;
}

/*
 * Intern copy constructor
 */
Intern::Intern(const Intern &copy)
{
	std::cout << BLUE << "Intern copy constructor called" << RST << std::endl;
	*this = copy;
}

/*
 * Intern assignation operator overload
 */
Intern &Intern::operator=(const Intern &src)
{
	std::cout << BLUE << "Intern assignation operator called" << RST << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

/*
 * Static tools functions for makeForm
 */

static AForm *makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

/*
 * Creates an AForm object
 */
AForm *Intern::makeForm(const std::string formToMake, const std::string formTarget)
{
	AForm		*(*ptr[])(const std::string)	= {&makePresident, &makeRobot, &makeShrubbery};
	std::string forms[]							= {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i <= 3; i++)
	{
		if (i == 3)
			throw Intern::NoSuchFormException();
		else if (formToMake == forms[i])
		{
			std::cout << "Intern creates " << formToMake << " form" << std::endl;
			return (ptr[i](formTarget));
		}
	}
	return (NULL);
}

/**************************************************************************/
/*								EXCEPTIONS					   			  */
/**************************************************************************/

const char *Intern::NoSuchFormException::what(void) const throw()
{
	return ("Intern cannot create a form called ");
}
