/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:48:25 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/08 17:07:27 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	std::cout << RED "[WrongAnimal]" GREY " Default constructor called" RESET << std::endl;
	_type = "wrong animal";
}


WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << RED "[WrongAnimal]" GREY " Copy constructor called" RESET << std::endl;
	*this = src;
}


WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << RED "[WrongAnimal]" GREY " Assignment operator called" RESET << std::endl;
	_type = src._type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED "[WrongAnimal]" GREY " Destructor called" RESET << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << RED "*unintelligible sound*" RESET << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return _type;
}

