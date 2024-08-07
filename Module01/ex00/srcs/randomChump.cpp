/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:15:10 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/07 12:21:20 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump( std::string name )
{
	Zombie zombie(name);
	zombie.announce();
}

void	randomChump(PreventNull* ptr)
{
	(void)ptr;
	std::cerr << "Error: NULL pointer in a string function" << std::endl;
}
