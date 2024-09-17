/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:50:04 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/17 16:49:59 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Span.hpp"
#include <iostream>

int	main(void)
{
	std::cout << YELLOW << "FILLED SPAN" << RESET << std::endl;
	try
	{
		Span span(5);
		span.addNumber(100000);
		span.addNumber(10);
		span.addNumber(500);
		span.addNumber(100);
		span.addNumber(503);
		std::cout << CYAN;
		span.printNumbers();
		std::cout << WHITE << "> longuest span: " << span.longuestSpan() << RESET << std::endl;
		std::cout << WHITE << "> shortest span: " << span.shortestSpan() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "Exception catched: " << e.what() << RESET << '\n';
	}
	std::cout << std::endl;

	std::cout << YELLOW << "SPAN WITH ONE VALUE" << RESET << std::endl;
	try
	{
		Span span(5);
		span.addNumber(1);
		std::cout << CYAN;
		span.printNumbers();
		std::cout << WHITE << "> longuest span: " << span.longuestSpan() << RESET << std::endl;
		std::cout << WHITE << "> shortest span: " << span.shortestSpan() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "Exception catched: " << e.what() << RESET << '\n';
	}
	std::cout << std::endl;

	std::cout << YELLOW << "SPAN WITH TWO VALUES" << RESET << std::endl;
	try
	{
		Span span(5);
		span.addNumber(-1);
		span.addNumber(10);
		std::cout << CYAN;
		span.printNumbers();
		std::cout << WHITE << "> longuest span: " << span.longuestSpan() << RESET << std::endl;
		std::cout << WHITE << "> shortest span: " << span.shortestSpan() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "Exception catched: " << e.what() << RESET << '\n';
	}
	std::cout << std::endl;

	std::cout << YELLOW << "SPAN WITH MORE VALUES THAN POSSIBLE" << RESET << std::endl;
	try
	{
		Span span(5);
		span.addNumber(1);
		span.addNumber(10);
		span.addNumber(500);
		span.addNumber(109);
		span.addNumber(0);
		span.addNumber(0);
		std::cout << CYAN;
		span.printNumbers();
		std::cout << WHITE << "> longuest span: " << span.longuestSpan() << RESET << std::endl;
		std::cout << WHITE << "> shortest span: " << span.shortestSpan() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "Exception catched: " << e.what() << RESET << '\n';
	}
	std::cout << std::endl;

	std::cout << YELLOW << "EMPTY SPAN" << RESET << std::endl;
	try
	{
		Span emptySpan;
		emptySpan.addNumber(42);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "Exception catched: " << e.what() << RESET << '\n';
	}
	std::cout << std::endl;

	std::cout << YELLOW << "VERY BIG SPAN" << RESET << std::endl;
	try
	{
		Span bigSpan(100002);
		for (int i = 0; i < 100000; i++)
			bigSpan.addNumber(i * 10);
		// bigSpan.addNumber(3);
		// bigSpan.addNumber(10);
		std::cout << CYAN ;
		bigSpan.printNumbers();
		std::cout << WHITE << "> longuest span: " << bigSpan.longuestSpan() << RESET << std::endl;
		std::cout << WHITE << "> shortest span: " << bigSpan.shortestSpan() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "Exception catched: " << e.what() << RESET << '\n';
	}
}
