/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:34:10 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/16 18:53:07 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "Colors.hpp"
#include <iostream>

Span::Span() : _numbers(0), _maxValues(0)
{
	std::cout << GREY << "[Span] Default constructor called" << RESET << std::endl;
}

Span::Span(unsigned int maxValues) :_numbers(0), _maxValues(maxValues)
{
	std::cout << GREY << "[Span] Parametric constructor called" << RESET << std::endl;
}

Span::Span(const Span &src) : _numbers(src._numbers), _maxValues(src._maxValues)
{
	std::cout << GREY << "[Span] Copy constructor called" << RESET << std::endl;
}

Span& Span::operator=(const Span &src)
{
	std::cout << GREY << "[Span] Assignment operator called" << RESET << std::endl;
	_numbers = src._numbers;
	_maxValues= src._maxValues;
	return (*this);
}

Span::~Span()
{
	std::cout << GREY << "[Span] Destructor called" << RESET << std::endl;
}

unsigned int Span::getLengthNumber()
{
	return (_numbers.end() - _numbers.begin());
}


void	Span::addNumber(int number)
{
	if (getLengthNumber() >= _maxValues)
		throw(TooManyNumbersException());
	_numbers.push_back(number);
}

int Span::longuestSpan()
{
	if (getLengthNumber() < 2)
		throw (NotEnoughNumbersException());
	int maxNumber = *_numbers.begin();
	int minNumber = *_numbers.begin();
	for (std::vector<int>::iterator it = _numbers.begin() + 1; it != _numbers.end(); ++it)
	{
		if (*it < minNumber)
			minNumber = *it;
		if (*it > maxNumber)
			maxNumber=*it;
	}
	return maxNumber - minNumber;
}

const char* Span::TooManyNumbersException::what() const throw()
{
	return "Max number have been reached";
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return "Not enough numbers to do this operation";
}
