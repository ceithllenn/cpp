#pragma once

#include "colors.hpp"
#include <string>
#include "Data.hpp"
#include <iostream>
#include <stdint.h>

class Serializer
{
	private:
			Serializer();
			Serializer(const Serializer &copy);
			Serializer& operator=(const Serializer &src);
			~Serializer();

	public:
			static uintptr_t	serialize(Data *ptr);
			static Data			*deserialize(uintptr_t raw);
};
