/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:15:55 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/30 21:29:23 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << GREY "[RobotomyRequestForm] Default constructor called" RESET << std::endl;
	_target = "unknown target";
	std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << GREY "[RobotomyRequestForm] Parametric constructor called" RESET << std::endl;
	_target = target;
	std::srand(std::time(0));
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src)
{
	std::cout << GREY "[RobotomyRequestForm] Copy constructor called" RESET << std::endl;
	_target = src._target;
	std::srand(std::time(0));	
}

// affectation cannot be done with const members
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << GREY "[RobotomyRequestForm] Assignment operator called" RESET << std::endl;
	(void)src;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << GREY "[RobotomyRequestForm] Destructor called" RESET << std::endl;
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return _target;
}

void	RobotomyRequestForm::executeAction(void) const
{
	std::string target = getTarget();
	std::cout << WHITE "* Robotomy started on "<< target << " *" RESET << std::endl
		<< "Brrrrrrr" << std::endl;
	usleep(600000); ///
	std::cout << "Bzzzzz" << std::endl;
	usleep(700000);
	std::cout << "Trkkt brrr dzzz" << std::endl;
	usleep(400000);
	if (std::rand() % 2)
		std::cout << GREEN "Houra ! It's a success, " << target << " have been robotimized !" << RESET << std::endl;
	else
		std::cout << RED "Ouups it seems like the robotomy on " << target << " has failed..." RESET << std::endl;
}
