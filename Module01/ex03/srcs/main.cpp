/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:44:32 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/07 14:29:08 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

#define LIGHT_BLUE "\033[1;36m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

int main()
{
	{
		std::cout << BLUE << "HumanA:" << std::endl;
		std::cout << LIGHT_BLUE << "Create a weapon" << RESET << std::endl;
		Weapon club = Weapon("crude spiked club");
		std::cout << std::endl;
		
		std::cout << LIGHT_BLUE << "Create a human with the weapon" << RESET << std::endl;
		HumanA bob("Bob", club);
		std::cout << std::endl;

		std::cout << LIGHT_BLUE << "Attack with the weapon" << RESET << std::endl;
		bob.attack();

		std::cout << LIGHT_BLUE << "Change the weapon type" << RESET << std::endl;
		club.setType("some other type of club");
		
		std::cout << LIGHT_BLUE << "Attack with the weapon" << RESET << std::endl;
		bob.attack();
		std::cout << std::endl;

		std::cout << LIGHT_BLUE << "HumanA and weapon are destroyed" << RESET << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << BLUE << "HumanB:" << std::endl;
		std::cout << LIGHT_BLUE << "Create a weapon" << RESET << std::endl;
		Weapon club = Weapon("crude spiked club");
		std::cout << std::endl;
		
		std::cout << LIGHT_BLUE << "Create a human without the weapon" << RESET << std::endl;
		HumanB jim("Jim");
		std::cout << std::endl;

		std::cout << LIGHT_BLUE << "Set the weapon" << RESET << std::endl;		
		jim.setWeapon(club);
		
		std::cout << LIGHT_BLUE << "Attack with the weapon" << RESET << std::endl;
		jim.attack();

		std::cout << LIGHT_BLUE << "Change the weapon type" << RESET << std::endl;
		club.setType("some other type of club");

		std::cout << LIGHT_BLUE << "Attack with the weapon" << RESET << std::endl;
		jim.attack();
		std::cout << std::endl;
		
		std::cout << LIGHT_BLUE << "HumanB and weapon are destroyed" << RESET << std::endl;
	}
return 0;}

// int main()
// {
// 	{
// 		Weapon club = Weapon("crude spiked club");
// 		HumanA bob("Bob", club);
// 		bob.attack();
// 		club.setType("some other type of club");
// 		bob.attack();
// 	}
// 	std::cout << std::endl;
// 	{
// 		Weapon club = Weapon("crude spiked club");
// 		HumanB jim("Jim");
// 		jim.setWeapon(club);
// 		jim.attack();
// 		club.setType("some other type of club");
// 		jim.attack();
// 	}
// return 0;}
