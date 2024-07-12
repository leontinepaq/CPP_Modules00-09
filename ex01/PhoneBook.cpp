/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:26:58 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/12 17:50:54 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	this->current_index = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}
void	PhoneBook::add(void)
{
	this->contacts[this->current_index].fill_contact(&this->current_index);
	return ;
}

void	PhoneBook::display_list_contacts(void)
{
	std::cout << "\nLIST OF CONTACTS:" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < 8; i++)
		this->contacts[i].display_contact_list(i);
	std::cout << std::endl;
}

void	PhoneBook::select_contact(void)
{
	int		index;
	std::string	input;

	std::cout << "DISPLAY CONTACT:" << std::endl;
	std::cout << "> Please enter the index of the contact you want to display: ";
	std::getline(std::cin, input);
	std::istringstream iss(input);
    if (!(iss >> index) || !iss.eof()
		|| index < 0 || index >= 8 || this->contacts[index].is_empty())
    {
        std::cout << "> Invalid index - no contact to display\n" << std::endl;
        return;
    }	
	this->contacts[index].display_contact_information();
	std::cout << std::endl;
	return ;
}

void	PhoneBook::search(void)
{
	this->display_list_contacts();
	this->select_contact();
	return ;
}

