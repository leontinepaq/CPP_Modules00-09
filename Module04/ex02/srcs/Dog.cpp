/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:31:53 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/09 14:41:37 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << GREEN "[Dog]" GREY " Default constructor called" RESET << std::endl;
	_type = "dog";
	_brain = new Brain();
}


Dog::Dog(const Dog &src)
{
	std::cout << GREEN "[Dog]" GREY " Copy constructor called" RESET << std::endl;
	*_brain = *src._brain;
	_type = src._type;
}


Dog& Dog::operator=(const Dog &src)
{
	std::cout << GREEN "[Dog]" GREY " Assignment operator called" RESET << std::endl;
	_brain = new Brain(*src._brain);
	_type = src._type;
	return *this;
}


Dog::~Dog()
{
	std::cout << GREEN "[Dog]" GREY " Destructor called" RESET << std::endl;
	delete _brain;
}

void	Dog::makeSound(void) const
{
	std::cout << GREEN "Wouf wouf" RESET << std::endl;
}

void Dog::setIdea(int i, std::string idea)
{
	_brain->setIdea(i, idea);
}

std::string Dog::getIdea(int i) const
{
	return _brain->getIdea(i);
}

