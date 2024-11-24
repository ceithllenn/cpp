#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <cctype>

/*
 * Checks if a string contains only numeric characters
 *
 * @param s string to check
 * @return false if a non numeric character is found
 */
bool is_num(const std::string s)
{
	if (s.empty()) return (false);
	for (std::string::size_type i = 0; i < s.length(); i++)
	{
		if (!std::isdigit(s[i]) && s[i] != ' ')
			return (false);
	}
	return (true);
}

/*
 * Converts an int into a string
 */
std::string itos(int n)
{
	std::stringstream	s;

	s << n;
	return (s.str());
}

/*
 * Checks if the string s is a valid Phonebook attribute
 */
bool is_valid(std::string s)
{
	if (s.empty()) return (false);
	for (std::string::size_type i = 0; i < s.length(); i++)
	{
		if (!isspace(s[i]))
			return (true);
	}
	return (false);
}

/*
 * Creates a new contact in a Phonebook with user inputs
 */
void new_contact(PhoneBook &phonebook)
{
	Contact	contact;
	std::string	fname, lname, nick, number, secret;

	if (std::cin.eof())
	{
		std::cout << "Exiting ADD menu\n";
		return ;
	}

	std::cout << "Enter first name: ";
	std::getline(std::cin, fname);
	if (std::cin.eof())
	{
		std::cout << "\nExiting ADD menu\n";
		return ;
	}
	if (!is_valid(fname))
	{
		std::cout << "Field cannot be empty or contain only spaces. Exiting ADD menu." << std::endl;
		return ;
	}

	std::cout << "Enter last name: ";
	std::getline(std::cin, lname);
	if (std::cin.eof())
	{
		std::cout << "\nExiting ADD menu\n";
		return ;
	}
	if (!is_valid(lname))
	{
		std::cout << "Field cannot be empty or contain only spaces. Exiting ADD menu." << std::endl;
		return ;
	}

	std::cout << "Enter nickname: ";
	std::getline(std::cin, nick);
	if (std::cin.eof())
	{
		std::cout << "\nExiting ADD menu\n";
		return ;
	}
	if (!is_valid(nick))
	{
		std::cout << "Field cannot be empty or contain only spaces. Exiting ADD menu." << std::endl;
		return ;
	}

	std::cout << "Enter phone number: ";
	std::getline(std::cin, number);
	if (std::cin.eof())
	{
		std::cout << "\nExiting ADD menu\n";
		return ;
	}
	if (!is_num(number))
	{
		std::cout << "Phone number should only contain digits. Exiting ADD menu" << std::endl;
		return ;
	}

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, secret);
	if (std::cin.eof())
	{
		std::cout << "\nExiting ADD menu\n";
		return ;
	}
	if (!is_valid(secret))
	{
		std::cout << "Field cannot be empty or contain only spaces. Exiting ADD menu." << std::endl;
		return ;
	}
	contact.set_contact(fname, lname, nick, number, secret);
	phonebook.add_contact(contact);
}
