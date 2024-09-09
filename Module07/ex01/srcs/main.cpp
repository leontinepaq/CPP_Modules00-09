/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:45:52 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/09 18:03:11 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

#define CYAN "\033[1;36m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

void add_one(int &i)
{
	i++;
}
void add_one(char &c)
{
	c++;
}

template< typename T >
void print(T &i)
{
	std::cout << i << std::endl;
}

int main()
{
	std::cout << CYAN << "Testing with int array" << RESET << std::endl;
	int array[] = {1, 2, 3, 4, 5};
	std::cout << BLUE << "Print array:" << RESET << std::endl;
	iter(array, 5, &print);
	std::cout << BLUE << "Add one to each element:" << RESET << std::endl;
	iter(array, 5, &add_one);
	iter(array, 5, &print);
	std::cout << std::endl;

	std::cout << CYAN << "Testing with char array" << RESET << std::endl;
	char array2[] = {'a', 'b', 'c', 'd', 'e'};
	std::cout << BLUE << "Print array:" << RESET << std::endl;
	iter(array2, 5, &print);
	std::cout << BLUE << "Add one to each element:" << RESET << std::endl;
	iter(array2, 5, &add_one);
	iter(array2, 5, &print);
	std::cout << std::endl;
}
