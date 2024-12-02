#include "Bureaucrat.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * Bureaucrat destructor
 */
Bureaucrat::~Bureaucrat()
{
	std::cout << YLLW << "Bureaucrat destructor was called" << RST << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * Bureaucrat default constructor
 */
Bureaucrat::Bureaucrat(): name("default"), grade(150)
{
	std::cout << YLLW << "Bureaucrat default constructor called for "
			<< this->getName() << " with grade of " << this->getGrade()
			<< RST << std::endl;
}

/*
 * Bureaucrat grade constructor
 */
Bureaucrat::Bureaucrat(int n): name("default")
{
	std::cout << YLLW << "Bureaucrat constructor called for " << this->getName()
			<< " with grade of " << n << RST << std::endl;
	this->setGrade(n);
}

/*
 * Bureaucrat name constructor
 */
Bureaucrat::Bureaucrat(std::string s): name(s), grade(150)
{
	std::cout << YLLW << "A Bureaucrat named " << this->getName()
			<< " with grade of " << this->getGrade() << " was created"
			<< RST << std::endl;
}

/*
 * Bureaucrat full constructor
 */
Bureaucrat::Bureaucrat(std::string s, int n): name(s)
{
	std::cout << YLLW << "Bureaucrat constructor called for " << this->getName()
			<< " with grade of " << n << RST << std::endl;
	this->setGrade(n);
}

/*
 * Bureaucrat copy constructor
 */
Bureaucrat::Bureaucrat(const Bureaucrat &copy): name(copy.getName() + "_copy")
{
	std::cout << YLLW << "Bureaucrat copy constructor called for " << this->getName()
		<< RST << std::endl;
	*this = copy;
}

/*
 * Bureaucrat assignation operator overload
 */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << YLLW << "Bureaucrat assignation operator called" << RST << std::endl;
	if (this == &src)
		return (*this);
	this->grade = src.getGrade();
	return (*this);
}

/**************************************************************************/
/*							GETTERS && SETTERS	   						  */
/**************************************************************************/

const std::string Bureaucrat::getName(void) const
{
	return(this->name);
}

int Bureaucrat::getGrade(void) const
{
	return(this->grade);
}

void Bureaucrat::setGrade(int n)
{
	if (n > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (n < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = n;
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

/*
 * Incrementes Bureaucrat's grade
 */
void Bureaucrat::incrementGrade(void)
{
	std::cout << "Trying to increment grade of " << this->getName() << std::endl;
	this->setGrade(this->grade - 1);
}

/*
 * Decrementes Bureaucrat's grade
 */
void Bureaucrat::decrementGrade(void)
{
	std::cout << "Trying to decrement grade of " << this->getName() << std::endl;
	this->setGrade(this->grade + 1);
}

/**************************************************************************/
/*								EXCEPTIONS					   			  */
/**************************************************************************/

/*
 * If a Bureaucrat's grade is below 1
 */
const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

/*
 * If a Bureaucrat's garde is above 150
 */
const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

/**************************************************************************/

/*
 * Ostream overload
 */
std::ostream &operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Bureaucrat " << a->getName() << ":\n\tgrade: "
		<< a->getGrade() << std::endl;
	return (o);
}
