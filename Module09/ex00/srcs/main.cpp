/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 23:22:40 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/10/11 15:40:22 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Colors.hpp>
#include <BitcoinExchange.hpp>
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << RED << "Error: bad arguments" << RESET << std::endl
			<< "Usage: ./btc [input file]" << RESET << std::endl;
		return 1;
	}
	if (BitcoinExchange::printBitcoinRatesFile(av[1]))
		return 1;
	return 0;
}
