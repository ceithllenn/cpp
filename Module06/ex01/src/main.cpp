#include "Serializer.hpp"
#include "Data.hpp"

int	main(void)
{
	Data	A;
	Data	B;
	Data	*C;

	uintptr_t result;

	A.n = 42;
	A.str = "Deux fois vingt-et-un";
	B.n = 69;
	B.str = "Six-Neuf la trique";
	C = &B;
	std::cout << std::endl;

	std::cout << "A - int value :\t" << A.n << std::endl;
	std::cout << "A - str value :\t" << A.str << std::endl;
	std::cout << "A - adr value :\t" << &A << std::endl;
	std::cout << std::endl;

	std::cout << "B - int value :\t" << B.n << std::endl;
	std::cout << "B - str value :\t" << B.str << std::endl;
	std::cout << "B - adr value :\t" << &B << std::endl;
	std::cout << std::endl;

	std::cout << "C - int value :\t" << C->n << std::endl;
	std::cout << "C - str value :\t" << C->str << std::endl;
	std::cout << "C - adr value :\t" << C << std::endl;
	std::cout << std::endl;

	result = Serializer::serialize(&A);
	std::cout << "Result value :\t" << result << std::endl;
	std::cout << std::endl;

	C = Serializer::deserialize(result);
	std::cout << "Result value :\t" << result << std::endl;
	std::cout << std::endl;
	
	std::cout << "A - int value :\t" << A.n << std::endl;
	std::cout << "A - str value :\t" << A.str << std::endl;
	std::cout << "A - adr value :\t" << &A << std::endl;
	std::cout << std::endl;

	std::cout << "B - int value :\t" << B.n << std::endl;
	std::cout << "B - str value :\t" << B.str << std::endl;
	std::cout << "B - adr value :\t" << &B << std::endl;
	std::cout << std::endl;

	std::cout << "C - int value :\t" << C->n << std::endl;
	std::cout << "C - str value :\t" << C->str << std::endl;
	std::cout << "C - adr value :\t" << C << std::endl;
	std::cout << std::endl;

	return (0);
}