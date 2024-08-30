/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:56:55 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/30 17:04:11 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << GREY << "A default ScavTrap is created" << RESET << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_maxHitPoints = 100;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << GREY << "ScavTrap " << _name 
		<< " is created" << RESET << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_maxHitPoints = 100;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << GREY << "ScavTrap " << _name 
		<< " is destroyed" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	*this = src;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;
	_maxHitPoints = src._maxHitPoints;
	return (*this);
}

void ScavTrap::attack(const std::string& targetName)
{
	if (_hitPoints == 0)
	{
		std::cout << RED << "ScavTrap " << _name 
		<< " can't attack, it is already dead." << RESET << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << RED << "ScavTrap " << _name 
		<< " can't attack, it needs more energy points." << RESET << std::endl;
		return ;
	}
	std::cout << BLUE  << "ScavTrap " << LIGHT_BLUE << _name 
		<< BLUE << " attacks " << LIGHT_BLUE << targetName
		<< BLUE << "! It causes " << LIGHT_BLUE << _attackDamage 
		<< BLUE << " points of damage !" << RESET << std::endl;
	_energyPoints--;
}

void ScavTrap::guardGate(void)
{
	if (_hitPoints == 0)
	{
		std::cout << RED << "ScavTrap " << _name 
		<< " can't guard the gate, it is already dead." << RESET << std::endl;
		return ;
	}
	std::cout << GREEN << "ScavTrap " << _name 
		<< " is now in Gate keeper mode." << RESET << std::endl;
}
