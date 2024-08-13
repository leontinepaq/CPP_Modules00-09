/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:59:36 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/13 03:08:11 by lpaquatt         ###   ########.fr       */
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


Cat::Cat(const Cat &src) : AAnimal(src)
{
	std::cout << PURPLE "[Cat]" GREY " Copy constructor called" RESET << std::endl;
	_type = src._type;
	_brain = new Brain(*src._brain);
}


Cat& Cat::operator=(const Cat &src)
{
	std::cout << PURPLE "[Cat]" GREY " Assignment operator called" RESET << std::endl;
	_type = src._type;
	*_brain = *src._brain;
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

void	Cat::setIdea(int i, std::string idea)
{
	_brain->setIdea(i, idea);
}

std::string Cat::getIdea(int i) const
{
	return _brain->getIdea(i);
}
