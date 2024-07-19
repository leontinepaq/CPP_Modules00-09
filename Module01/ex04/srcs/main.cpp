/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:49:20 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/19 16:09:49 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int checkArgs(int ac)
{
	if (ac != 4)
	{
		std::cerr << "Error: wrong number of arguments" << std::endl;
		std::cerr << "Usage: ./ex04 [filename] [string] [string]" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int main(int ac, char **av)
{
	if(checkArgs(ac))
		return (EXIT_FAILURE);
	std::string filename(av[1]);
	std::string s1(av[2]);
	std::string s2(av[3]);
	if (Sed::mySed(filename, s1, s2))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
