#include "colors.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>

/*
 * Randomly instanciates A, B or C
 *
 * @return Base pointer
 */
Base *generate(void)
{
	int	choice = rand() % 3;

	switch (choice)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		default:
			return (new C());
	}
}

/*
 * Prints the object's type
 */
void identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL) std::cout << BLUE << "- A -" RST << std::endl;
	else if (dynamic_cast<B*>(p) != NULL) std::cout << CYAN << "- B -" RST << std::endl;
	else if (dynamic_cast<C*>(p) != NULL) std::cout << MAGN << "- C -" RST << std::endl;
}

/*
 * Prints the object's type
 */
void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << LIME "- A -" RST << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << REDD << "NOT A" << std::endl;
	}
	
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << LIME << "- B -" RST << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << REDD << "NOT B" << std::endl;
	}
	
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << LIME << "- C -" RST << std::endl;
	}
	catch (const std::exception &e) 
	{
		std::cout << REDD << "NOT C" << std::endl;
	}
}

int main(void)
{
	srand(static_cast<unsigned int>(time(0)));

	Base* instances[10];
	
	for (int i = 0; i < 10; ++i)
		instances[i] = generate();

	std::cout << GRY1 << "Identify pointer:" << RST << std::endl;
	for (int i = 0; i < 10; ++i)
		identify(instances[i]);
	std::cout << std::endl;

	std::cout << GRY1 << "Identify reference:" << RST << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		identify(*instances[i]);
		std::cout << std::endl;
	}

	for (int i = 0; i < 10; ++i)
		delete instances[i];

	return (0);
}