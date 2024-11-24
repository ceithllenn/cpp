#include <string>
#include <iostream>

int main()
{
	std::string s = "HI THIS IS BRAIN";
	std::string *stringPTR = &s;
	std::string &stringREF = s;

	std::cout
			<< "memory adress of the string variable: " << &s << "\n"
			<< "memory adress of held by stringPTR: " << stringPTR << "\n"
			<< "memory adress of held by stringREF: " << &stringREF << "\n"
			<< "value of the string: " << s << "\n"
			<< "value of stringPTR: " << stringPTR << "\n"
			<< "value of stringREF: " << stringREF << std::endl;
	return (0);
}