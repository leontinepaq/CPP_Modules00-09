/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printFcts.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:45:49 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/06 13:47:05 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	putChar(double value)
{
	std::cout << "char: ";
	if (value < 0 || value >= 255)
		std::cout << "impossible" << std::endl;
	else if (value < 32 || value > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

void putInt(double value)
{
	std::cout << "int: ";
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

void putFloat(double value)
{
	std::cout << "float: ";	
	if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::string nullDecimalPart;
	if (value - static_cast<int>(value) == 0)
		nullDecimalPart = ".0";
	std::cout << static_cast<float>(value) << nullDecimalPart << "f" << std::endl;
}

void putDouble(double value)
{
	std::cout << "double: ";
	std::string nullDecimalPart;
	if (value - static_cast<int>(value) == 0)
		nullDecimalPart = ".0";
	std::cout << value << nullDecimalPart << std::endl;
}

void printPseudoLiteral(double value)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}
