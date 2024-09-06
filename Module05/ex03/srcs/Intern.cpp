/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 21:45:58 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/06 18:30:22 by lpaquatt         ###   ########.fr       */
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

AForm	*Intern::makeShrubberyCreationForm(std::string target) const
{
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::makeRobotomyRequestForm(std::string target) const
{
	return new RobotomyRequestForm(target);
}

AForm	*Intern::makePresidentialPardonForm(std::string target) const
{
	return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm(std::string formName, std::string target) const
{
	AForm* (Intern::*ptr[3])(std::string target) const = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *form = NULL;
	int i;
	for (i = 0; i < 3; i++)
	{
		if (formNames[i] == formName)
		{
			form = (this->*ptr[i])(target);
			break;
		}
	}
	if (i == 3)
	{
		std::cout << RED "Intern doesn't know how to make the form '" << formName
				<< "'... He can only create 'shrubbery creation', 'robotomy request' or 'presidential pardon' forms" << RESET << std::endl;
		return NULL;
	}
	std::cout << GREEN "Intern creates a " << formName << " form" << RESET << std::endl;
	return form;
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return "Form not found";
}
		