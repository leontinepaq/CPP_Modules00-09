/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:46:04 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/07 12:31:54 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define BOLD "\033[1m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int main(void)
{
	std::cout << BOLD << "Creating a zombie that can be used in another function" << RESET << std::endl;
	std::string name1;
	std::cout << BLUE << "Enter the name of the first zombie: ";
	std::cin >> name1;
	std::cout << RESET;
	Zombie* zombie = newZombie(name1);
	std::cout << std::endl;
	
	std::cout << BOLD << "Announcing the first zombie" << RESET << std::endl;
	if (zombie)
		zombie->announce();
	std::cout << std::endl;
		
	std::cout << BOLD << "Creating a zombie that will be destroyed after announcing itself" << RESET << std::endl;
	std::string name2;
	std::cout << BLUE << "Enter the name of the second zombie: ";
	std::cin >> name2;
	std::cout << RESET;
	randomChump(name2);
	std::cout << std::endl;

	std::cout << BOLD << "Deleting the first zombie" << RESET << std::endl;
	delete zombie;
	return (0);
}
