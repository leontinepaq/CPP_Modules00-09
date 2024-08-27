/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:12:33 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/07 16:44:27 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

#ifndef MAIN_NB
# define MAIN_NB 1
#endif

bool bsp( Point const a, Point const b, Point const c, Point const point);

#if MAIN_NB == 0
// test with point outside of the triangle
int	main(void)
{
	Point a(1.0f, 1.0f);
	Point b(2.0f, 2.0f);
	Point c(3.0f, 0.0f);
	Point p(4.0f, 2.0f);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "p = " << p << std::endl << std::endl;
	
	bool res = bsp(a, b, c, p);
	if (res == true)
		std::cout << GREEN << "Point p is inside the triangle abc";
	else
		std::cout << RED << "Point p is outside the triangle abc";
	std::cout << RESET << std::endl << std::endl;
	return 0;
}
#endif

#if MAIN_NB == 1
// test with point inside of the triangle
int main(void)
{
	Point a(1.0f, 1.0f);
	Point b(2.0f, 2.0f);
	Point c(3.0f, 0.0f);
	Point p(2.0f, 1.0f);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "p = " << p << std::endl << std::endl;
	
	bool res = bsp(a, b, c, p);
	if (res == true)
		std::cout << GREEN << "Point p is inside the triangle abc";
	else
		std::cout << RED << "Point p is outside the triangle abc";
	std::cout << RESET << std::endl << std::endl;
	return 0;
}
#endif

#if MAIN_NB == 2
// test with point on the edge of the triangle or bad triangle
int main(void)
{
	Point a(1.0f, 1.0f);
	Point b(2.0f, 2.0f);
	Point c(3.0f, 0.0f);
	Point p(1.5f, 1.5f);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "p = " << p << " (edge)" << std::endl << std::endl;
	
	bool res = bsp(a, b, c, p);
	if (res == true)
		std::cout << GREEN << "Point p is inside the triangle abc";
	else
		std::cout << RED << "Point p is outside the triangle abc";
	std::cout << RESET << std::endl << std::endl;

	std::cout << "----------------------------------------------------" << std::endl << std::endl;

	std::cout << "Test with bad triangle aac" << std::endl;
	bool res2 = bsp(a, a, c, p);
	if (res2 == true)
		std::cout << GREEN << "Point p is inside the triangle aac";
	else
		std::cout << RED << "Point p is outside the triangle aac";
	std::cout << RESET << std::endl << std::endl;

	std::cout << "----------------------------------------------------" << std::endl << std::endl;

	std::cout << "Test with bad triangle abp" << std::endl;
	bool res3 = bsp(a, b, p, p);
	if (res3 == true)
		std::cout << GREEN << "Point p is inside the triangle abp";
	else
		std::cout << RED << "Point p is outside the triangle abp";
	std::cout << RESET << std::endl << std::endl;
	return 0;
}
#endif
