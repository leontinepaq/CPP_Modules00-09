/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:13:01 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/06 16:16:45 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>

Data::Data() : _value(0), _str("")
{
	std::cout << GREY "[Data] Default constructor called" RESET << std::endl;
}

Data::Data(int value, std::string str) : _value(value), _str(str)
{
	std::cout << GREY "[Data] Parameterized constructor called" RESET << std::endl;
}

Data::Data(const Data &src) : _value(src._value), _str(src._str)
{
	std::cout << GREY "[Data] Copy constructor called" RESET << std::endl;
}


Data& Data::operator=(const Data &src)
{
	std::cout << GREY "[Data] Assignment operator called" RESET << std::endl;
	_value = src._value;
	_str = src._str;
	return *this;
}

Data::~Data()
{
	std::cout << GREY "[Data] Destructor called" RESET << std::endl;
}

void Data::setValue(int value)
{
	_value = value;
}

int Data::getValue() const
{
	return _value;
}

void Data::setStr(std::string str)
{
	_str = str;
}

std::string Data::getStr() const
{
	return _str;
}
