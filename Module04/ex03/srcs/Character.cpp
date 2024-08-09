/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:01:39 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/09 18:15:01 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>
Character::Character()
{
	std::cout << ORANGE "[Character]" GREY " Default constructor called" RESET << std::endl;
	for (size_t i = 0; i < NB_MATERIA; i++)
		_inventory[i] = 0;
}

Character::Character(std::string name)
{
	std::cout << ORANGE "[Character]" GREY " Parameter constructor called" RESET << std::endl;
	_name = name;
	for (size_t i = 0; i < NB_MATERIA; i++)
		_inventory[i] = 0;
}

Character::Character(const Character &src)
{
	std::cout << ORANGE "[Character]" GREY " Copy constructor called" RESET << std::endl;
	_name = src.getName();
	for (size_t i = 0; i < NB_MATERIA; i++)
	{
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
}

Character& Character::operator=(const Character &src)
{
	std::cout << ORANGE "[Character]" GREY " Assignment operator called" RESET << std::endl;
	_name = src.getName();
	for (size_t i = 0; i < NB_MATERIA; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
	return (*this);
}

Character::~Character()
{
	std::cout << ORANGE "[Character]" GREY " Destructor called" RESET << std::endl;
	for (size_t i = 0; i < NB_MATERIA; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

std::string const &Character::getName() const
{
	return (_name);
}

size_t Character::getNbMateria() const
{
	size_t res = 0;
	for (size_t i = 0; i < NB_MATERIA; i++)
	{
		if (_inventory[i])
			res++;
	}
	return (res);
}

void Character::equip(AMateria* m)
{
	if (getNbMateria() == NB_MATERIA)
	{
		std::cout << ORANGE "* Inventory is full *" RESET << std::endl;
		return ;
	}
	size_t i = 0;
	while (_inventory[i])
		i++;
	_inventory[i] = m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= NB_MATERIA || !_inventory[idx])
	{
		std::cout << ORANGE "* " << _name << " doesn't have any materia in its "
			<< idx << " pocket of its inventory *" RESET << std::endl;
		return ;
	}
	_inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= NB_MATERIA || !_inventory[idx])
	{
		std::cout << ORANGE "* " << _name << " doesn't have any materia in its "
			<< idx << " pocket of its inventory *" RESET << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
}
