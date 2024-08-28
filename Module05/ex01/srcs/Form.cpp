/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 01:20:55 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/28 03:00:15 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << GREY "[Form] Default constructor called" RESET << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Bureaucrat::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << GREY "[Form] Parametric constructor called" RESET << std::endl;
}

Form::Form(const Form &src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign),
	_gradeToExecute(src._gradeToExecute)
{
	std::cout << GREY "[Form] Copy constructor called" RESET << std::endl;
}

// affectation cannot be done with const members
Form& Form::operator=(const Form &src)
{
	std::cout << GREY "[Form] Assignment operator called" RESET << std::endl;
	(void)src;
	return *this;
}

Form::~Form()
{
	std::cout << GREY "[Form] Destructor called" RESET << std::endl;
}

const std::string	Form::getName(void) const
{
	return _name;
}

bool	Form::getSigned(void) const
{
	return _signed;
}

int	Form::getGradeToSign(void) const
{
	return _gradeToSign;
}

int	Form::getGradeToExecute(void) const
{
	return _gradeToExecute;
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	int grade = bureaucrat.getGrade();
	if (grade > _gradeToSign)
		throw Bureaucrat::GradeTooLowException();
	if (_signed)
		throw Form::FormAlreadySignedException();
	_signed = true;
}

void	Form::beExecuted(Bureaucrat const &executor) const
{
	int grade = executor.getGrade();
	if (grade > _gradeToExecute)
		throw Bureaucrat::GradeTooLowException();
	if (!_signed)
		throw Form::FormNotSignedException();
}

const char* Form::FormAlreadySignedException::what() const throw()
{
	return "Already signed";
}

const char* Form::FormNotSignedException::what() const throw()
{
	return "Not signed";
}

std::ostream&	operator<<(std::ostream &os, const Form &src)
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