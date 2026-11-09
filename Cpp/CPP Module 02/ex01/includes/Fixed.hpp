#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public :
		Fixed();
		Fixed(const int fixed_point);
		Fixed(const float floating_point);
		Fixed(const Fixed &value);
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;

		Fixed& operator=(const Fixed& value);

	private :
		int			_fixed_point;
		static const int	_fractional_bit;
};

std::ostream& operator<<(std::ostream& os, const Fixed& value);

#endif
