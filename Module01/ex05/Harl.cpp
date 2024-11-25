#include "Harl.hpp"

/*
 * Harl default constructor
 */
Harl::Harl()
{

}

/*
 * Harl destructor
 */
Harl::~Harl()
{

}

/*
 * Harl debug message
 */
void Harl::debug(void)
{
	std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!";
	std::cout << std::endl;
}

/*
 * Harl info message
 */
void Harl::info(void)
{
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!";
	std::cout << std::endl;
}

/*
 * Harl warning message
 */
void Harl::warning(void)
{
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.";
	std::cout << std::endl;
}

/*
 * Harl error message
 */
void Harl::error(void)
{
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}

/*
 * Selects the right Harl complain message
 */
void Harl::complain(std::string level)
{
	void (Harl::*ptr[4])(void) 	= {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	lvls[4] 		= {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == lvls[i])
		{
			(this->*ptr[i])();
			break ;
		}
	}
}
