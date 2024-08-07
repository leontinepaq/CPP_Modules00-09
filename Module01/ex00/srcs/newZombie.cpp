/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:05:01 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/07 12:20:57 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*  newZombie( std::string name )
{
	Zombie* newZombie = new Zombie(name);
	return (newZombie);
}

Zombie*  newZombie(PreventNull* ptr)
{
	(void)ptr;
	std::cerr << "Error: NULL pointer in a string function" << std::endl;
	return (NULL);
}
