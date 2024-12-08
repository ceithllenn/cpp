#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << REDD << "Usage: ./RPN \"number number operator ...\" " << RST << std::endl;
		return (1);
	}

	try
	{
		RPN rpn;
		int	result = rpn.calculate(argv[1]);
		std::cout << result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << REDD << e.what() << RST << std::endl;
		return (1);
	}
	return (0);
}