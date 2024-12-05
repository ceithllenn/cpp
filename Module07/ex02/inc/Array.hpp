#pragma once

#include <iostream>

template< typename T>

class Array
{
	private:
			T				*array;
			unsigned int	size;

	public:
			Array(): size(0)
			{
				std::cout << "default constructor called: created empty Array of size 0" << std::endl;
				this->array = new T[this->size];
			}

			Array(unsigned int n): size(n)
			{
				std::cout << "constructor for an Array of size " << size << " called" << std::endl;
				this->array = new T[this->size];
			}

			Array(const Array &copy): size(copy.getSize())
			{
				std::cout << "Array copy constructor called" << std::endl;
				this->array = NULL;
				*this = copy;
			}

			~Array()
			{
				std::cout << "Array destructor called" << std::endl;
				if (this->array)
					delete [] this->array;
			}

			Array &operator=(const Array &src)
			{
				std::cout << "Array assignation operator called" << std::endl;
				if (this->array)
					delete [] this->array;
				if (src.getSize())
				{
					this->size = src.getSize();
					this->array = new T[this->size];
					for (unsigned int i = 0; i < this->getSize(); i++)
						this->array[i] = src.array[i];
				}
				return (*this);
			}

			T &operator[](unsigned int index)
			{
				if (!this->array || index >= this->size)
					throw Array<T>::InvalidIndexException();
				return (this->array[index]);
			}

			class InvalidIndexException: public std::exception
			{
				public:
						virtual const char	*what() const throw();
			};

			unsigned int getSize() const
			{
				return (this->size);
			}
};

template<typename T>
const char *Array<T>::InvalidIndexException::what() const throw()
{
	return ("Error: Invalid index");
}
