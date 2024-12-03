#pragma once

#include "colors.hpp"
#include <string>
#include <iostream>
#include <cctype>
#include <limits>
#include <cmath>

class ScalarConverter
{
	public:
			static void convert(std::string &input);

	private:
			ScalarConverter();
			ScalarConverter(const ScalarConverter &copy);
			ScalarConverter& operator=(const ScalarConverter &src);
			~ScalarConverter();

			static void	print_char_int(std::string &input);
			static void	print_float_double(std::string &input);
};