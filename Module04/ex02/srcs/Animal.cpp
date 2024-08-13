/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:43:59 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/13 03:07:34 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

AAnimal::AAnimal()
{
	std::cout << ORANGE "[Animal]" GREY " Default constructor called" RESET << std::endl;
	_type = "unclassified animal";
}


AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << ORANGE "[Animal]" GREY " Copy constructor called" RESET << std::endl;
	_type = src._type;
}


AAnimal& AAnimal::operator=(const AAnimal &src)
{
	std::cout << ORANGE "[Animal]" GREY " Assignment operator called" RESET << std::endl;
	_type = src._type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << ORANGE "[Animal]" GREY " Destructor called" RESET << std::endl;
}
