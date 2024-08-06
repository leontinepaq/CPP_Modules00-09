/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:08:33 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/06 16:30:02 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#define YELLOW "\033[1;33m"

int main(void)
{
	std::string name;
	std::cout << "Enter the name of your ScavTrap: ";
	std::cin >> name;
	std::cout << std::endl;

	ScavTrap scav(name);
	std::cout << std::endl;

	scav.displayStatus();
	std::cout << std::endl;

	std::cout << YELLOW << "ATTACK" << RESET << std::endl;
	scav.attack("enemy");
	std::cout << std::endl;
	scav.displayStatus();
	std::cout << std::endl;

	std::cout << YELLOW << "TAKE DAMAGE : 5" << RESET << std::endl;
	scav.takeDamage(5);
	std::cout << std::endl;
	scav.displayStatus();
	std::cout << std::endl;

	std::cout << YELLOW << "REPAIRED : 2" << RESET << std::endl;
	scav.beRepaired(2);
	std::cout << std::endl;
	scav.displayStatus();
	std::cout << std::endl;

	return (0);
}