#include "Serializer.hpp"

/**************************************************************************/
/*							NON INSTANCIABLE CLASS 						  */
/**************************************************************************/

Serializer::Serializer() {}
Serializer::Serializer(const Serializer &copy) {
	*this = copy;
}
Serializer& Serializer::operator=(const Serializer &src) {
	(void)src;
	return (*this);
}
Serializer::~Serializer() {}

/**************************************************************************/
/*							PUBLIC METHODS					   			  */
/**************************************************************************/

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}