/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:58:43 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/07 14:16:28 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	_name = "";
	std::cout << "A new zombie appeared" << std::endl;
}

Zombie::Zombie(std::string name)
{
	if (name.empty())
		_name = "Unknown zombie";
	else
		_name = name;
	std::cout << "A new zombie appeared: " << _name << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << _name << " is dead" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	_name = name;
	std::cout << "A zombie have been named: " << _name << std::endl;
}
