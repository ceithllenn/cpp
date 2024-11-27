#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal		a;
	Cat			c;
	Dog			d;
	WrongAnimal	wa;
	WrongCat	wc;

	std::cout << "animal: ";
	a.makeSound();
	std::cout << "cat: ";
	c.makeSound();
	std::cout << "dog: ";
	d.makeSound();
	std::cout << "wrong animal: ";
	wa.makeSound();
	std::cout << "wrong cat: ";
	wc.makeSound();
	return (0);
}