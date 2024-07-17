/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:46:04 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/17 17:23:02 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


# include <iostream>
# include <cstdlib>
# include <string>
# include <iomanip>
# include <limits>
# include <sstream> 


int main(void)
{
	int N = 6;
	
	std::cout << "*Creating a horde of " << N << " zombies*" << std::endl;
	Zombie* zombie = zombieHorde(N, "Martin");
	std::cout << std::endl;
	if (!zombie)
		return (1);
	for (int i = 0; i < N; i++)
	{
		std::cout << "*Announce from zombie " << i + 1 << "*" << std::endl;
		zombie[i].announce();
		std::cout << std::endl;
	}
	std::cout << "*Deleting the horde*" << std::endl;
	delete [] zombie;
}
