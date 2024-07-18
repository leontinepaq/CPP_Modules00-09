/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:00:25 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/18 16:18:54 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
	std::cout << "A new human of type B appears: " << name << ". ";
	std::cout << "They have no weapon." << std::endl;
}

// HumanB::HumanB(std::string name, Weapon &weapon) : name(name), weapon(&weapon)
// {
// 	std::cout << "A new human of type B appears: " << name << ". ";
// 	std::cout << "They use " << weapon.getType() << " as their weapon." << std::endl;
// }

HumanB::~HumanB(void)
{
	std::cout << "Human of type B " << this->name << " is dead." << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
	std::cout << this->name << " takes a new weapon: " << weapon.getType() << std::endl;
}

void	HumanB::attack(void)
{
	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " has no weapon to attack with." << std::endl;
}
