/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:53:00 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/31 15:19:46 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	
	std::cout << PINK << "\nWELCOME TO YOUR PHONEBOOK!\n" << RESET << std::endl;
	while (1)
	{
		std::string	buff;
		std::cout << BLUE << "Enter a command (ADD, SEARCH or EXIT)"
			<< RESET << "\n>> ";
		if (!std::getline(std::cin, buff))
		{
			if (std::cin.eof())
                std::cout << RED << "\n> EOF detected\n" << RESET << std::endl;
			break;
		};
		if (buff == "EXIT")
		{
			std::cout << std::endl;
			break ;
		}
		else if (buff == "ADD")
			phonebook.add();
		else if (buff == "SEARCH")
			phonebook.search();
		else
			std::cout << RED << "> Invalid command\n" << RESET << std::endl;
		if (std::cin.eof())
			break;
	}
	std::cout << PINK << "YOU ARE LEAVING YOUR PHONEBOOK..." << std::endl;
	std::cout << "HOPE YOU'LL BE BACK SOON ! :)\n" << RESET << std::endl;
	return (EXIT_SUCCESS);
}
