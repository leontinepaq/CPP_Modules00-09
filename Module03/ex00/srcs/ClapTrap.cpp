/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:54:08 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/08 13:05:15 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << GREY << "A default ClapTrap is created" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << GREY << "ClapTrap " << _name 
		<< " is created" << RESET << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << GREY << "ClapTrap " << _name 
		<< " is destroyed" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string& targetName)
{
	if (_hitPoints == 0)
	{
		std::cout << RED << "ClapTrap " << _name 
		<< " can't attack, it is already dead." << RESET << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << RED << "ClapTrap " << _name 
		<< " can't attack, it needs more energy points." << RESET << std::endl;
		return ;
	}
	std::cout << BLUE  << "ClapTrap " << LIGHT_BLUE << _name 
		<< BLUE << " attacks " << LIGHT_BLUE << targetName
		<< BLUE << "! It causes " << LIGHT_BLUE << _attackDamage 
		<< BLUE << " points of damage !" << RESET << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << RED << "ClapTrap " << _name 
		<< " is already dead, it can't take more damage." << RESET << std::endl;
		return ;
	}
	if (_hitPoints < amount)
		amount = _hitPoints;
	std::cout << BLUE  << "ClapTrap " << LIGHT_BLUE << _name 
		<< BLUE << " takes damage!" << std::endl
		<< RED << _name << " loses " << amount 
		<< " hit points!" << RESET << std::endl;
	_hitPoints -= amount;
	if (_hitPoints == 0)
	{
		_hitPoints = 0;
		std::cout << RED << "ClapTrap " << _name << " is dead! RIP little angel" << RESET << std::endl;
	}
}


void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << RED << "ClapTrap " << _name 
		<< " can't be repaired, it is already dead." << RESET << std::endl;
		return ;
	}
	if (_hitPoints == 10)
	{
		std::cout << GREEN << "ClapTrap " << _name 
		<< " is already full life, it can't be repaired." << RESET << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << RED << "ClapTrap " << _name 
		<< " can't be repaired, , it needs more energy points.." << RESET << std::endl;
		return ;
	}
	if (amount > 10)
		amount = 10;
	if (_hitPoints + amount > 10)
		amount = 10 - _hitPoints;
	std::cout << BLUE  << "ClapTrap " << LIGHT_BLUE << _name 
		<< BLUE << " is repaired!" << std::endl
		<< GREEN << _name << " gains " << amount 
		<< " hit points!" << RESET << std::endl;
	_hitPoints += amount;
	_energyPoints--;
}

void ClapTrap::displayStatus(void) const
{
	if (_hitPoints == 0)
	{
		std::cout << "--------------------------------" << std::endl;
		std::cout << RED << "ClapTrap " << _name << " is dead!" << RESET << std::endl;
		std::cout << "--------------------------------" << std::endl;
		return ;
	}
	std::cout << "--------------------------------" << std::endl;
	std::cout << LIGHT_BLUE << "ClapTrap " << _name << " status:" << std::endl
		<< WHITE << "Hit points: " << LIGHT_BLUE << _hitPoints << std::endl
		<< WHITE << "Energy points: " << LIGHT_BLUE << _energyPoints << std::endl
		<< WHITE << "Attack damage: " << LIGHT_BLUE << _attackDamage << RESET << std::endl;
	std::cout << "--------------------------------" << std::endl;
}
