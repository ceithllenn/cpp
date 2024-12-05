#include "iter.hpp"

int main()
{
	int			tab[4] = {1, 2, 3, 4};
	std::string	tab2[4] = {"coucou", "comment", "ca", "va"};
	float		tab3[4] = {3.23f, 213.21222f, 543.32f, 634.12f};


	iter(tab, 4, display);
	std::cout << std::endl;
	iter(tab2, 4, display);
	std::cout << std::endl;
	iter(tab3, 4, display);
	return (0);
}