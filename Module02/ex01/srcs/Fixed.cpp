/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:14:07 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/07 15:31:01 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(value << Fixed::_nb_bits);
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << Fixed::_nb_bits));
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(src.getRawBits());
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &src)
{
	os << src.toFloat();
	return os;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)getRawBits() / (1 << _nb_bits));
}

int Fixed::toInt(void) const
{
	return getRawBits() >> _nb_bits;
}

void Fixed::printBits(void) const
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
