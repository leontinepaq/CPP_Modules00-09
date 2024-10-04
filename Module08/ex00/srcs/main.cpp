/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:52:06 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/10/04 12:05:10 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "Colors.hpp"
#include <iostream>
#include <vector>
#include <list>

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
	std::cout << CYAN << "TEST WITH INT VECTOR" << RESET << std::endl;
	int values[] = {1, 500, 42, -1};
	size_t n = sizeof(values) / sizeof(values[0]);
	std::vector<int> tab = valuesToVector(values, n);
	
	std::cout << WHITE << "tab = [ ";
	for (std::vector<int>::iterator it = tab.begin(); it != tab.end(); ++it)
		std::cout << *it << " ";
	std::cout << "]" << RESET << std::endl;

	try
	{
		std::vector<int>::iterator toFind; 
		std::cout << WHITE << "> Trying to find 42 in the vector: " << RESET;
		toFind = easyfind(tab, 42);
		std::cout << GREEN << *toFind << " was found at index " 
			<< toFind - tab.begin() << RESET << std::endl; 
		std::cout << WHITE << "> Trying to find 0 in the vector: " << RESET;
		toFind = easyfind(tab, 0);
		std::cout << GREEN << *toFind << " was found at index " 
			<< toFind - tab.begin() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << CYAN << "TEST WITH INT LIST" << RESET << std::endl;
	int values2[] = {0, 1, -1, 42, 50, 42};
	n = sizeof(values2) / sizeof(values2[0]);
	std::list<int> list = valuesToList(values2, n);
	std::cout << WHITE<< "list = [ ";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
		std::cout << *it << " ";
	std::cout << "]" << RESET << std::endl;
	try
	{
		std::list<int>::iterator toFind;
		std::cout << WHITE << "> Trying to find 42 in the list: " << RESET;
		toFind = easyfind(list, 42);
		std::cout << GREEN << *toFind << " was found at index " 
			<< std::distance(list.begin(), toFind) << RESET << std::endl;
		std::cout << WHITE << "> Trying to find 0 in the list: " << RESET;
		toFind = easyfind(list, 0);
		std::cout << GREEN << *toFind << " was found at index " 
			<< std::distance(list.begin(), toFind) << RESET << std::endl;		
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	// std::cout << CYAN << "TEST WITH STRING VECTOR" << RESET << std::endl;
	// std::vector<std::string> tab2;
	// tab2.push_back("Hello");
	// tab2.push_back("World");
	// tab2.push_back("42");
	
	// std::cout << WHITE << "tab2 = [ ";
	// for (std::vector<std::string>::iterator it = tab2.begin(); it != tab2.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << "]" << RESET << std::endl;
	
	// std::cout<< RED << "> Does not compile <" << RESET << std::endl;
	// // try
	// // {
	// // 	std::cout << WHITE "> Trying to find 42 in the vector: " RESET;
	// // 	std::cout << GREEN << *easyfind(tab2, 42) << " was found" RESET << std::endl;
	// // }
	// // catch(const std::exception& e)
	// // {
	// // 	std::cerr << RED "Exception caught: " << e.what() << RESET << std::endl;
	// // }
}

