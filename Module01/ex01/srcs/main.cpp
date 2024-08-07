/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:46:04 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/07 13:34:22 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define BLUE "\033[0;34m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

int main(void)
{
	int N;
	std::cout << BLUE << "Enter the number of zombies you want to create: ";	
	std::cin >> N;
	std::string name;
	std::cout << "Enter a name for the horde: ";
	std::cin >> name;
	std::cout << RESET;
	std::cout << std::endl;

	std::cout << BOLD << "*Creating a horde of " << N << " zombies*" << RESET << std::endl;
	Zombie* zombie = zombieHorde(N, name);
	std::cout << std::endl;
	if (!zombie)
		return (1);

	for (int i = 0; i < N; i++)
	{
		std::cout << BOLD << "*Announce from zombie " << i + 1 << "*" << RESET << std::endl;
		zombie[i].announce();
	}
	std::cout << std::endl;
	
	std::cout << BOLD << "*Deleting the horde*" << RESET << std::endl;
	delete [] zombie;
	return (0);
}
