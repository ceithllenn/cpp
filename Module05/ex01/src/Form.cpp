#include "Form.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * Form destructor
 */
Form::~Form()
{
	std::cout << PINK << "Form destructor called" << RST << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * Form default constructor
 */
Form::Form(): name("default"), isSigned(false), toSign(150), toEx(150)
{
	std::cout << PINK << "Form constructor called for " << this->getName()
			<< " with sign grade " << this->getToSign() << " and ex garde of "
			<< this->getToEx() << RST << std::endl;
}

/*
 * Form name constructor
 */
Form::Form(std::string s): name(s), isSigned(false), toSign(150), toEx(150)
{
	std::cout << PINK << "Form constructor called for " << this->getName()
			<< " with sign grade " << this->getToSign() << " and ex garde of "
			<< this->getToEx() << RST << std::endl;
}

/*
 * Form grades constructor
 */
Form::Form(int nToSign, int nToEx): name("default"), isSigned(false), toSign(nToSign), toEx(nToEx)
{
	std::cout << PINK << "Form constructor called for " << this->getName()
			<< " with sign grade " << this->getToSign() << " and ex garde of "
			<< this->getToEx() << RST << std::endl;
	if (nToSign > 150 || nToEx > 150)
		throw Form::GradeTooLowException();
	else if (nToSign < 1 || nToEx < 1)
		throw Form::GradeTooHighException();
}

/*
 * Form full constructor
 */
Form::Form(std::string s, int nToSign, int nToEx): name(s), isSigned(false), toSign(nToSign), toEx(nToEx)
{
	std::cout << PINK << "Form constructor called for " << this->getName()
			<< " with sign grade " << this->getToSign() << " and ex garde of "
			<< this->getToEx() << RST << std::endl;
	if (nToSign > 150 || nToEx > 150)
		throw Form::GradeTooLowException();
	else if (nToSign < 1 || nToEx < 1)
		throw Form::GradeTooHighException();
}

/*
 * Form copy constructor
 */
Form::Form(const Form &copy): name(copy.getName() + "_copy"), isSigned(false),
	toSign(copy.getToSign()), toEx(copy.getToEx())
{
	std::cout << PINK << "Form copy constructor called" << RST << std::endl;
}

/*
 * Assignation operator overload
 */
Form& Form::operator=(const Form &src)
{
	std::cout << PINK << "Form assignation operator overload called" << RST << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

/**************************************************************************/
/*							GETTERS && SETTERS	   						  */
/**************************************************************************/

const std::string Form::getName(void) const
{
	return (this->name);
}

bool Form::getSignStatus(void) const
{
	return (this->isSigned);
}

int Form::getToSign(void) const
{
	return (this->toSign);
}

int Form::getToEx(void) const
{
	return (this->toEx);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

/*
 * Signs the form if the Bureaucrat's grade is high enough
 */
void Form::beSigned(const Bureaucrat &b)
{
	std::cout << "Bureaucrat " << b.getName() << " trying to sign form "
			<< this->getName() << std::endl;
	if (b.getGrade() > this->getToSign())
		throw (Bureaucrat::GradeTooLowException());
	else if (!this->getSignStatus())
	{
		this->isSigned = true;
		std::cout << this->getName() << " Form was signed by " << b.getName() << std::endl;
	}
	else
		std::cout << REDD << this->getName() << " Form is already signed" << RST << std::endl;
}

/**************************************************************************/
/*								EXCEPTIONS					   			  */
/**************************************************************************/

/*
 * grade above 150
 */
const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

/*
 * grade below 1
 */
const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

/**************************************************************************/

/*
 * Ostream overload
 */
std::ostream &operator<<(std::ostream &o, Form *f)
{
	o << GRNN << "Form: " << f->getName()
			<< ":\n\tsign grade:\t" << f->getToSign()
			<< "\n\texec grade:\t" << f->getToEx()
			<< "\n\tis signed:\t" << f->getSignStatus()
			<< RST << std::endl;
	return (o);
}
