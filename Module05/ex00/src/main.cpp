#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	*a = new Bureaucrat();

	std::cout << GRNN << a << RST;

	try
	{
		a->decrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << REDD << "Decrementing grade of " << a->getName()
			<< " failed: " << e.what() << RST << std::endl;
	}

	std::cout << GRNN << a << RST;

	try
	{
		a->incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << REDD << "Incrementing grade of " << a->getName()
			<< " failed: " << e.what() << RST << std::endl;
	}

	std::cout << GRNN << a << RST;
	
	try
	{
		a->decrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << REDD << "Decrementing grade of " << a->getName()
			<< " failed: " << e.what() << RST << std::endl;
	}

	std::cout << GRNN << a << RST;
	delete a;
	std::cout << std::endl;

	Bureaucrat	*b = new Bureaucrat(1);

	std::cout << GRNN << b << RST;

	try
	{
		b->decrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << REDD << "Decrementing grade of " << b->getName()
			<< " failed: " << e.what() << RST << std::endl;
	}

	std::cout << GRNN << b << RST;

	try
	{
		b->incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << REDD << "Incrementing grade of " << b->getName()
			<< " failed: " << e.what() << RST << std::endl;
	}

	std::cout << GRNN << b << RST;

	try
	{
		b->incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << REDD << "Incrementing grade of " << b->getName()
			<< " failed: " << e.what() << RST << std::endl;
	}

	std::cout << GRNN << b << RST;
	delete b;
	std::cout << std::endl;

	Bureaucrat	*c = NULL;

	try
	{
		c = new Bureaucrat(0);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << REDD << "Constructing default failed: "
			<< e.what() << RST << std::endl;
	}
	if (c)
		delete c;
	std::cout << std::endl;

	Bureaucrat	*d = NULL;

	try
	{
		d = new Bureaucrat(170);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << REDD << "Constructing default failed: "
			<< e.what() << RST << std::endl;
	}
	if (d)
		delete d;
	std::cout << std::endl;
	
	Bureaucrat	*bob = new Bureaucrat("Bob", 120);

	std::cout << GRNN << bob << RST;
	bob->decrementGrade();
	std::cout << GRNN << bob << RST;

	Bureaucrat	*bob_copy = new Bureaucrat(*bob);

	std::cout << GRNN << bob_copy << RST;
	bob_copy->incrementGrade();
	std::cout << GRNN << bob << RST;
	std::cout << GRNN << bob_copy << RST;

	delete bob;
	delete bob_copy;

	return (0);
}