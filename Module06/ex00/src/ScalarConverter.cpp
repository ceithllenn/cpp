#include "ScalarConverter.hpp"

/**************************************************************************/
/*							NON INSTANCIABLE CLASS 						  */
/**************************************************************************/

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	*this = copy;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &src) {
	(void)src;
	return (*this);
}
ScalarConverter::~ScalarConverter() {}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

void ScalarConverter::print_char_int(std::string &input)
{
	long long	converted = atoll(input.c_str());

	std::cout << BLUE << "char: " << RST;
	if (converted < std::numeric_limits<char>::min() || converted > std::numeric_limits<char>::max())
		std::cout << "impossible";
	else if (input.length() == 1 && !isdigit(input[0]))
		std::cout << "'" << input[0] << "'";
	else if (!isprint(converted))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(converted) << "'";
	std::cout << std::endl;

	std::cout << PURP << "int: " << RST;
	if (converted < std::numeric_limits<int>::min() || converted > std::numeric_limits<int>::max()
		|| input == "nan" || input == "nanf")
		std::cout << "impossible";
	else if (input.length() == 1 && !isdigit(input[0]))
		std::cout << static_cast<int>(input[0]);
	else
		std::cout << static_cast<int>(converted);
	std::cout << std::endl;
}

void ScalarConverter::print_float_double(std::string &input)
{
	double	converted = atof(input.c_str());

	std::cout << YLLW << "float: " << RST;
	if (input.length() == 1 && !isdigit(input[0]))
		std::cout << static_cast<float>(input[0]) << ".0";
	else if (std::floor(converted) == converted && converted < 1000000)
		std::cout << static_cast<float>(converted) << ".0";
	else
		std::cout << static_cast<float>(converted);
	std::cout << "f" << std::endl;

	std::cout << ORNG << "double: " << RST;
	if (input.length() == 1 && !isdigit(input[0]))
		std::cout << static_cast<double>(input[0]) << ".0";
	else if (std::floor(converted) == converted && converted < 1000000)
		std::cout << static_cast<double>(converted) << ".0";
	else
		std::cout << static_cast<double>(converted);
	std::cout << std::endl;
}

void ScalarConverter::convert(std::string &input)
{
	print_char_int(input);
	print_float_double(input);
}
