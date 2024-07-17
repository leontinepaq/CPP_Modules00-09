/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:58:43 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/17 17:05:00 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->name = "";
	std::cout << "A new zombie appeared" << std::endl;
}

Zombie::Zombie(std::string name)
{
	if (name.empty())
		this->name = "Unknown zombie";
	else
		this->name = name;
	std::cout << "A new zombie appeared: " << this->name << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " is dead" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
	std::cout << "A zombie have been named: " << this->name << std::endl;
}
