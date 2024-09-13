/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:52:06 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/13 18:17:01 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>

#ifndef COLORS
# define BLUE		"\033[1;34m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define CYAN		"\033[1;36m"
# define MAGENTA	"\033[1;35m"
# define YELLOW		"\033[1;33m"
# define GREY		"\033[1;30m"
# define WHITE		"\033[1;37m"
# define ORANGE		"\033[1;38;5;208m"
# define PURPLE		"\033[1;38;5;129m"
# define RESET		"\033[0m"
#endif

std::vector<int> valuesToVector (int values[], size_t n)
{
	std::vector<int> tab;

	for (size_t i = 0; i < n; ++i)
		tab.push_back(values[i]);
	return tab;
}

int main()
{
	std::cout << CYAN << "TEST WITH INT VECTOR" << RESET << std::endl;
	int values[] = {1, 500, 42, -1};
	size_t n = sizeof(values) / sizeof(values[0]);
	std::vector<int> tab = valuesToVector(values, n);
	
	std::cout << WHITE "tab = [ ";
	for (std::vector<int>::iterator it = tab.begin(); it != tab.end(); ++it)
		std::cout << *it << " ";
	std::cout << "]" RESET << std::endl;

	try
	{
		std::cout << WHITE "> Trying to find 42 in the vector: " RESET;
		std::cout << GREEN << *easyfind(tab, 42) << " was found" RESET << std::endl;
		std::cout << WHITE "> Trying to find 0 in the vector: " RESET;
		std::cout << GREEN << *easyfind(tab, 0) << " was found" RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED "Exception caught: " << e.what() << RESET << std::endl;
	}
	
	std::cout << CYAN << "TEST WITH STRING VECTOR" << RESET << std::endl;
	std::vector<std::string> tab2;
	tab2.push_back("Hello");
	tab2.push_back("World");
	tab2.push_back("42");
	
	std::cout << WHITE "tab2 = [ ";
	for (std::vector<std::string>::iterator it = tab2.begin(); it != tab2.end(); ++it)
		std::cout << *it << " ";
	std::cout << "]" RESET << std::endl;
	
	std::cout<< RED "> Does not compile <" RESET << std::endl;
	// try
	// {
	// 	std::cout << WHITE "> Trying to find 42 in the vector: " RESET;
	// 	std::cout << GREEN << *easyfind(tab2, 42) << " was found" RESET << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << RED "Exception caught: " << e.what() << RESET << std::endl;
	// }
}
