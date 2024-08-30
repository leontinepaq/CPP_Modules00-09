/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:56:09 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/30 21:28:43 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << GREY "[PresidentialPardonForm] Default constructor called" RESET << std::endl;
	_target = "unknown target";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << GREY "[PresidentialPardonForm] Parametric constructor called" RESET << std::endl;
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src)
{
	std::cout << GREY "[PresidentialPardonForm] Copy constructor called" RESET << std::endl;
	_target = src._target;
}

// affectation cannot be done with const members
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	std::cout << GREY "[PresidentialPardonForm] Assignment operator called" RESET << std::endl;
	(void)src;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << GREY "[PresidentialPardonForm] Destructor called" RESET << std::endl;
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return _target;
}

void	PresidentialPardonForm::executeAction(void) const
{
	std::cout << WHITE "* " << getTarget() << " has been pardonned by Zaphod Beeblebrox *" RESET << std::endl;
}
