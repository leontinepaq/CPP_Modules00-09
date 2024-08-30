/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:08:33 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/30 16:40:16 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#define YELLOW "\033[1;33m"

int main(void)
{
	std::string name;
	std::cout << "Enter the name of your DiamondTrap: ";
	std::cin >> name;
	std::cout << std::endl;

	DiamondTrap diamond(name);
	std::cout << std::endl;

	std::cout << YELLOW << "WHO AM I" << RESET << std::endl;
	diamond.whoAmI();
	std::cout << std::endl;


	diamond.displayStatus();
	std::cout << std::endl;

	std::cout << YELLOW << "ATTACK" << RESET << std::endl;
	diamond.attack("enemy");
	std::cout << std::endl;
	diamond.displayStatus();
	std::cout << std::endl;

	std::cout << YELLOW << "GUARD GATE" << RESET << std::endl;
	diamond.guardGate();
	std::cout << std::endl;

	std::cout << YELLOW << "HIGH FIVES GUYS" << RESET << std::endl;
	diamond.highFivesGuys();
	std::cout << std::endl;


	return (0);
}