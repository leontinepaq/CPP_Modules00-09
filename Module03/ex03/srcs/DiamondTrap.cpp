/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:43:57 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/08 13:20:46 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("default_clap_name"), FragTrap("default_clap_name"), ScavTrap("default_clap_name")
{
	_name = "default";
	std::cout << GREY << "DiamondTrap " << _name 
		<< " is created" << RESET << std::endl;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	_maxHitPoints = FragTrap::_maxHitPoints;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name  + "_clap_name"), ScavTrap(name  + "_clap_name")	
{
	_name = name;
	std::cout << GREY << "DiamondTrap " << _name 
		<< " is created" << RESET << std::endl;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	_maxHitPoints = FragTrap::_maxHitPoints;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << GREY << "DiamondTrap " << _name 
		<< " is destroyed" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), FragTrap(src), ScavTrap(src)
{
	*this = src;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;
	_maxHitPoints = src._maxHitPoints;
	return (*this);
}

void	DiamondTrap::attack(const std::string& targetName)
{
	ScavTrap::attack(targetName);
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << BLUE << "DiamondTrap has different names:" << std::endl;
	std::cout << WHITE << "- As a ClapTrap, its name is: " << LIGHT_BLUE << ClapTrap::_name << std::endl;
	std::cout << WHITE << "- As a DiamondTrap, its name is: " << LIGHT_BLUE << DiamondTrap::_name << RESET << std::endl;
}
