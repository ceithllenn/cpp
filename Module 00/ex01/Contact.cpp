#include "Contact.hpp"
#include "tools.hpp"

/*
 * Contact default constructor
 */
Contact::Contact(void)
{
	
}

/*
 * Initialize Contact data
 *
 * @param fname Contact's first name
 * @param lname Contact's last name
 * @param nick Contact's nickname
 * @param number Contact's phone number
 * @param s Contact's darkets secret
 */
void	Contact::set_contact(const std::string &fname, const std::string &lname, const std::string &nick, const std::string &number, const std::string &s)
{
	first_name = fname;
	last_name = lname;
	nickname = nick;
	phone_number = number;
	secret = s;
}

/*
 * Formats the string to display contact list in column
 * @return formatted string
 */
std::string	Contact::in_column(const std::string &str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (std::string(10 - str.length(), ' ') + str);
}

/*
 * Displays all Contacts in formatted colums
 */
void	Contact::display_all(int index) const
{
	std::cout << "|" << in_column(itos(index))
				<< "|" << in_column(first_name)
				<< "|" << in_column(last_name)
				<< "|" << in_column(nickname)
				<< "|" << std::endl;
}

/*
 * Displays all data on a selected Contact
 */
void	Contact::display_contact() const
{
	std::cout << "First name: " << first_name << std::endl
				<< "Last name: " << last_name << std::endl
				<< "Nickname: " << nickname << std::endl
				<< "Phone number: " << phone_number << std::endl
				<< "Darkest secret: " << secret << std::endl;
}
