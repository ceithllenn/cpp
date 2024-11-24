#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "tools.hpp"

int main()
{
	PhoneBook	phonebook;
	std::string	cmd;

	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break ;
		}
		if (cmd == "ADD")
			new_contact(phonebook);
		else if (cmd == "SEARCH")
			phonebook.search_contact();
		else if (cmd == "EXIT")
			break ;
	}
	return (0);
}
