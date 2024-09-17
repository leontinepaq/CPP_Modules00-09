/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printFcts.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:45:49 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/17 22:07:50 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// a priori la conv statique d'un double a un char est un comportement defini par le standard C++ 
//comme une conversion modulo 256 (char signe) ou 128 (char non signe)
// -> pas besoin de verifier si le double est dans les bornes d'un char
void	putChar(double value)
{
	std::cout << "char: ";
	// if (value < 0 || value >= 255)
	// 	std::cout << "impossible" << std::endl;
	// else if (value < 32 || value > 126)
	// 	std::cout << "Non displayable" << std::endl;
	// else
		// std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	char c = static_cast<char>(value);
	if (c < 32 || c > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}


// a priori la conv statique d'un double a un int n'a pas de comportement defini si le double depasse les bornes d'un int
// -> verifier si le double est dans les bornes d'un int
void putInt(double value)
{
	std::cout << "int: ";
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		std::cout << "undefined behavior" << std::endl; //?
	else
		std::cout << static_cast<int>(value) << std::endl;
}


// a priori la conv statique d'un double a un float n'a pas de comportement defini si le double depasse les bornes d'un float
// peut entraîner une perte de precision ou inf
void putFloat(double value)
{
	std::cout << "float: ";	
	// if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
	// {
	// 	std::cout << "impossible" << std::endl;
	// 	return ;
	// }
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
