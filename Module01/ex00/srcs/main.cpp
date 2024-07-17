/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:46:04 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/17 15:55:04 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


#include <string>
#include <iostream>


int main(void)
{
	Zombie* zombie = newZombie("Marcel I");
	if (zombie)
		zombie->announce();

	randomChump("Albert II");

	delete zombie;
	return (0);
}
