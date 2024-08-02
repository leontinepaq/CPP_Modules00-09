/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:27:21 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/02 13:34:13 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

bool	Contact::isEmpty(void)
{
	if (this->firstName == "")
		return (true);
	return (false);
}

static int	checkInputField(std::string buff, std::string field)
{
	std::istringstream iss(buff);
	if (buff == "")
	{
		std::cout << RED << "> Field \"" << field << "\" cannot be empty" 
			<< RESET << std::endl;
		return (EXIT_FAILURE);
	}
	for (size_t i = 0; i < buff.length(); i++)
	{
		if (!isgraph(buff[i]) && buff[i] != ' ')
		{
			std::cout << RED << "> Field \"" << field << "\" cannot contain non-printable characters"
				<< RESET << std::endl;
			return (EXIT_FAILURE);
		}	
	}
	return (EXIT_SUCCESS);
}

int	Contact::enterField(std::string field, std::string *buff)
{
	std::cout << BLUE << "   - " << field << ": " << RESET;
	if (!std::getline(std::cin, *buff))
	{
		if (std::cin.eof())
			std::cout << RED << "\n> EOF detected" << RESET << std::endl;
		return (EXIT_FAILURE);
	}
	if (checkInputField(*buff, field))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	Contact::fillContact(int *index)
{
	Contact tmp_Contact;

	std::cout << PINK << "\nNEW CONTACT:" << std::endl;
	std::cout << BLUE << "> Please enter the following information "
		<< "(no field should be empty):" << RESET << std::endl;
	if (Contact::enterField("first name", &tmp_Contact.firstName)
		|| Contact::enterField("last name", &tmp_Contact.lastName)
		|| Contact::enterField("nickname", &tmp_Contact.nickname)
		|| Contact::enterField("phone number", &tmp_Contact.phoneNumber)
		|| Contact::enterField("darkest secret", &tmp_Contact.darkestSecret))
	{
		std::cout << RED << "> Contact not added\n" << RESET << std::endl;
		return ;
	}
	*this = tmp_Contact;
	*index = (*index + 1) % MAX_CONTACTS;
	std::cout << GREEN << "> Contact successfully added to your phonebook\n" 
		<< RESET << std::endl;
	return ;
}

void	Contact::displayField(std::string field_value)
{
	std::cout << LIGHT_BLUE << "|" << RESET;
	if (field_value.length() > 10)
		std::cout << field_value.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << field_value;
}
void	Contact::displayContactRow(int index)
{
	if (this->isEmpty())
		return ;
	std::cout << std::setw(10) << index;
	this->displayField(this->firstName);
	this->displayField(this->lastName);
	this->displayField(this->nickname);
	std::cout << std::endl;
	return ;
}

void	Contact::displayContactInformation(void)
{
	std::cout << PINK << "\nCONTACT INFORMATION:" << RESET << std::endl;
	std::cout << LIGHT_BLUE << "   - first name: " << RESET << this->firstName << std::endl;
	std::cout << LIGHT_BLUE << "   - last name: " << RESET <<  this->lastName << std::endl;
	std::cout << LIGHT_BLUE << "   - nickname: " << RESET <<  this->nickname << std::endl;
	std::cout << LIGHT_BLUE << "   - phone number: " << RESET <<  this->phoneNumber << std::endl;
	std::cout << LIGHT_BLUE << "   - darkest secret: " << RESET <<  this->darkestSecret << std::endl;
	return ;
}
