/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:34:10 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/17 17:35:18 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "Colors.hpp"
#include <iostream>

Span::Span() : _maxValues(0)
{
	std::cout << GREY << "[Span] Default constructor called" << RESET << std::endl;
}

Span::Span(unsigned int maxValues) : _maxValues(maxValues)
{
	std::cout << GREY << "[Span] Constructor called" << RESET << std::endl;
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


void	Span::printNumbers()
{
	std::multiset<int>::iterator itr;


	int i = 0;
	std::cout << "Numbers: [ ";
	if (_numbers.size() < 10)
	{
		for (itr = _numbers.begin(); (itr != _numbers.end()); ++itr)
			std::cout << *itr << " ";
	}
	else
	{
		for (itr = _numbers.begin(); (itr != _numbers.end()) && i < 5; ++itr)
		{
			std::cout << *itr << " ";
			i++;
		}
		std::cout << "... ";
		std::cout << *_numbers.rbegin() << " ";
	}
	std::cout << "]" << std::endl;
}

void	Span::addNumber(int number)
{
	if (_numbers.size() >= _maxValues)
		throw(TooManyNumbersException());
	_numbers.insert(number);
}

void	Span::addNumber(std::multiset<int>::iterator begin, std::multiset<int>::iterator end)
{
	if (_numbers.size() + std::distance(begin, end) > _maxValues)
		throw(TooManyNumbersException());
	_numbers.insert(begin, end);
}

static int	distance(int a, int b)
{
	return abs(a - b);
}

int Span::longuestSpan()
{
	if (_numbers.size() < 2)
		throw (NotEnoughNumbersException());
	return distance(*_numbers.begin(), *_numbers.rbegin());
}

int Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw (NotEnoughNumbersException());
	int minSpan = distance(*_numbers.begin(), *_numbers.rbegin());
	std::multiset<int>::iterator itr;
	std::multiset<int>::iterator nextItr = _numbers.begin();
	nextItr++;
	for (itr = _numbers.begin(); nextItr != _numbers.end(); ++itr) 
	{
		int dist = distance(*itr, *nextItr);
		if (dist < minSpan)
		{
			minSpan = dist;
			if (minSpan == 0)
				return 0;
		}
		nextItr++;
	}
	return minSpan;
	
}

const char* Span::TooManyNumbersException::what() const throw()
{
	return "Max number have been reached";
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return "Not enough numbers to do this operation";
}
