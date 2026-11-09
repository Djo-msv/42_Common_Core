#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int Fixed::_fractional_bit = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_fixed_point = 0;
}

Fixed::Fixed(const Fixed &value)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = value;
}

Fixed::Fixed(const int fixed_point)
{
	std::cout << "Int constructor called" << std::endl;
	_fixed_point = fixed_point * (1 << _fractional_bit);
}

Fixed::Fixed(const float floating_point)
{
	std::cout << "Float constructor called" << std::endl;
	_fixed_point = roundf(floating_point * (1 << _fractional_bit));
}

float Fixed::toFloat(void) const
{
	return ((float)_fixed_point / (1 << _fractional_bit));
}

int Fixed::toInt( void ) const
{
	return ((_fixed_point) / (1 << _fractional_bit));
}

Fixed& Fixed::operator=(const Fixed &value)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_fixed_point = value.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& value)
{
    os << value.toFloat();
    return os;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (_fixed_point);
}

void Fixed::setRawBits(int const raw)
{
	_fixed_point = raw;
}



