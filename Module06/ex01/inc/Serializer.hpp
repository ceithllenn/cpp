#pragma once

#include "colors.hpp"
#include <string>
#include "Data.hpp"
#include <iostream>

class Data;

class Serializer
{
	private:
			Serializer();
			Serializer(const Serializer &copy);
			Serializer& operator=(const Serializer &src);
			~Serializer();

	public:
			uintptr_t	serialize(Data *ptr);
			Data		*deserialize(uintptr_t raw);
};
