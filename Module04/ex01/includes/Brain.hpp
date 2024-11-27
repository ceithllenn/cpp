#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>
# include "colors.hpp"

class Brain
{
	private:
			std::string	ideas[100];

	public:
			Brain();
			Brain(const Brain &copy);
			Brain &operator=(const Brain &src);

			virtual ~Brain();

			std::string getIdea(int index);
			void		setIdea(int index, const std::string idea);
};

#endif