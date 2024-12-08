#pragma once

#include "colors.hpp"
#include <stack>
#include <string>
#include <iostream>
#include <sstream>

class RPN
{
	private:
			std::stack<int>	stack;

			bool			isOperator(const std::string &s);
			int				operation(const std::string &s, int n1, int n2);
			void			checkExpression(const std::string &s);

	public:
			RPN();
			RPN(const RPN &copy);
			RPN& operator=(const RPN &src);

			~RPN();

			int	calculate(const std::string &s);

			class DivisionByZeroException: public std::exception
			{
				public:
						virtual const char *what() const throw();
			};
			
			class InvalidOperatorException: public std::exception
			{
				public:
						virtual const char *what() const throw();
			};

			class ArgumentIsEmptyException: public std::exception
			{
				public:
						virtual const char *what() const throw();
			};

			class BadSyntaxException: public std::exception
			{
				public:
						virtual const char *what() const throw();
			};

			class WrongNumberException: public std::exception
			{
				public:
						virtual const char *what() const throw();
			};

			class OperandsOperatorsException: public std::exception
			{
				public:
						virtual const char *what() const throw();
			};

			class NotEnoughOperandsException: public std::exception
			{
				public:
						virtual const char *what() const throw();
			};

			class TooManyOperandsException: public std::exception
			{
				public:
						virtual const char *what() const throw();
			};
};