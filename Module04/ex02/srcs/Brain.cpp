/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:13:25 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/09 14:36:52 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << BLUE "[Brain]" GREY " Default constructor called" << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << BLUE "[Brain]" GREY " Copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = src._ideas[i];
}

Brain& Brain::operator=(const Brain &src)
{
	std::cout << BLUE "[Brain]" GREY " Assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = src._ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << BLUE "[Brain]" GREY " Destructor called" << std::endl;
}

void Brain::setIdea(int i, std::string idea)
{
	_ideas[i] = idea;
}
std::string Brain::getIdea(int i) const
{
	return _ideas[i];
}
