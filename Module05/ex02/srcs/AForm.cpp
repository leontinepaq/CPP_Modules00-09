/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 01:20:55 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/30 21:20:05 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << GREY "[AForm] Default constructor called" RESET << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Bureaucrat::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << GREY "[AForm] Parametric constructor called" RESET << std::endl;
}

AForm::AForm(const AForm &src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign),
	_gradeToExecute(src._gradeToExecute)
{
	std::cout << GREY "[AForm] Copy constructor called" RESET << std::endl;
}

// affectation cannot be done with const members
AForm& AForm::operator=(const AForm &src)
{
	std::cout << GREY "[AForm] Assignment operator called" RESET << std::endl;
	(void)src;
	return *this;
}

AForm::~AForm()
{
	std::cout << GREY "[AForm] Destructor called" RESET << std::endl;
}

const std::string	AForm::getName(void) const
{
	return _name;
}

bool	AForm::getSigned(void) const
{
	return _signed;
}

int	AForm::getGradeToSign(void) const
{
	return _gradeToSign;
}

int	AForm::getGradeToExecute(void) const
{
	return _gradeToExecute;
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	int grade = bureaucrat.getGrade();
	if (grade > _gradeToSign)
		throw Bureaucrat::GradeTooLowException();
	if (_signed)
		throw AForm::FormAlreadySignedException();
	_signed = true;
}

void	AForm::checkExecution(Bureaucrat const &executor) const
{
	int grade = executor.getGrade();
	if (grade > _gradeToExecute)
		throw Bureaucrat::GradeTooLowException();
	if (!_signed)
		throw AForm::FormNotSignedException();
}

const char* AForm::FormAlreadySignedException::what() const throw()
{
	return "Already signed";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Not signed";
}

std::ostream&	operator<<(std::ostream &os, const AForm &src)
{
	os << "-------------------------------------" << std::endl;
	os << WHITE << src.getName() << std::endl
		<< "- signed: ";
	if (src.getSigned())
		os << "yes" << std::endl;
	else
		os << "no" << std::endl;
	os << "- grade to sign: " << src.getGradeToSign() << std::endl
		<< "- grade to execute: " << src.getGradeToExecute() << RESET << std::endl;
	os << "-------------------------------------" << std::endl;
	return os;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	checkExecution(executor);
	executeAction();
}
