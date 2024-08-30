/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:43:57 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/30 17:39:19 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("default_clap_name"), FragTrap(), ScavTrap()
{
	_name = "default";
	std::cout << GREY << "DiamondTrap " << _name 
		<< " is created" << RESET << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	_maxHitPoints = 100;
}
//si j'ai bien compris :
//les membres sont partagés entre les classes -> besoin de initialisation pour les valeurs particulières dans cette classe (sinon prennent valeurs de la derniere classe (ScavTrap))
//different pour _name car la classe Diamond a son propre attribut _name

DiamondTrap::DiamondTrap(std::string name) 
	: ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap()
{
	_name = name;
	std::cout << GREY << "DiamondTrap " << _name 
			  << " is created" << RESET << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	_maxHitPoints = 100;
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
