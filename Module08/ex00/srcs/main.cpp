/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:52:06 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/16 17:24:29 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "Colors.hpp"
#include <iostream>
#include <vector>
#include <list>


// #ifndef COLORS
// # define BLUE		"\033[1;34m"
// # define Colors::RED		"\033[1;31m"
// # define Colors::GREEN		"\033[1;32m"
// # define Colors::CYAN		"\033[1;36m"
// # define MAGENTA	"\033[1;35m"
// # define YELLOW		"\033[1;33m"
// # define GREY		"\033[1;30m"
// # define Colors::WHITE		"\033[1;37m"
// # define ORANGE		"\033[1;38;5;208m"
// # define PURPLE		"\033[1;38;5;129m"
// # define Colors::RESET		"\033[0m"
// #endif



std::vector<int> valuesToVector (int values[], size_t n)
{
	std::vector<int> tab;

	for (size_t i = 0; i < n; ++i)
		tab.push_back(values[i]);
	return tab;
}

std::list<int> valuesToList (int values[], size_t n)
{
	std::list<int> list;

	for (size_t i = 0; i < n; ++i)
		list.push_back(values[i]);
	return list;
}

int main()
{
	std::cout << Colors::CYAN << "TEST WITH INT VECTOR" << Colors::RESET << std::endl;
	int values[] = {1, 500, 42, -1};
	size_t n = sizeof(values) / sizeof(values[0]);
	std::vector<int> tab = valuesToVector(values, n);
	
	std::cout << Colors::WHITE << "tab = [ ";
	for (std::vector<int>::iterator it = tab.begin(); it != tab.end(); ++it)
		std::cout << *it << " ";
	std::cout << "]" << Colors::RESET << std::endl;

	try
	{
		std::vector<int>::iterator toFind; 
		std::cout << Colors::WHITE << "> Trying to find 42 in the vector: " << Colors::RESET;
		toFind = easyfind(tab, 42);
		std::cout << Colors::GREEN << *toFind << " was found at index " 
			<< toFind - tab.begin() << Colors::RESET << std::endl; 
		std::cout << Colors::WHITE << "> Trying to find 0 in the vector: " << Colors::RESET;
		toFind = easyfind(tab, 0);
		std::cout << Colors::GREEN << *toFind << " was found at index " 
			<< toFind - tab.begin() << Colors::RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << Colors::RED << "Exception caught: " << e.what() << Colors::RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << Colors::CYAN << "TEST WITH LIST" << Colors::RESET << std::endl;
	int values2[] = {0, 1, -1, 42, 50, 42};
	n = sizeof(values2) / sizeof(values2[0]);
	std::list<int> list = valuesToList(values, n);

	std::cout << Colors::WHITE<< "list = [ ";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
		std::cout << *it << " ";
	std::cout << "]" << Colors::RESET << std::endl;
	try
	{
		std::list<int>::iterator toFind;
		std::cout << Colors::WHITE << "> Trying to find 42 in the list: " << Colors::RESET;
		toFind = easyfind(list, 42);
		std::cout << Colors::GREEN << *toFind << " was found at index " 
			<< std::distance(list.begin(), toFind) << Colors::RESET << std::endl;
		std::cout << Colors::WHITE << "> Trying to find 0 in the list: " << Colors::RESET;
		toFind = easyfind(list, 0);
		std::cout << Colors::GREEN << *toFind << " was found at index " 
			<< std::distance(list.begin(), toFind) << Colors::RESET << std::endl;		
	}
	catch(const std::exception& e)
	{
		std::cerr << Colors::RED << "Exception caught: " << e.what() << Colors::RESET << std::endl;
	}
	std::cout << std::endl;
}


	// std::cout << Colors::CYAN << "TEST WITH STRING VECTOR" << Colors::RESET << std::endl;
	// std::vector<std::string> tab2;
	// tab2.push_back("Hello");
	// tab2.push_back("World");
	// tab2.push_back("42");
	
	// std::cout << Colors::WHITE "tab2 = [ ";
	// for (std::vector<std::string>::iterator it = tab2.begin(); it != tab2.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << "]" Colors::RESET << std::endl;
	
	// std::cout<< Colors::RED "> Does not compile <" Colors::RESET << std::endl;
	// // try
	// // {
	// // 	std::cout << Colors::WHITE "> Trying to find 42 in the vector: " Colors::RESET;
	// // 	std::cout << Colors::GREEN << *easyfind(tab2, 42) << " was found" Colors::RESET << std::endl;
	// // }
	// // catch(const std::exception& e)
	// // {
	// // 	std::cerr << Colors::RED "Exception caught: " << e.what() << Colors::RESET << std::endl;
	// // }
// }

