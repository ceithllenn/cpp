#include "RobotomyRequestForm.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/*
 * RobotomyRequestForm destructor
 */
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << ORNG << "RobotomyRequestForm destructor called" << RST << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/*
 * RobotomyRequestForm default constructor
 * private constructor
 */
RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("default")
{
	std::cout << ORNG << "RobotomyRequestForm default constructor called" << RST << std::endl;
}

/*
 * RobotomyRequestFormconstructor
 */
RobotomyRequestForm::RobotomyRequestForm(std::string s): AForm("RobotomyRequestForm", 72, 45), target(s)
{
	std::cout << ORNG << "RobotomyRequestForm constructor called for " << this->getTarget() << RST << std::endl;
}

/*
 * RobotomyRequestForm copy constructor
 */
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy): AForm("RobotomyRequestForm", 72, 45), target(copy.getTarget())
{
	std::cout << ORNG << "RobotomyRequestForm copy constructor called for " << this->getTarget() << RST << std::endl;
	*this = copy;
}

/*
 * RobotomyRequestForm assignation operator overload
 */
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << ORNG << "RobotomyRequestForm assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

/**************************************************************************/
/*							GETTERS && SETTERS	   						  */
/**************************************************************************/

std::string RobotomyRequestForm::getTarget(void) const
{
	return (this->target);
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

static int count_robot = 0;
/*
 * Executes the form
 */
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getToEx())
		throw (Bureaucrat::GradeTooLowException());
	else if (!this->getSignStatus())
		throw (AForm::FormNotSignedException());
	else if (count_robot++ % 2)
		std::cout << DRILLING_NOISE << this->getTarget()
			<< " has been robotomized" << std::endl;
	else
		std::cout << DRILLING_NOISE << "Robotomy failed !" << std::endl;
}

/**************************************************************************/

/*
 * Ostream overload
 */
std::ostream &operator<<(std::ostream &o, RobotomyRequestForm *f)
{
	o << GRNN << "Form " << f->getName()
		<< ":\n\tsign grade:\t" << f->getToSign()
		<< "\n\texec grade:\t" << f->getToEx()
		<< "\n\tis signed:\t" << f->getSignStatus()
		<< "\n\ttarget:\t" << f->getTarget()
		<< RST << std::endl;

	return (o);
}
