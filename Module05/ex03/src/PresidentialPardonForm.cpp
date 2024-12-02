#include "PresidentialPardonForm.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * PresidentialPardonForm destructor
 */
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << PURP << "PresidentialPardonForm destructor called" << RST << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * PresidentialPardonForm default constructor
 * private constructor
 */
PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), target("default")
{
	std::cout << PURP << "PresidentialPardonForm default constructor called" << RST << std::endl;
}

/*
 * PresidentialPardonForm constructor
 */
PresidentialPardonForm::PresidentialPardonForm(std::string s): AForm("PresidentialPardonForm", 25, 5), target(s)
{
	std::cout << PURP << "PresidentialPardonForm constructor called for " << this->getTarget() << RST << std::endl;
}

/*
 * PresidentialPardonForm copy constructor
 */
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy): AForm("PresidentialPardonForm", 25, 5), target(copy.getTarget())
{
	std::cout << PURP << "PresidentialPardonForm copy constructor called for " << this->getTarget() << RST << std::endl;
	*this = copy;
}

/*
 * PresidentialPardonForm assignation operator overload
 */
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	std::cout << PURP << "PresidentialPardonForm assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

/**************************************************************************/
/*							GETTERS && SETTERS	   						  */
/**************************************************************************/

std::string PresidentialPardonForm::getTarget(void) const
{
	return (this->target);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

/*
 * Executes the form
 */
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getToEx())
		throw (Bureaucrat::GradeTooLowException());
	else if (!this->getSignStatus())
		throw (AForm::FormNotSignedException());
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

/**************************************************************************/

/*
 * Ostream overload
 */
std::ostream &operator<<(std::ostream &o, PresidentialPardonForm *f)
{
	o << GRNN << "Form " << f->getName()
		<< ":\n\tsign grade:\t" << f->getToSign()
		<< "\n\texec grade:\t" << f->getToEx()
		<< "\n\tis signed:\t" << f->getSignStatus()
		<< "\n\ttarget:\t" << f->getTarget()
		<< RST << std::endl;
	
	return (o);
}