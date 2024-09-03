/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:32:45 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/03 18:21:05 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter()	: _value(0), _isPseudoLiteral(false), _input("")
{
	std::cout << GREY "[ScalarConverter] Default constructor called" RESET << std::endl;
}

ScalarConverter::ScalarConverter(std::string input) : _value(0), _isPseudoLiteral(false), _input("")
{
	std::cout << GREY "[ScalarConverter] Parametric constructor called" RESET << std::endl;
	if (checkInput(input) == true)
		_input = input;
}


ScalarConverter::ScalarConverter(const ScalarConverter &src) : _value(src._value), _isPseudoLiteral(src._isPseudoLiteral), _input(src._input)
{
	std::cout << GREY "[ScalarConverter] Copy constructor called" RESET << std::endl;
}


ScalarConverter& ScalarConverter::operator=(const ScalarConverter &src)
{
	std::cout << GREY "[ScalarConverter] Assignment operator called" RESET << std::endl;
	_input = src._input;
	_value = src._value;
	_isPseudoLiteral = src._isPseudoLiteral;
	return (*this);
}


ScalarConverter::~ScalarConverter()
{
	std::cout << GREY "[ScalarConverter] Destructor called" RESET << std::endl;
}

static bool	isChar(std::string input)
{
	if (input.length() == 1 && !isdigit(input[0]))
		return (true);
	std::cout << YELLOW "test > " << input << " is not a char" RESET << std::endl;
	return (false);
}

static bool	isInt(std::string input)
{
	if (input.length() == 1 && isdigit(input[0]))
		return (true);
	if (input.length() > 1 && (isdigit(input[0]) || input[0] == '-' || input[0] == '+'))
	{
		for (size_t i = 1; i < input.length(); i++)
		{
			if (!isdigit(input[i]))
			{
				std::cout << YELLOW "test > " << input << " is not an int (unvalid char)" RESET << std::endl;
				return (false);
			}
		}
		if (input.length() > 11 
			|| atoll(input.c_str()) > std::numeric_limits<int>::max()
			|| atoll(input.c_str()) <  std::numeric_limits<int>::min())
		{
			std::cout << YELLOW "test > " << input << " is not an int (overflow)" RESET << std::endl;
			return (false);
		}
		return (true);
	}
	std::cout << YELLOW "test > " << input << " is not an int (unvalid char)" RESET << std::endl;
	return (false);
}

/*
Float literal :

1) digit-sequence representing a whole number without a decimal separator, in this case the exponent is not optional: 1e10, 1e-5L.
2) digit-sequence representing a whole number with a decimal separator, in this case the exponent is optional: 1., 1.e-2.
3) digit-sequence representing a fractional number. The exponent is optional: 3.14, .1f, 0.1e-1L.
4) Hexadecimal digit-sequence representing a whole number without a radix separator. The exponent is never optional for hexadecimal floating-point literals: 0x1ffp10, 0X0p-1.
5) Hexadecimal digit-sequence representing a whole number with a radix separator. The exponent is never optional for hexadecimal floating-point literals: 0x1.p0, 0xf.p-1.
6) Hexadecimal digit-sequence representing a fractional number with a radix separator. The exponent is never optional for hexadecimal floating-point literals: 0x0.123p-1, 0xa.bp10l.

decimal-exponent has the form
e | E exponent-sign ﻿(optional) digit-sequence 		

hex-exponent has the form
p | P exponent-sign ﻿(optional) digit-sequence 		(since C++17)

exponent-sign, if present, is either + or -

suffix, if present, is one of f, l, F, L, f16, f32, f64, f128, bf16, F16, F32, F64, F128, BF16(since C++23). The suffix determines the type of the floating-point literal:

        (no suffix) defines double
        f F defines float
        l L defines long double 

*/

static bool	isDecimal(std::string input)
{
	if (input.length() < 2)
		return (false);
	size_t nbDot = 0;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && input[i] != '.')
		{
			if ((input[i] == '-' || input[i] == '+') && i == 0)
				continue;
			return (false);
		}
		if (input[i] == '.' && nbDot++ > 0)
			return (false);
	}
	if (nbDot == 0)
		return (false);
	return (true);
}


static bool isDouble(std::string input)
{
	std::string decimalPart = input;
	size_t posE = input.find('e');
	if (posE == std::string::npos)
		posE = input.find('E');
	if (posE != std::string::npos)
	{
		std::string exponentPart = input.substr(posE + 1, input.length() - posE - 2);
		if (isInt(exponentPart) == false)
		{
			std::cout << YELLOW "test > " << input << " is not a double (after e)" RESET << std::endl;
			return (false);
		}
		decimalPart = input.substr(0, posE);
	}
	if (isDecimal(decimalPart) == false)
	{
		std::cout << YELLOW "test > " << input << " is not a double (before e)" RESET << std::endl;
		return (false);
	}
	//no overflow check for double ? put it as ??
	return (true);
}

static bool	isFloat(std::string input)
{
	if (input.length() < 3)
	{
		std::cout << YELLOW "test > " << input << " is not a float (too short)" RESET << std::endl;
		return (false);
	}
	if (input[input.length() - 1] != 'F' && input[input.length() - 1] != 'f')
	{
		std::cout << YELLOW "test > " << input << " is not a float (no suffix)" RESET << std::endl;
		return (false);
	}
	std::string beforeF = input.substr(0, input.length() - 1);
	if (isDouble(beforeF) == false)
	{
		std::cout << YELLOW "test > " << input << " is not a float (before f)" RESET << std::endl;
		return (false);
	}
	//no overflow check for float ? put it as +/-inff
	return (true);
}

bool	ScalarConverter::checkInput(std::string input)
{
	if (!isChar(input) && !isInt(input) && !isFloat(input))// && !isDouble(input))
	{
		//throw std::invalid_argument("Invalid input");
		return (false);
	}
	return (true);
}


void	ScalarConverter::inputToDouble(void)
{
	try
	{
		std::stringstream ss(_input);
		ss >> _value;
	}
	catch (std::exception &e)
	{
		std::cerr << RED "Error: " RESET << e.what() << std::endl;
	}
}

void	ScalarConverter::printValue(void) const
{
	std::string nullDecimalPart;
	if (_value - static_cast<int>(_value) == 0)
		nullDecimalPart = ".0";

	std::cout << "char: ";
	if (_value < 32 || _value > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(_value) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(_value) << std::endl;
	std::cout << "float: " << static_cast<float>(_value) << nullDecimalPart << "f" << std::endl;
	std::cout << "double: " << _value << nullDecimalPart << std::endl;
}


void	ScalarConverter::convert(const char *input)
{
	std::string strInput(input);
	
	ScalarConverter sc(strInput);
	sc.inputToDouble();
	sc.printValue();
}

