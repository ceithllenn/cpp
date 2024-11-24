#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon
{
	private:
			std::string	type;

	public:
			Weapon();
			Weapon(std::string);
			~Weapon();

			std::string const &getType() const;
			void setType(std::string s);
};

#endif