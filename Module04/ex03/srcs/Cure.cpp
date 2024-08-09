/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:31:50 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/09 18:18:43 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cure.hpp"
#include <iostream>

Cure::Cure() : _type("cure")
{
	std::cout << CYAN "[Cure]" GREY " Default constructor called" RESET << std::endl;
}

Cure::Cure(const Cure &src)
{
	std::cout << CYAN "[Cure]" GREY " Copy constructor called" RESET << std::endl;
	_type = src._type;
}

Cure& Cure::operator=(const Cure &src)
{
	std::cout << CYAN "[Cure]" GREY " Assignment operator called" RESET << std::endl;
	_type = src._type;
	return *this;
}

Cure::~Cure()
{
	std::cout << CYAN "[Cure]" GREY " Destructor called" RESET << std::endl;
}

std::string const &Cure::getType() const
{
	return _type;
}

void Cure::use(ICharacter& target)
{
	std::cout << CYAN "* heals " << target.getName() << " 's wounds *" RESET << std::endl;
}

Cure	*Cure::clone() const
{
	return new Cure();
}
