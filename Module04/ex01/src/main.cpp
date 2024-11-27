#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal		*tab[6];

	for (int i = 0; i < 3; i++)
		tab[i] = new Cat;
	for (int i = 3; i < 6; i++)
		tab[i] = new Dog;

	for (int i = 0; i < 6; i++)
		tab[i]->makeSound();

	for (int i = 0; i < 6; i++)
		delete tab[i];

	//Dog		*d1 = new Dog();

	//d1->getBrain()->setIdea(0, "Hungry!");

	//Dog		*d2 = new Dog(*d1);

	//delete d1;
	//std::cout << d2->getBrain()->getIdea(0) << std::endl;
	//delete d2;
	return (0);
}