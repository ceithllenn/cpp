#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	std::string tmp = argv[1];

	if (argc != 2)
		return (0);
	ScalarConverter::convert(tmp);
	return (0);
}