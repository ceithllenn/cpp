#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	Character* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	bob->equip(src->createMateria("ice"));
	bob->equip(src->createMateria("cure"));

	Character *bob_copy = new Character(*bob);

	tmp = bob_copy->getMateria(1);
	bob_copy->unequip(1);
	delete tmp;

	delete bob;
	delete me;
	delete src;
	delete bob_copy;

	return (0);
}