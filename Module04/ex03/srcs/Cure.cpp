/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:31:50 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/13 01:55:13 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
	if (SHOW_CONSTRUCTORS)
		std::cout << CYAN "[Cure]" GREY " Default constructor called" RESET << std::endl;
	AMateria::_type = _type;
}

Cure::Cure(const Cure &src) : AMateria(src)
{
	if (SHOW_CONSTRUCTORS)
		std::cout << CYAN "[Cure]" GREY " Copy constructor called" RESET << std::endl;
}

Cure& Cure::operator=(const Cure &src)
{
	if (SHOW_CONSTRUCTORS)
		std::cout << CYAN "[Cure]" GREY " Assignment operator called" RESET << std::endl;
	_type = src._type;
	AMateria::_type = _type;
	return *this;
}

Cure::~Cure()
{
	if (SHOW_CONSTRUCTORS)
		std::cout << CYAN "[Cure]" GREY " Destructor called" RESET << std::endl;
}

std::string const &Cure::getType() const
{
	return _type;
}

Cure	*Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << CYAN "* heals " << target.getName() << "'s wounds *" RESET << std::endl;
}
