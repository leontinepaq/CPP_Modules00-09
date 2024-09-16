/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:50:04 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/16 18:55:10 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Span.hpp"
#include <iostream>


int	main(void)
{
	Span span(5);
	Span emptySpan;

	try
	{
		emptySpan.addNumber(42);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "Exception catched: " << e.what() << RESET << '\n';
	}
	try
	{
		span.addNumber(1);
		span.addNumber(10);
		span.addNumber(500);
		span.addNumber(0);
		std::cout << WHITE << span.longuestSpan() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "Exception catched: " << e.what() << RESET << '\n';
	}
}
