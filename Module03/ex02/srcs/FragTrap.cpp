/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:43:40 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/30 17:04:39 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << GREY << "A default FragTrap is created" << RESET << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	_maxHitPoints = 100;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << GREY << "FragTrap " << _name 
		<< " is created" << RESET << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	_maxHitPoints = 100;
}

FragTrap::~FragTrap(void)
{
	std::cout << GREY << "FragTrap " << _name 
		<< " is destroyed" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	*this = src;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;
	_maxHitPoints = src._maxHitPoints;
	return (*this);
}

void FragTrap::attack(const std::string& targetName)
{
	if (_hitPoints == 0)
	{
		std::cout << RED << "FragTrap " << _name 
		<< " can't attack, it is already dead." << RESET << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << RED << "FragTrap " << _name 
		<< " can't attack, it needs more energy points." << RESET << std::endl;
		return ;
	}
	std::cout << BLUE  << "FragTrap " << LIGHT_BLUE << _name 
		<< BLUE << " attacks " << LIGHT_BLUE << targetName
		<< BLUE << "! It causes " << LIGHT_BLUE << _attackDamage 
		<< BLUE << " points of damage !" << RESET << std::endl;
	_energyPoints--;
}

void FragTrap::highFivesGuys(void) const
{
	std::cout << BLUE << "FragTrap " << LIGHT_BLUE << _name 
		<< BLUE << " asks : High five guys !?" << RESET << std::endl;
}
