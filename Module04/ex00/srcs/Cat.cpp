/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:59:36 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/13 03:06:12 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << PURPLE "[Cat]" GREY " Default constructor called" RESET << std::endl;
	_type = "cat";
}


Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << PURPLE "[Cat]" GREY " Copy constructor called" RESET << std::endl;
	_type = src._type;
}


Cat& Cat::operator=(const Cat &src)
{
	std::cout << PURPLE "[Cat]" GREY " Assignment operator called" RESET << std::endl;
	_type = src._type;
	return *this;
}


Cat::~Cat()
{
	std::cout << PURPLE "[Cat]" GREY " Destructor called" RESET << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << PURPLE "Miaouuu" RESET << std::endl;
}
