/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:14:07 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/07 15:32:54 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	// std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

Fixed::Fixed(int const value)
{
	// std::cout << "Int constructor called" << std::endl;
	setRawBits(value << Fixed::_nb_bits);
}

Fixed::Fixed(float const value)
{
	// std::cout << "Float constructor called" << std::endl;
	_value = floatToFixedValue(value);
}

Fixed::Fixed(const Fixed &src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(src.getRawBits());
	return *this;
}

//pre-increment
const Fixed &Fixed::operator++(void)
{
	setRawBits(getRawBits() + 1);
	return *this;
}

//post-increment
const Fixed Fixed::operator++(int)
{
	Fixed tmp = Fixed(toFloat());
	setRawBits(getRawBits() + 1);
	return tmp;
}

//pre-decrement
const Fixed &Fixed::operator--(void)
{
	setRawBits(getRawBits() - 1);
	return *this;
}

//post-decrement
const Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	setRawBits(getRawBits() - 1);
	return tmp;
}

const Fixed Fixed::operator+(const Fixed &src) const
{
	Fixed res;

	res.setRawBits(getRawBits() + src.getRawBits());
	return res;
}

const Fixed Fixed::operator-(const Fixed &src) const
{
	Fixed res;

	res.setRawBits(getRawBits() - src.getRawBits());
	return res;
}

const Fixed Fixed::operator*(const Fixed &src) const
{
	Fixed res;
	
	res.setRawBits((getRawBits() * src.getRawBits()) >> Fixed::_nb_bits);
	return res;
}

const Fixed Fixed::operator/(const Fixed &src) const
{
	Fixed res;

	if (src.getRawBits() == 0)
	{
		std::cerr << "Division by zero" << std::endl;
		return Fixed(0);
	}
	res.setRawBits((getRawBits() << Fixed::_nb_bits) / src.getRawBits());
	return res;
}

bool Fixed::operator>(const Fixed &src) const
{
	return getRawBits() > src.getRawBits();
}

bool Fixed::operator<(const Fixed &src) const
{
	return getRawBits() < src.getRawBits();
}

bool Fixed::operator>=(const Fixed &src) const
{
	return getRawBits() >= src.getRawBits();
}

bool Fixed::operator<=(const Fixed &src) const
{
	return getRawBits() <= src.getRawBits();
}

bool Fixed::operator==(const Fixed &src) const
{
	return getRawBits() == src.getRawBits();
}

bool Fixed::operator!=(const Fixed &src) const
{
	return getRawBits() != src.getRawBits();
}

std::ostream &operator<<(std::ostream &os, const Fixed &src)
{
	os << src.toFloat();
	return os;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

int Fixed::floatToFixedValue(float value) const
{
	return (int)roundf(value * (1 << Fixed::_nb_bits));
}

float Fixed::toFloat(void) const
{
	return ((float)getRawBits() / (1 << _nb_bits));
}

int Fixed::toInt(void) const
{
	return getRawBits() >> _nb_bits;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

void Fixed::printBits(void)
{
	std::string bits;
	int n = getRawBits();

	for (int i = 0; i < 32; i++)
	{
		if (i == _nb_bits)
			bits.insert(0, 1, '|');
		bits.insert(0, 1, (n & 1) + '0');
		n >>= 1;
	}
	std::cout << bits << std::endl;
}
