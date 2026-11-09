#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int Fixed::_fractional_bit = 8;

Fixed::Fixed(void)
{
	_fixed_point = 0;
}

Fixed::Fixed(const Fixed &value)
{
	_fixed_point = value.getRawBits();
}

Fixed::Fixed(const int fixed_point)
{
	_fixed_point = fixed_point * 256;
}

Fixed::Fixed(const float floating_point)
{
	_fixed_point = roundf(floating_point * 256);
}

float Fixed::toFloat(void) const
{
	return ((float)_fixed_point / 256.0f);
}

int Fixed::toInt( void ) const
{
	return ((_fixed_point) / 256);
}

Fixed& Fixed::operator=(const Fixed &value)
{
	_fixed_point = value.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
}

int	Fixed::getRawBits(void) const
{
	return (_fixed_point);
}

void Fixed::setRawBits(int const raw)
{
	_fixed_point = raw;
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->toFloat() < other.toFloat();
}

bool Fixed::operator>(const Fixed& other) const
{
    return this->toFloat() > other.toFloat();
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->toFloat() <= other.toFloat();
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->toFloat() >= other.toFloat();
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->toFloat() == other.toFloat();
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->toFloat() != other.toFloat();
}


Fixed Fixed::operator++(int)
{
	Fixed	tmp = *this;
	_fixed_point++;
	return (tmp);
}

Fixed &Fixed::operator++(void)
{
	_fixed_point++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	tmp = *this;
	_fixed_point--;
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	_fixed_point--;
	return (*this);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed    result;

    result._fixed_point = this->_fixed_point + other.getRawBits();
    return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed    result;

    result._fixed_point = this->_fixed_point - other.getRawBits();
    return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed    result;

    long a = this->_fixed_point;
	long b = other._fixed_point;
    result._fixed_point = (a * b) / (1 << _fractional_bit);
    return (result);
}

Fixed Fixed::operator/(Fixed const & other) const
{
    Fixed    result;

    long tmp = (1 << _fractional_bit) * this->_fixed_point ;
    result._fixed_point = roundf(tmp / (float)other._fixed_point);
    return (result);
}

std::ostream& operator<<(std::ostream& os, const Fixed& value)
{
    os << value.toFloat();
    return os;
}

const Fixed& Fixed::max(const Fixed& value1, const Fixed& value2)
{
    return (value1 < value2 ? value2 : value1);
}

const Fixed& Fixed::min(const Fixed& value1, const Fixed& value2)
{
    return (value1 < value2 ? value1 : value2);
}

const Fixed& Fixed::max(Fixed& value1, Fixed& value2)
{
    return (value1 < value2 ? value2 : value1);
}

const Fixed& Fixed::min(Fixed& value1, Fixed& value2)
{
    return (value1 < value2 ? value1 : value2);
}
