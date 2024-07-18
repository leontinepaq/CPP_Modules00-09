/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:42:32 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/17 17:59:35 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
	std::cout << "Weapon of type " << type << " created" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon of type " << this->type << " destroyed" << std::endl;
}

std::string const &Weapon::getType(void)
{
	std::string const &ref = this->type;
	return (ref);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
	std::cout << "Weapon type set to " << type << std::endl;
}
