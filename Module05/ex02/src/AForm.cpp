#include "AForm.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * AForm destructor
 */
AForm::~AForm()
{
	std::cout << PINK << "AForm destructor called" << RST << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * AForm default constructor
 */
AForm::AForm(): name("default"), isSigned(false), toSign(150), toEx(150)
{
	std::cout << PINK << "AForm constructor called for " << this->getName()
			<< " with sign grade " << this->getToSign() << " and exec grade of "
			<< this->getToEx() << RST << std::endl;
}

/*
 * AForm name constructor
 */
AForm::AForm(std::string s): name(s), isSigned(false), toSign(150), toEx(150)
{
	std::cout << PINK << "AForm constructor called for " << this->getName()
			<< " with sign grade " << this->getToSign() << " and exex grade of "
			<< this->getToEx() << RST << std::endl;
}

/*
 * AForm grades constructor
 */
AForm::AForm(int nToSign, int nToEx): name("default"), isSigned(false), toSign(nToSign), toEx(nToEx)
{
	std::cout << PINK << "AForm constructor called for " << this->getName()
			<< " with sign grade " << this->getToSign() << " and exec grade of "
			<< this->getToEx() << RST << std::endl;
	if (nToSign > 150 || nToEx > 150)
		throw AForm::GradeTooLowException();
	else if (nToSign < 1 || nToEx < 1)
		throw AForm::GradeTooHighException();
}

/*
 * AForm full constructor
 */
AForm::AForm(std::string s, int nToSign, int nToEx): name(s), isSigned(false), toSign(nToSign), toEx(nToEx)
{
	std::cout << PINK << "AForm constructor called for " << this->getName()
			<< " with sign grade " << this->getToSign() << " and exec grade of "
			<< this->getToEx() << RST << std::endl;
	if (nToSign > 150 || nToEx > 150)
		throw AForm::GradeTooLowException();
	else if (nToSign < 1 || nToEx < 1)
		throw AForm::GradeTooHighException();
}

/*
 * AForm copy constructor
 */
AForm::AForm(const AForm &copy): name(copy.getName() + "_copy"), isSigned(false),
	toSign(copy.getToSign()), toEx(copy.getToEx())
{
	std::cout << PINK << "AForm copy constructor called" << RST << std::endl;
}

/*
 * Assignation operator overload
 */
AForm& AForm::operator=(const AForm &src)
{
	std::cout << PINK << "AForm assignation operator overload called" << RST << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

/**************************************************************************/
/*							GETTERS && SETTERS	   						  */
/**************************************************************************/

const std::string AForm::getName(void) const
{
	return (this->name);
}

bool AForm::getSignStatus(void) const
{
	return (this->isSigned);
}

int AForm::getToSign(void) const
{
	return (this->toSign);
}

int AForm::getToEx(void) const
{
	return (this->toEx);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

/*
 * Signs the form if the Bureaucrat's grade is high enough
 */
void AForm::beSigned(const Bureaucrat &b)
{
	std::cout << "Bureaucrat " << b.getName() << " trying to sign form "
			<< this->getName() << std::endl;
	if (b.getGrade() > this->getToSign())
		throw (Bureaucrat::GradeTooLowException());
	else if (!this->getSignStatus())
	{
		this->isSigned = true;
		std::cout << this->getName() << " form was signed by " << b.getName() << std::endl;
	}
	else
		std::cout << REDD << this->getName() << " form is already signed" << RST << std::endl;
}

/**************************************************************************/
/*								EXCEPTIONS					   			  */
/**************************************************************************/

/*
 * grade above 150
 */
const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

/*
 * grade below 1
 */
const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

/*
 * if form isn't signed
 */
const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form needs to be signed before executing");
}

/**************************************************************************/

/*
 * Ostream overload
 */
std::ostream &operator<<(std::ostream &o, AForm *f)
{
	o << GRNN << "Form: " << f->getName()
			<< ":\n\tsign grade:\t" << f->getToSign()
			<< "\n\texec grade:\t" << f->getToEx()
			<< "\n\tis signed:\t" << f->getSignStatus()
			<< RST << std::endl;
	return (o);
}
