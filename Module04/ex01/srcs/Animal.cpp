/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:43:59 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/13 03:07:06 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	std::cout << ORANGE "[Animal]" GREY " Default constructor called" RESET << std::endl;
	_type = "unclassified animal";
}


Animal::Animal(const Animal &src)
{
	std::cout << ORANGE "[Animal]" GREY " Copy constructor called" RESET << std::endl;
	_type = src._type;
}


Animal& Animal::operator=(const Animal &src)
{
	std::cout << ORANGE "[Animal]" GREY " Assignment operator called" RESET << std::endl;
	_type = src._type;
	return *this;
}

Animal::~Animal()
{
	std::cout << ORANGE "[Animal]" GREY " Destructor called" RESET << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << ORANGE "*unintelligible sound*" RESET << std::endl;
}

std::string	Animal::getType(void) const
{
	return _type;
}

