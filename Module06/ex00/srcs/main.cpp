/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:34:18 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/03 16:59:38 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << RED "Error: " RESET "Invalid number of arguments" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	float a = 1.f;
	float b =-1.e-1;
	std::cout << "TEST: " << a + b << std::endl;
	return (0);
}
