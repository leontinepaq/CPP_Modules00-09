/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:59:36 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/08 18:33:56 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << PURPLE "[Cat]" GREY " Default constructor called" RESET << std::endl;
	_type = "cat";
	_brain = new Brain();
}


Cat::Cat(const Cat &src)
{
	std::cout << PURPLE "[Cat]" GREY " Copy constructor called" RESET << std::endl;
	*this = src;
}


Cat& Cat::operator=(const Cat &src)
{
	std::cout << PURPLE "[Cat]" GREY " Assignment operator called" RESET << std::endl;
	_type = src._type;
	_brain = new Brain(*src._brain);
	return *this;
}


Cat::~Cat()
{
	std::cout << PURPLE "[Cat]" GREY " Destructor called" RESET << std::endl;
	delete _brain;
}

void	Cat::makeSound(void) const
{
	std::cout << PURPLE "Miaouuu" RESET << std::endl;
}

Brain *Cat::getBrain(void) const
{
	return _brain;
}
