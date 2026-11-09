#include <iostream>
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
	_fixed_point = value.getRawBits();
}

Fixed& Fixed::operator=(Fixed &value)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_fixed_point = value.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixed_point);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixed_point = raw;
}
