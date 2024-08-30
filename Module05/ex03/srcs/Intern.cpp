/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 21:45:58 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/30 22:33:18 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

Intern::Intern()
{
	std::cout << GREY "[Intern] Default constructor called" RESET << std::endl;
}

Intern::Intern(const Intern &src)
{
	std::cout << GREY "[Intern] Copy constructor called" RESET << std::endl;
	(void)src;
}

Intern& Intern::operator=(const Intern &src)
{
	std::cout << GREY "[Intern] Assignment operator called" RESET << std::endl;
	(void)src;
	return *this;
}

Intern::~Intern()
{
	std::cout << GREY "[Intern] Destructor called" RESET << std::endl;
}

static int getFormNb(std::string formName)
{
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == formName)
			return i;
	}
	throw Intern::FormNotFoundException();
}

AForm	*Intern::makeForm(std::string formName, std::string target) const
{
	AForm *form;

	try
	{
		switch (getFormNb(formName))
		{
			case 0:
				form = new ShrubberyCreationForm(target);
				break;
			case 1:
				form = new RobotomyRequestForm(target);
				break;
			case 2:
				form = new PresidentialPardonForm(target);
				break;
		}
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("Form not found"))
		{
			std::cout << RED "Intern doesn't know how to make the form '" << formName
				<< "'... He can only create shrubbery creation, robotomy request or presidential pardon forms" << RESET << std::endl;
		}
		else
			std::cout << RED "Intern can't make the form" << RESET << std::endl;
		return NULL;
	}
	std::cout << GREEN "Intern creates a " << formName << " form" << RESET << std::endl;
	return form;
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return "Form not found";
}
		