/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:54:08 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/06 14:25:39 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energyPoints(10), _attackDamage(0)
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
	_hitpoints = src._hitpoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string& targetName)
{
	if (_hitpoints == 0)
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
	if (_hitpoints == 0)
	{
		std::cout << RED << "ClapTrap " << _name 
		<< " is already dead, it can't take more damage." << RESET << std::endl;
		return ;
	}
	if (_hitpoints < amount)
		amount = _hitpoints;
	std::cout << BLUE  << "ClapTrap " << LIGHT_BLUE << _name 
		<< BLUE << " takes damage!" << std::endl
		<< RED << _name << " loses " << amount 
		<< " hit points!" << RESET << std::endl;
	_hitpoints -= amount;
	if (_hitpoints == 0)
	{
		_hitpoints = 0;
		std::cout << RED << "ClapTrap " << _name << " is dead! RIP little angel" << RESET << std::endl;
	}
}


void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitpoints == 10)
	{
		std::cout << GREEN << "ClapTrap " << _name 
		<< " is already full life, it can't be repaired." << RESET << std::endl;
		return ;
	}
	if (_hitpoints == 0)
	{
		std::cout << RED << "ClapTrap " << _name 
		<< " can't be repaired, it is already dead." << RESET << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << RED << "ClapTrap " << _name 
		<< " can't be repaired, , it needs more energy points.." << RESET << std::endl;
		return ;
	}
	if (_hitpoints + amount > 10)
		amount = 10 - _hitpoints;
	std::cout << BLUE  << "ClapTrap " << LIGHT_BLUE << _name 
		<< BLUE << " is repaired!" << std::endl
		<< GREEN << _name << " gains " << amount 
		<< " hit points!" << RESET << std::endl;
	_hitpoints += amount;
	_energyPoints--;
}

void ClapTrap::displayStatus(void) const
{
	if (_hitpoints == 0)
	{
		std::cout << "--------------------------------" << std::endl;
		std::cout << RED << "ClapTrap " << _name << " is dead!" << RESET << std::endl;
		std::cout << "--------------------------------" << std::endl;
		return ;
	}
	std::cout << "--------------------------------" << std::endl;
	std::cout << LIGHT_BLUE << "ClapTrap " << _name << " status:" << std::endl
		<< WHITE << "Hit points: " << LIGHT_BLUE << _hitpoints << std::endl
		<< WHITE << "Energy points: " << LIGHT_BLUE << _energyPoints << std::endl
		<< WHITE << "Attack damage: " << LIGHT_BLUE << _attackDamage << RESET << std::endl;
	std::cout << "--------------------------------" << std::endl;
}
