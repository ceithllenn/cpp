#include "PhoneBook.hpp"
#include "tools.hpp"

/*
 * Phonebook default constructor
 */
PhoneBook::PhoneBook(void)
{
	index = 0;
	size = 0;
}

/*
 * Adds a new contact to the phonebook
 *
 * @param contact Contact to be added
 */
void	PhoneBook::add_contact(const Contact &contact)
{
	contacts[index] = contact;
	index = (index + 1) % 8;
	if (size < 8) size++;
}

/*
 * Displays all contacts in colums
 * user can enter index to display all contact info
 */
void	PhoneBook::search_contact(void) const
{
	if (!size)
	{
		std::cout << "No contacts yet ! :(" << std::endl;
		return ;
	}
	for (int i = 0; i < size; i++)
		contacts[i].display_all(i + 1);

	std::cout << "Enter the index of the contact you want to select: ";
	std::string s;
	std::getline(std::cin, s);

	if (std::cin.eof())
	{
		std::cin.clear();
		std::cout << "\nExiting search menu\n";
		return ;
	}

	if (is_num(s))
	{
		int	j = std::atoi(s.c_str());
		if (j >= 1 && j < size)
		{
			contacts[j - 1].display_contact();
			return ;
		}
	}
	std::cout << "Invalid index" << std::endl;
}
