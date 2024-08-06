/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:08:33 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/06 16:51:25 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#define YELLOW "\033[1;33m"

int main(void)
{
	std::string name;
	std::cout << "Enter the name of your FragTrap: ";
	std::cin >> name;
	std::cout << std::endl;

	FragTrap frag(name);
	std::cout << std::endl;

	frag.displayStatus();
	std::cout << std::endl;

	std::cout << YELLOW << "ATTACK" << RESET << std::endl;
	frag.attack("enemy");
	std::cout << std::endl;
	frag.displayStatus();
	std::cout << std::endl;

	std::cout << YELLOW << "TAKE DAMAGE : 5" << RESET << std::endl;
	frag.takeDamage(5);
	std::cout << std::endl;
	frag.displayStatus();
	std::cout << std::endl;

	std::cout << YELLOW << "REPAIRED : 2" << RESET << std::endl;
	frag.beRepaired(2);
	std::cout << std::endl;
	frag.displayStatus();
	std::cout << std::endl;

	std::cout << YELLOW << "HIGH FIVE" << RESET << std::endl;
	frag.highFivesGuys();
	std::cout << std::endl;

	return (0);
}