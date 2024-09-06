/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:32:45 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/06 15:15:49 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter()	: _value(0), _isPseudoLiteral(false), _input("")
{
	#if PRINT_CONSTRUCTOR
		std::cout << GREY "[ScalarConverter] Default constructor called" RESET << std::endl;
	#endif
}

ScalarConverter::ScalarConverter(std::string input) : _value(0), _isPseudoLiteral(false), _input("")
{
	#if PRINT_CONSTRUCTOR
		std::cout << GREY "[ScalarConverter] Parametric constructor called" RESET << std::endl;
	#endif
	if (isPseudoLiteral(input) == true)
	{
		_isPseudoLiteral = true;
		if (input == "nanf" || input == "nan")
			_value = NAN;
		else if (input == "-inff" || input == "-inf")
			_value = -INFINITY;
		else if (input == "+inff" || input == "+inf")
			_value = INFINITY;
		_input = input;
		return ;
	}	
	if (checkInput(input) == true)
	{
		_input = input;
		inputToDouble();
		return ;
	}
	throw std::invalid_argument("Invalid input");
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) : _value(src._value), _isPseudoLiteral(src._isPseudoLiteral), _input(src._input)
{
	#if PRINT_CONSTRUCTOR
		std::cout << GREY "[ScalarConverter] Copy constructor called" RESET << std::endl;
	#endif
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &src)
{
	#if PRINT_CONSTRUCTOR
		std::cout << GREY "[ScalarConverter] Assignment operator called" RESET << std::endl;
	#endif
	_input = src._input;
	_value = src._value;
	_isPseudoLiteral = src._isPseudoLiteral;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	#if PRINT_CONSTRUCTOR
		std::cout << GREY "[ScalarConverter] Destructor called" RESET << std::endl;
	#endif
}

bool	ScalarConverter::checkInput(std::string input)
{
	if (!isChar(input) && !isInt(input) && !isFloat(input) && !isDouble(input))
		return (false);
	return (true);
}

void	ScalarConverter::inputToDouble(void)
{
	if (_input.empty())
		return ;
	if (isChar(_input))
		_value = static_cast<double>(_input[0]);
	else
	{
		std::stringstream ss(_input);
		ss >> _value;
	}
}

void	ScalarConverter::printValue(void) const
{
	if (_isPseudoLiteral == true)
	{
		printPseudoLiteral(_value);
		return ;
	}
	putChar(_value);
	putInt(_value);
	putFloat(_value);
	putDouble(_value);
}

void	ScalarConverter::convert(const char *input)
{
	std::string strInput(input);
	try 
	{
		ScalarConverter sc(strInput);
		sc.printValue();
	}
	catch (std::invalid_argument &e)
	{
		std::cerr << RED "Error: Invalid input" RESET << std::endl;
	}
}
