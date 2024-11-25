#ifndef FIXED_HPP
# define FIXED_HPP

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

			int		getRawBits() const;
			void	setRawBits(int const raw);
};
#endif