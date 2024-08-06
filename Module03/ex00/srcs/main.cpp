/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:08:33 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/06 14:16:04 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define YELLOW "\033[1;33m"

int main(void)
{
	std::string name;
	std::cout << "Enter the name of your ClapTrap: ";
	std::cin >> name;
	std::cout << std::endl;
	
	ClapTrap claptrap(name);
	std::cout << std::endl;

	claptrap.displayStatus();
	std::cout << std::endl;

	std::cout << YELLOW << "ATTACK" << std::endl;
	claptrap.attack("enemy");
	std::cout << std::endl;
	claptrap.displayStatus();
	std::cout << std::endl;

	std::cout << YELLOW << "TAKE DAMAGE : 5" << std::endl;
	claptrap.takeDamage(5);
	std::cout << std::endl;
	claptrap.displayStatus();
	std::cout << std::endl;

	std::cout << YELLOW << "REPAIRED : 2" << std::endl;
	claptrap.beRepaired(2);
	std::cout << std::endl;
	claptrap.displayStatus();
	std::cout << std::endl;

	std::cout << YELLOW << "TAKE DAMAGE : 8" << std::endl;
	claptrap.takeDamage(8);
	std::cout << std::endl;
	claptrap.displayStatus();
	std::cout << std::endl;

	std::cout << YELLOW << "TAKE DAMAGE : 10" << std::endl;
	claptrap.takeDamage(10);
	std::cout << std::endl;

	std::cout << YELLOW << "REPAIRED : 10" << std::endl;
	claptrap.beRepaired(10);
	std::cout << std::endl;

	return (0);
}