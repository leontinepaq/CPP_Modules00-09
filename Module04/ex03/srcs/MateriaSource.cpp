/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:26:17 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/12 23:43:16 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void)
{
	if (SHOW_CONSTRUCTORS)
		std::cout << PURPLE "[MateriaSource]" GREY " Default constructor called" RESET << std::endl;
	for (size_t i = 0; i < NB_MATERIA; i++)
		_inventory[i] = 0;
}


MateriaSource::MateriaSource(const MateriaSource &src)
{
	if (SHOW_CONSTRUCTORS)
		std::cout << PURPLE "[MateriaSource]" GREY " Copy constructor called" RESET << std::endl;
	for (size_t i = 0; i < NB_MATERIA; i++)
	{
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &src)
{
	if (SHOW_CONSTRUCTORS)
		std::cout << PURPLE "[MateriaSource]" GREY " Assignment operator called" RESET << std::endl;
	for (size_t i = 0; i < NB_MATERIA; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
	return *this;
}

MateriaSource::~MateriaSource(void)
{
	if (SHOW_CONSTRUCTORS)
		std::cout << PURPLE "[MateriaSource]" GREY " Destructor called" RESET << std::endl;
	for (size_t i = 0; i < NB_MATERIA; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (!materia)
	{
		std::cout << RED "Invalid materia" RESET << std::endl;
		return ;
	}
	for (size_t i = 0; i < NB_MATERIA; i++)
	{
		if (!_inventory[i])
		{
			if (SHOW_ALL_MESSAGES)
				std::cout << PURPLE "A new materia '" << materia->getType() << "' is stored in your spell book (page " << i << ")!" RESET << std::endl;
			_inventory[i] = materia->clone();
			delete materia; //if not in my inventory
			return ;
		}
	}
	std::cout << RED "Your spell book is full, you can't learn more materia!" RESET << std::endl;
	delete materia;
}

void MateriaSource::eraseMateria(int idx)
{
	if (idx < 0 || idx >= NB_MATERIA)
	{
		std::cout << RED "You can't erase a materia from a page that doesn't exist!" RESET << std::endl;
		return ;
	}
	if (!_inventory[idx])
	{
		std::cout << RED "You can't erase a materia from a page that is already empty!" RESET << std::endl;
		return ;
	}
	if (SHOW_ALL_MESSAGES)
		std::cout << PURPLE "You forgot the materia stored in your spell book page " << idx << "." RESET << std::endl;
	delete _inventory[idx];
	_inventory[idx] = 0;
}

void	MateriaSource::displayKnownMaterias(void) const
{
	if (!SHOW_ALL_MESSAGES)
		return ;
	std::cout << PURPLE "Your spell book contains the following materias:" RESET << std::endl;
	for (size_t i = 0; i < NB_MATERIA; i++)
	{
		if (_inventory[i])
			std::cout << PURPLE "- Page " << i << ": " << _inventory[i]->getType() << RESET << std::endl;
		else
			std::cout << PURPLE "- Page " << i << ": empty" RESET << std::endl;
	}
}


AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < NB_MATERIA; i++)
	{
		if (_inventory[i] && _inventory[i]->getType() == type)
		{
			if (SHOW_ALL_MESSAGES)
				std::cout << PURPLE "A new materia '" << type << "' is created from your spell book." RESET << std::endl;
			return _inventory[i]->clone();
		}
	}
	std::cout << RED "You can't create a materia '" << type << "', you don't have it in your spell book !" RESET << std::endl;
	return 0;
}
