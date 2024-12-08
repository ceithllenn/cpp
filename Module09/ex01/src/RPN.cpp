#include "RPN.hpp"

/**************************************************************************/
/*									DESTRUCTOR	   						  */
/**************************************************************************/

/**
 * @brief Destroy the RPN::RPN object
 * 
 */
RPN::~RPN()
{
	//std::cout << YLLW << "RPN destructor called" << RST << std::endl;
}

/**************************************************************************/
/*								CONSTRUCTORS	   						  */
/**************************************************************************/

/**
 * @brief Construct a new RPN::RPN object
 * 
 */
RPN::RPN()
{
	//std::cout << YLLW << "RPN default constructor called" << RST << std::endl;
}

/**
 * @brief Construct a new RPN::RPN object
 * 
 * @param copy 
 */
RPN::RPN(const RPN &copy)
{
	//std::cout << YLLW << "RPN copy constructor called" << RST << std::endl;
	if (this != &copy)
		*this = copy;
}

/**
 * @brief RPN assignation operator overload
 * 
 * @param src 
 */
RPN& RPN::operator=(const RPN &src)
{
//	std::cout << YLLW << "RPN assignation operator overload" << RST << std::endl;
	if (this != &src)
		this->stack = src.stack;
	return (*this);
}

/**************************************************************************/
/*							TOOLS METHODS					   			  */
/**************************************************************************/

/**
 * @brief Checks if string is an operator
 * 
 * @param s string to test
 */
bool RPN::isOperator(const std::string &s)
{
	return (s == "+" || s == "-" || s == "*" || s == "/");
}

/**
 * @brief Performs an operation
 * 
 * @param s operator
 * @param n1 operand 1
 * @param n2 operand 2
 * @return result
 */
int RPN::operation(const std::string &s, int n1, int n2)
{
	if (s == "+")
		return (n1 + n2);
	if (s == "-")
		return (n1 - n2);
	if (s == "*")
		return (n1 * n2);
	if (s == "/")
	{
		if (!n2)
			throw DivisionByZeroException();
		return (n1 / n2);
	}
	throw InvalidOperatorException();
}

void RPN::checkExpression(const std::string &s)
{
	int	numberCount(0), operatorCount(0), spaceCount(0);

	if (s.empty())
		throw ArgumentIsEmptyException();
	if (isspace(s[0]) || isspace(s[s.size() - 1]))
		throw BadSyntaxException();

	for (size_t i = 0; i < s.size(); i++)
	{
		char	c = s[i];

		if (!isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/' && c != ' ')
			throw BadSyntaxException();

		if (isdigit(c))
		{
			if (isdigit(s[i + 1]))
				throw WrongNumberException();
			numberCount++;
		}
		else if (isOperator(std::string(1, c)))
			operatorCount++;
		else if (isspace(c))
		{
			spaceCount++;
			if (i > 0 && isspace(s[i - 1]))
				throw BadSyntaxException();
		}
	}

	if (spaceCount != numberCount + operatorCount - 1)
		throw BadSyntaxException();
	if (!operatorCount || !numberCount || numberCount != operatorCount + 1)
		throw OperandsOperatorsException();
}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

/**
 * @brief Calculate the RPN expression
 * 
 * @param s RPN expression
 * @return calcul's result
 */
int RPN::calculate(const std::string &s)
{
	checkExpression(s);

	std::istringstream	iss(s);
	std::string			token;

	while (iss >> token)
	{
		if (isdigit(token[0]))
		{
			std::stringstream	ss(token);
			int					number;

			ss >> number;
			stack.push(number);
		}
		else if (isOperator(token))
		{
			if (stack.size() < 2)
				throw NotEnoughOperandsException();
			int	n2 = stack.top();
			stack.pop();
			int	n1 = stack.top();
			stack.pop();
			int result = operation(token, n1, n2);
			stack.push(result);
		}
		else
			throw BadSyntaxException();
	}

	if (stack.size() != 1)
		throw TooManyOperandsException();

	return (stack.top());
}

/**************************************************************************/
/*								EXCEPTIONS					   			  */
/**************************************************************************/

/**
 * @brief Division by zero error
 */
const char *RPN::DivisionByZeroException::what(void) const throw()
{
	return ("Error: division by zero");
}

/**
 * @brief Invalid operator error
 */
const char *RPN::InvalidOperatorException::what(void) const throw()
{
	return ("Error: invalid operator");
}

/**
 * @brief Empty argument error
 */
const char *RPN::ArgumentIsEmptyException::what(void) const throw()
{
	return ("Error: argument is empty");
}

/**
 * @brief Bad syntax error
 */
const char *RPN::BadSyntaxException::what(void) const throw()
{
	return ("Error: bad syntax");
}

/**
 * @brief Number too big error
 */
const char *RPN::WrongNumberException::what(void) const throw()
{
	return ("Error: number cannot be greater than 9");
}

/**
 * @brief Operands/operators error
 */
const char *RPN::OperandsOperatorsException::what(void) const throw()
{
	return ("Error: wrong number of operands/operators");
}

/**
 * @brief Not enough operands error
 */
const char *RPN::NotEnoughOperandsException::what(void) const throw()
{
	return ("Error: not enough operands for operation");
}

/**
 * @brief Too many operands left error
 */
const char *RPN::TooManyOperandsException::what(void) const throw()
{
	return ("Error: too many operands left on the stack");
}