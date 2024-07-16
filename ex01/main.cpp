/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:53:00 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/16 13:52:47 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	
	std::cout << "\nWELCOME TO YOUR PHONEBOOK!\n" << std::endl;
	while (1)
	{
		std::string	buff;
		std::cout << "Enter a command (ADD, SEARCH or EXIT)\n>> ";
		if (!std::getline(std::cin, buff))
		{
			if (std::cin.eof())
                std::cout << "\n> EOF detected\n" << std::endl;
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
		if (std::cin.eof())
			break;
	}
	std::cout << "YOU ARE LEAVING YOUR PHONEBOOK..." << std::endl;
	std::cout << "HOPE YOU'LL BE BACK SOON ! :)\n" << std::endl;
	return (EXIT_SUCCESS);
}
