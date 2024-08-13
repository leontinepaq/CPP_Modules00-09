/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:51:18 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/13 01:55:35 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
	if (SHOW_CONSTRUCTORS)
		std::cout << BLUE "[Ice]" GREY " Default constructor called" RESET << std::endl;
}

Ice::Ice(const Ice &src) : AMateria(src)
{
	if (SHOW_CONSTRUCTORS)
		std::cout << BLUE "[Ice]" GREY " Copy constructor called" RESET << std::endl;
}

Ice& Ice::operator=(const Ice &src)
{
	if (SHOW_CONSTRUCTORS)
		std::cout << BLUE "[Ice]" GREY " Assignment operator called" RESET << std::endl;
	_type = src._type;
	return *this;
}

Ice::~Ice()
{
	if (SHOW_CONSTRUCTORS)
		std::cout << BLUE "[Ice]" GREY " Destructor called" RESET << std::endl;
}

std::string const &Ice::getType() const
{
	return _type;
}

Ice* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << BLUE "* shoots an ice bolt at " << target.getName() << " *" RESET << std::endl;
}
