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

		bool operator< (const Fixed& other) const;
		bool operator> (const Fixed& other) const;
		bool operator<= (const Fixed& other) const;
		bool operator>= (const Fixed& other) const;
		bool operator== (const Fixed& other) const;
		bool operator!= (const Fixed& other) const;

		Fixed operator+ (const Fixed& other) const;
		Fixed operator- (const Fixed& other) const;
		Fixed operator* (const Fixed& other) const;
		Fixed operator/ (const Fixed& other) const;

		Fixed operator++(int);
		Fixed& operator++(void);
		Fixed operator--(int);
		Fixed& operator--(void);

		static const Fixed& max(const Fixed& value1, const Fixed& value2);
		static const Fixed& min(const Fixed& value1, const Fixed& value2);

		static const Fixed& max(Fixed& value1, Fixed& value2);
		static const Fixed& min(Fixed& value1, Fixed& value2);

	private :
		int			_fixed_point;
		static const int	_fractional_bit;
};

std::ostream& operator<<(std::ostream& os, const Fixed& value);


#endif
