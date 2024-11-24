#ifndef TOOLS_HPP
# define TOOLS_HPP
# include <string>
# include <iostream>
# include <sstream>
# include <cctype>
# include "PhoneBook.hpp"

bool		is_num(const std::string s);
std::string itos(int n);
void new_contact(PhoneBook &Phonebook);

#endif