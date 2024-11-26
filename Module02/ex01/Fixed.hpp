#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
	private:
			int			value;
			static int	fract;

	public:
			Fixed();
			~Fixed();
			Fixed(Fixed const &copy);
			Fixed& operator=(Fixed const &copy);
			Fixed(int const n);
			Fixed(float const n);

			int		getRawBits() const;
			void	setRawBits(int const raw);
			float	toFloat(void) const;
			int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed);

#endif