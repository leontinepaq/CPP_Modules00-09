/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:24:22 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/09 15:59:30 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : _type("default")
{
	std::cout << GREEN "[AMateria]" GREY " Default constructor called" RESET << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << GREEN "[AMateria]" GREY " Parameter constructor called" RESET << std::endl;
}


AMateria::AMateria(const AMateria &src)
{
	std::cout << GREEN "[AMateria]" GREY " Copy constructor called" RESET << std::endl;
	_type = src._type;
}


AMateria& AMateria::operator=(const AMateria &src)
{
	std::cout << GREEN "[AMateria]" GREY " Assignment operator called" RESET << std::endl;
	_type = src._type; //pas d'interet ..?
	return *this;
}

AMateria::~AMateria()
{
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


