/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:27:21 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/16 13:53:44 by lpaquatt         ###   ########.fr       */
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

bool	Contact::is_empty(void)
{
	if (this->first_name == "")
		return (true);
	return (false);
}

int	check_input_field(std::string buff, std::string field)
{
	std::istringstream iss(buff);
	if (buff == "")
	{
		std::cout << "> Field \"" << field << "\" cannot be empty" << std::endl;
		return (EXIT_FAILURE);
	}
	for (size_t i = 0; i < buff.length(); i++)
	{
		if (!isgraph(buff[i]) && buff[i] != ' ')
		{
			std::cout << "> Field \"" << field << "\" cannot contain non-printable characters" << std::endl;
			return (EXIT_FAILURE);
		}	
	}
	return (EXIT_SUCCESS);
}

int	Contact::enter_field(std::string field, std::string *buff)
{
	std::cout << "   - " << field << ": ";
	if (!std::getline(std::cin, *buff))
	{
		if (std::cin.eof())
			std::cout << "\n> EOF detected\n";
		return (EXIT_FAILURE);
	}
	if (check_input_field(*buff, field))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	Contact::fill_contact(int *index)
{
	Contact tmp_Contact;

	std::cout << "\nNEW CONTACT:" << std::endl;
	std::cout << "> Please enter the following information "
		<< "(no field should be empty):" << std::endl;
	if (Contact::enter_field("first name", &tmp_Contact.first_name)
		|| Contact::enter_field("last name", &tmp_Contact.last_name)
		|| Contact::enter_field("nickname", &tmp_Contact.nickname)
		|| Contact::enter_field("phone number", &tmp_Contact.phone_number)
		|| Contact::enter_field("darkest secret", &tmp_Contact.darkest_secret))
	{
		std::cout << "> Contact not added\n" << std::endl;
		return ;
	}
	*this = tmp_Contact;
	*index = (*index + 1) % 8;
	std::cout << "> Contact successfully added to your phonebook\n" << std::endl;
	return ;
}

void	Contact::display_field(std::string field_value)
{
	std::cout << "|";
	if (field_value.length() > 10)
		std::cout << field_value.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << field_value;
}
void	Contact::display_contact_list(int index)
{
	if (this->is_empty())
		return ;
	std::cout << std::setw(10) << index;
	this->display_field(this->first_name);
	this->display_field(this->last_name);
	this->display_field(this->nickname);
	std::cout << std::endl;
	return ;
}

void	Contact::display_contact_information(void)
{
	std::cout << "\nCONTACT INFORMATION:" << std::endl;
	std::cout << "   - first name: " << this->first_name << std::endl;
	std::cout << "   - last name: " << this->last_name << std::endl;
	std::cout << "   - nickname: " << this->nickname << std::endl;
	std::cout << "   - phone number: " << this->phone_number << std::endl;
	std::cout << "   - darkest secret: " << this->darkest_secret << std::endl;
	return ;
}
