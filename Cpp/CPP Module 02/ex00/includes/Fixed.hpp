#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public :
		Fixed();
		Fixed(const Fixed &value);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		Fixed& operator=(Fixed& value);

	private :
		int			_fixed_point;
		static const int	_fractional_bit;
};

#endif
