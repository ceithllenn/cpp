#include "ShrubberyCreationForm.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * ShrubberyCreationForm destructor
 */
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << LIME << "ShrubberyCreationForm destructor called" << RST << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * ShrubberyCreationForm default constructor
 * private constructor
 */
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), target("default")
{
	std::cout << LIME << "ShrubberyCreationForm default constructor called" << RST << std::endl;
}

/*
 * ShrubberyCreationForm constructor
 */
ShrubberyCreationForm::ShrubberyCreationForm(std::string s): AForm("ShrubberyCreationForm", 145, 137), target(s)
{
	std::cout << LIME << "ShrubberyCreationForm constructor called for " << this->getTarget() << RST << std::endl;
}

/*
 * ShrubberyCreationForm copy constructor
 */
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy): AForm("ShrubberyCreationForm", 145, 137), target(copy.getTarget())
{
	std::cout << LIME << "ShrubberyCreationForm copy constructor called for " << this->getTarget() << RST << std::endl;
	*this = copy;
}

/*
 * ShrubberyCreationForm assignation operator overload
 */
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << LIME << "ShrubberyCreationForm assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

/**************************************************************************/
/*							GETTERS && SETTERS	   						  */
/**************************************************************************/

std::string ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

/*
 * Executes the form
 */
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getToEx())
		throw (Bureaucrat::GradeTooLowException());
	else if (!this->getSignStatus())
		throw (AForm::FormNotSignedException());
	else
	{
		std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());

		for (int i = 0; i < 5; i++)
		{
			outfile <<
			"         v" << std::endl <<
			"        >X<" << std::endl <<
			"         A" << std::endl <<
			"        d$b" << std::endl <<
			"      .d\\$$b." << std::endl <<
			"    .d$i$$\\$$b." << std::endl <<
			"       d$$@b" << std::endl <<
			"      d\\$$$ib" << std::endl <<
			"    .d$$$\\$$$b" << std::endl <<
			"  .d$$@$$$$\\$$ib." << std::endl <<
			"      d$$i$$b" << std::endl <<
			"     d\\$$$$@$b" << std::endl <<
			"  .d$@$$\\$$$$$@b." << std::endl <<
			".d$$$$i$$$\\$$$$$$b." << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
		std::endl;
		}
		outfile.close();
	}
}

/**************************************************************************/

/*
 * Ostream overload
 */
std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm *f)
{
	o << GRNN << "Form " << f->getName()
		<< ":\n\tsign grade:\t" << f->getToSign()
		<< "\n\texec grade:\t" << f->getToEx()
		<< "\n\tis signed:\t" << f->getSignStatus()
		<< "\n\ttarget:\t" << f->getTarget()
		<< RST << std::endl;

	return (o);
}