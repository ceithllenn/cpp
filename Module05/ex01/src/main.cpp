#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat	*a = new Bureaucrat();
	Form		*b = new Form();

	std::cout << a;
	std::cout << b;
	std::cout << std::endl;

	try
	{
		b->beSigned(*a);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << a->getName() << " was not able to sign " << b->getName()
			<< ": " << e.what() << std::endl;
	}
	std::cout << b;
	std::cout << std::endl;

	delete a;
	delete b;
	std::cout << std::endl;

	Bureaucrat	*c = new Bureaucrat("Assistant", 145);
	Bureaucrat	*d = new Bureaucrat("CEO", 1);
	Form		*f = new Form("Rent Contract", 140, 100);

	std::cout << c;
	std::cout << d;
	std::cout << f;

	try
	{
		c->signForm(*f);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << REDD << c->getName() << " was not able to sign the form "
			<< f->getName() << ": " << e.what() << RST << std::endl;
	}
	std::cout << f;

	try
	{
		f->beSigned(*d);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << REDD << d->getName() << " was not able to sign the form "
			<< f->getName() << ": " << e.what() << RST << std::endl;	
	}
	std::cout << f;

	d->signForm(*f);

	delete c;
	delete d;
	delete f;
	std::cout << std::endl;

	Form	*g = NULL;
	try
	{
		g = new Form(160, 145);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << REDD << "Constructing default failed: "
			<< e.what() << RST << std::endl;
	}

	Form	*h = NULL;
	try
	{
		h = new Form(145, 160);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << REDD << "Constructing default failed: "
			<< e.what() << RST << std::endl;
	}

	Form	*i = NULL;
	try
	{
		i = new Form(145, -15);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << REDD << "Constructing default failed: "
			<< e.what() << RST << std::endl;
	}

	Form	*j = NULL;
	try
	{
		j = new Form(-15, 145);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << REDD << "Constructing default failed: "
			<< e.what() << RST << std::endl;
	}

	if (g)
		delete g;
	if (h)
		delete h;
	if (i)
		delete i;
	if (j)
		delete j;
	return (0);
}