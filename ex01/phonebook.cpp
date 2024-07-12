/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:53:00 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/12 17:05:06 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"


int	main(void)
{
	PhoneBook	phonebook;
	
	std::cout << "\nWELCOME TO YOUR PHONEBOOK!\n" << std::endl;
	while (1)
	{
		std::string	buff;
		std::cout << "Enter a command (ADD, SEARCH or EXIT)\n>> ";
		std::cin >> buff;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (buff == "EXIT")
			break ;
		else if (buff == "ADD")
			phonebook.add();
		else if (buff == "SEARCH")
			phonebook.search();
	}
	return (EXIT_SUCCESS);
}
