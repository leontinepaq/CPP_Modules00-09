/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:59:36 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/08 17:07:44 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	_type = "cat";
	std::cout << PURPLE "[Cat]" GREY " Default constructor called" RESET << std::endl;
}


Cat::Cat(const Cat &src)
{
	*this = src;
	std::cout << PURPLE "[Cat]" GREY " Copy constructor called" RESET << std::endl;
}


Cat& Cat::operator=(const Cat &src)
{
	_type = src._type;
	std::cout << PURPLE "[Cat]" GREY " Assignment operator called" RESET << std::endl;
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
