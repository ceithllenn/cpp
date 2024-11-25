#include "Harl.hpp"

int get_lvl(char *argv)
{
	std::string	lvls[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
		if (lvls[i] == argv)
			return (i);
	return (-1);
}

void harl_switch(char *argv, Harl &h)
{
	switch (get_lvl(argv))
	{
		case 0:
			h.complain("DEBUG");
			h.complain("INFO");
			h.complain("WARNING");
			h.complain("ERROR");
			break ;
		case 1:
			h.complain("INFO");
			h.complain("WARNING");
			h.complain("ERROR");
			break ;
		case 2:
			h.complain("WARNING");
			h.complain("ERROR");
			break ;
		case 3:
			h.complain("ERROR");
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

int main(int argc, char **argv)
{
	Harl	h;

	if (argc != 2)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	else
		harl_switch(argv[1], h);
	return (0);
}
