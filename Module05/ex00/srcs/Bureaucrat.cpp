/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 22:41:41 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/28 01:02:22 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150)
{
	std::cout << GREY << "[Bureaucrat] Default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << GREY << "[Bureaucrat] Parametric constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
	std::cout << GREY << "[Bureaucrat] Copy constructor called" << RESET << std::endl;
}

// affectation cannot be done with const members
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << GREY << "[Bureaucrat] Assignment operator called" << RESET << std::endl;
	(void)src;
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << GREY << "[Bureaucrat] Destructor called" << RESET << std::endl;
}

const std::string	Bureaucrat::getName(void) const
{
	return _name;
}

int	Bureaucrat::getGrade(void) const
{
	return _grade;
}

void	Bureaucrat::incrementGrade(void)
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high (1 is the highest possible grade)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low (150 is the lowest possible grade)";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade();
	return os;
}