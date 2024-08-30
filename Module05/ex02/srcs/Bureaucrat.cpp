/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 22:41:41 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/30 21:34:42 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150)
{
	std::cout << GREY "[Bureaucrat] Default constructor called" RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << GREY "[Bureaucrat] Parametric constructor called" RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
	std::cout << GREY "[Bureaucrat] Copy constructor called" RESET << std::endl;
}

// affectation cannot be done with const members
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << GREY "[Bureaucrat] Assignment operator called" RESET << std::endl;
	(void)src;
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << GREY "[Bureaucrat] Destructor called" RESET << std::endl;
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

void	Bureaucrat::signForm(AForm &form) const 
{
	try
	{
		form.beSigned(*this);
		std::cout << GREEN << _name << " signs " << form.getName() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("Already signed"))
			std::cout << RED << _name << " cannot sign " << form.getName() << " because it is already signed" << RESET << std::endl;
		else
			std::cout << RED << _name << " cannot sign " << form.getName() << " because it requires a grade minimum of "
				<< form.getGradeToSign() << RESET << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << GREEN << _name << " executed " << form.getName() << RESET << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cout << RED << _name << " cannot execute " << form.getName() << " because " << e.what() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		if (e.what() == std::string("Not signed"))
			std::cout << RED << _name << " cannot execute " << form.getName() << " because it is not signed" << RESET << std::endl;
		else if (e.what() == std::string("Grade too low"))
			std::cout << RED << _name << " cannot execute " << form.getName() << " because it requires a grade minimum of "
				<< form.getGradeToExecute() << RESET << std::endl;
		else
			std::cout << RED << _name << " cannot execute " << form.getName() << " because something unexpected happened" << RESET << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &src)
{
	os << WHITE << src.getName() << ", bureaucrat grade " << src.getGrade() << RESET << std::endl;
	return os;
}
