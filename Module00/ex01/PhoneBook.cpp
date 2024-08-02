/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:26:58 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/02 13:34:13 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->currentIndex = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}
void	PhoneBook::add(void)
{
	this->contacts[this->currentIndex].fillContact(&this->currentIndex);
	return ;
}

void	PhoneBook::displayListContacts(void)
{
	std::cout << PINK << "\nLIST OF CONTACTS:" << RESET << std::endl;
	std::cout << LIGHT_BLUE;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << RESET;
	for (int i = 0; i < MAX_CONTACTS; i++)
		this->contacts[i].displayContactRow(i);
	std::cout << std::endl;
}

void	PhoneBook::selectContact(void)
{
	int			index;
	std::string	input;

	std::cout << PINK << "DISPLAY CONTACT:" << RESET << std::endl;
	std::cout << BLUE << "> Please enter the index of the contact you want to display: " << RESET;
	if (!std::getline(std::cin, input))
	{
		if (std::cin.eof())
			std::cout << RED << "\n> EOF detected\n" << RESET << std::endl;
		return ;
	}
	std::istringstream iss(input);
    if (!(iss >> index) || !iss.eof()
		|| index < 0 || index >= MAX_CONTACTS || this->contacts[index].isEmpty())
    {
        std::cout << RED << "> Invalid index - no contact to display\n" 
			<< RESET << std::endl;
        return;
    }	
	this->contacts[index].displayContactInformation();
	std::cout << std::endl;
	return ;
}

void	PhoneBook::search(void)
{
	this->displayListContacts();
	this->selectContact();
	return ;
}
