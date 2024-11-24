#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>
# include <iostream>

class Contact
{
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	secret;
public:
	Contact();
	void set_contact(const std::string &fname, const std::string &lname, const std::string &nick, const std::string &number, const std::string &s);
	std::string	in_column(const std::string &str) const;
	void display_all(int index) const;
	void display_contact() const;
};

#endif