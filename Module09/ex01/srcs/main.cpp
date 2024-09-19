/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:28:54 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/19 17:00:04 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2 || !av[1][0])
	{
		std::cerr << "Error: Wrong arguments" << std::endl;
		return 0;
	}
	std::string expression = av[1];
	if (RPN::executeExpression(expression))
		return 1;
	return 0;
}
