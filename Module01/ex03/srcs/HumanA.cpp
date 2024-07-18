/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:59:47 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/18 16:18:46 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	std::cout << "A new human of type A appears: " << name << ". ";
	std::cout << "They use " << weapon.getType() << " as their weapon." << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "Human of type A " << this->name << " is dead." << std::endl;
}

// void	HumanA::setWeapon(Weapon &weapon)
// {
// 	this->weapon = weapon;
// 	std::cout << this->name << " takes a new weapon: " << weapon.getType() << std::endl;
// }

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
