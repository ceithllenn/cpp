#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>

#define RESET "\033[0m"
#define BLUE "\033[34m"

class Fixed
{
	private:
			int			value;
			static int	fract;

	public:
			Fixed();
			~Fixed();
			Fixed(Fixed const &copy);
			Fixed(int const n);
			Fixed(float const n);

			Fixed& operator=(Fixed const &copy);

			bool operator>(Fixed fixed) const;
			bool operator<(Fixed fixed) const;
			bool operator>=(Fixed fixed) const;
			bool operator<=(Fixed fixed) const;
			bool operator==(Fixed fixed) const;
			bool operator!=(Fixed fixed) const;

			float operator+(Fixed fixed) const;
			float operator-(Fixed fixed) const;
			float operator*(Fixed fixed) const;
			float operator/(Fixed fixed) const;

			Fixed operator++();
			Fixed operator--();
			Fixed operator++(int);
			Fixed operator--(int);

			int		getRawBits() const;
			void	setRawBits(int const raw);
			float	toFloat(void) const;
			int		toInt(void) const;

			static Fixed &min(Fixed &first, Fixed &second);
			static const Fixed &min(const Fixed &first, const Fixed &second);
			static Fixed &max(Fixed &first, Fixed &second);
			static const Fixed &max(const Fixed &first, const Fixed &second);
};

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed);

#endif