/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:01:39 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/13 02:23:06 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>
Character::Character(void) : _name("default")
{
	if (SHOW_CONSTRUCTORS)
		std::cout << ORANGE "[Character]" GREY " Default constructor called" RESET << std::endl;
	for (size_t i = 0; i < NB_MATERIA; i++)
		_inventory[i] = 0;
}

Character::Character(std::string name)
{
	if (SHOW_CONSTRUCTORS)
		std::cout << ORANGE "[Character]" GREY " Parameter constructor called" RESET << std::endl;
	_name = name;
	for (size_t i = 0; i < NB_MATERIA; i++)
		_inventory[i] = 0;
}

Character::Character(const Character &src)
{
	if (SHOW_CONSTRUCTORS)
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
	if (SHOW_CONSTRUCTORS)
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

Character::~Character(void)
{
	if (SHOW_CONSTRUCTORS)
		std::cout << ORANGE "[Character]" GREY " Destructor called" RESET << std::endl;
	for (size_t i = 0; i < NB_MATERIA; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

std::string const &Character::getName(void) const
{
	return (_name);
}

size_t Character::getNbMateria(void) const
{
	size_t res = 0;
	for (size_t i = 0; i < NB_MATERIA; i++)
	{
		if (_inventory[i])
			res++;
	}
	return (res);
}

bool Character::_inInventory(AMateria *m) const
{
	for (size_t i = 0; i < NB_MATERIA; i++)
	{
		if (_inventory[i] == m)
			return (true);
	}
	return (false);
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << RED << "Invalid materia" RESET << std::endl;
		return ;
	}
	for (size_t i = 0; i < NB_MATERIA; i++)
	{
		if (!_inventory[i])
		{
			if (SHOW_ALL_MESSAGES)
				std::cout << ORANGE << _name << " now have " << m->getType() << " in the pocket "
					<< i << " of its inventory." RESET << std::endl;
			if (_inInventory(m))
				_inventory[i] = m->clone();
			else
				_inventory[i] = m;
			return ;
		}
	}
	std::cout << RED << _name << "'s inventory is full, you can't equip it." RESET << std::endl;
	std::cout << ORANGE << "The materia falls on the ground." RESET << std::endl;
	if(!_inInventory(m))
		delete m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= NB_MATERIA || !_inventory[idx])
	{
		std::cout << RED << _name << " doesn't have any materia in the pocket "
			<< idx << " of its inventory." RESET << std::endl;
		return ;
	}
	if (SHOW_ALL_MESSAGES)
		std::cout << ORANGE << _name << " puts the materia from the pocket "
			<< idx << " of its inventory on the ground." RESET << std::endl;
	delete _inventory[idx];
	_inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= NB_MATERIA)
	{
		std::cout << RED << "Invalid pocket number" RESET << std::endl;
		return ;
	}
	if (!_inventory[idx])
	{
		std::cout << RED << _name << " doesn't have any materia in the pocket "
			<< idx << " of its inventory." RESET << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
}

void Character::displayInventory(void) const
{
	if (!SHOW_ALL_MESSAGES)
		return ;
	std::cout << ORANGE << _name << " has the following materias in its inventory." RESET << std::endl;
	for (size_t i = 0; i < NB_MATERIA; i++)
	{
		if (_inventory[i])
			std::cout << ORANGE "- Pocket " << i << ": " << _inventory[i]->getType() << RESET << std::endl;
		else
			std::cout << ORANGE "- Pocket " << i << ": empty" RESET << std::endl;
	}
}
