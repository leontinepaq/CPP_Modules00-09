/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:14:07 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/06 23:47:21 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	// std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(int const value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->setRawBits(value << Fixed::nb_bits);
}

Fixed::Fixed(float const value)
{
	// std::cout << "Float constructor called" << std::endl;
	this->value = floatToFixedValue(value);
}

Fixed::Fixed(const Fixed &src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(src.getRawBits());
	return *this;
}

//pre-increment
const Fixed &Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

//post-increment
const Fixed Fixed::operator++(int)
{
	Fixed tmp = Fixed(this->toFloat());
	this->setRawBits(this->getRawBits() + 1);
	return tmp;
}

//pre-decrement
const Fixed &Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

//post-decrement
const Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->setRawBits(this->getRawBits() - 1);
	return tmp;
}

const Fixed Fixed::operator+(const Fixed &src) const
{
	Fixed res;

	res.setRawBits(this->getRawBits() + src.getRawBits());
	return res;
}

const Fixed Fixed::operator-(const Fixed &src) const
{
	Fixed res;

	res.setRawBits(this->getRawBits() - src.getRawBits());
	return res;
}

const Fixed Fixed::operator*(const Fixed &src) const
{
	Fixed res;
	
	res.setRawBits((this->getRawBits() * src.getRawBits()) >> Fixed::nb_bits);
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
	res.setRawBits((this->getRawBits() << Fixed::nb_bits) / src.getRawBits());
	return res;
}

bool Fixed::operator>(const Fixed &src) const
{
	return this->getRawBits() > src.getRawBits();
}

bool Fixed::operator<(const Fixed &src) const
{
	return this->getRawBits() < src.getRawBits();
}

bool Fixed::operator>=(const Fixed &src) const
{
	return this->getRawBits() >= src.getRawBits();
}

bool Fixed::operator<=(const Fixed &src) const
{
	return this->getRawBits() <= src.getRawBits();
}

bool Fixed::operator==(const Fixed &src) const
{
	return this->getRawBits() == src.getRawBits();
}

bool Fixed::operator!=(const Fixed &src) const
{
	return this->getRawBits() != src.getRawBits();
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
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

int Fixed::floatToFixedValue(float value) const
{
	return (int)roundf(value * (1 << Fixed::nb_bits));
}

float Fixed::toFloat(void) const
{
	return ((float)this->getRawBits() / (1 << this->nb_bits));
}

int Fixed::toInt(void) const
{
	return this->getRawBits() >> this->nb_bits;
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
	int n = this->getRawBits();

	for (int i = 0; i < 32; i++)
	{
		if (i == this->nb_bits)
			bits.insert(0, 1, '|');
		bits.insert(0, 1, (n & 1) + '0');
		n >>= 1;
	}
	std::cout << bits << std::endl;
}