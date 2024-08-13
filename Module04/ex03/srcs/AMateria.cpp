/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:24:22 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/13 01:54:52 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : _type("default")
{
	if (SHOW_CONSTRUCTORS)
		std::cout << GREEN "[AMateria]" GREY " Default constructor called" RESET << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	if (SHOW_CONSTRUCTORS)
		std::cout << GREEN "[AMateria]" GREY " Parameter constructor called" RESET << std::endl;
}

AMateria::AMateria(const AMateria &src)
{
	if (SHOW_CONSTRUCTORS)
		std::cout << GREEN "[AMateria]" GREY " Copy constructor called" RESET << std::endl;
	_type = src._type;
}

AMateria::~AMateria()
{
	if (SHOW_CONSTRUCTORS)
		std::cout << GREEN "[AMateria]" GREY " Destructor called" RESET << std::endl;
}

std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << GREEN "*nothing happens*" RESET << std::endl;
}
