/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:31:53 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/08 17:07:39 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << GREEN "[Dog]" GREY " Default constructor called" RESET << std::endl;
	_type = "dog";
}


Dog::Dog(const Dog &src)
{
	*this = src;
	std::cout << GREEN "[Dog]" GREY " Copy constructor called" RESET << std::endl;
}


Dog& Dog::operator=(const Dog &src)
{
	_type = src._type;
	std::cout << GREEN "[Dog]" GREY " Assignment operator called" RESET << std::endl;
	return *this;
}


Dog::~Dog()
{
	std::cout << GREEN "[Dog]" GREY " Destructor called" RESET << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << GREEN "Wouf wouf" RESET << std::endl;
}
