#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream>
# include <string>
# include <cstdlib>

class PhoneBook
{
private:
	Contact	contacts[8];
	int		index;
	int		size;
public:

	PhoneBook();
	void add_contact(const Contact &contact);
	void search_contact() const;
};

#endif