/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:14:07 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/07 11:35:57 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define BLUE "\033[0;34m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"
#define RESET "\033[0m"

Fixed::Fixed(void)
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << BLUE << "Copy assignment operator called" << RESET << std::endl;
	this->setRawBits(src.getRawBits());
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << MAGENTA << "getRawBits member function called" << RESET << std::endl;
	return this->value;
}

void Fixed::setRawBits( int const raw )
{
	this->value = raw;
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
