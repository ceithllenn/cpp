#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class Zombie
{
	private:

	std::string	name;

	public:

	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce();
	void set_name(std::string s);
};

Zombie	*zombieHorde(int N, std::string name);

#endif