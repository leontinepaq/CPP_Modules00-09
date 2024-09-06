/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:34:18 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/06 16:39:54 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
types of casting
https://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used
static_cast is the first cast you should attempt to use. It does things like implicit conversions between types (such as int to float, or pointer to void*), and it can also call explicit conversion functions (or implicit ones).
*/

#include "ScalarConverter.hpp"

#define MAIN_NB 1

#if MAIN_NB == 0
int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << RED "Error: Invalid number of arguments" RESET << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	return (0);
}
#endif

#if MAIN_NB == 1

void test(std::string input)
{
	std::cout << CYAN "Input: " << input << RESET << std::endl;
	ScalarConverter::convert(input.c_str());
	std::cout << std::endl;
}

int main(void)
{
	std::string	input;

	
	std::cout << YELLOW "----- CHAR -----" RESET << std::endl;
	test("a");
	test("&");
	std::cout << std::endl;
	
	std::cout << YELLOW "----- INT -----" RESET << std::endl;
	test("42");
	test("-42");
	test("2147483647");
	test("2147483648");
	test("-2147483649");
	std::cout << std::endl;
	
	std::cout << YELLOW "----- FLOAT -----" RESET << std::endl;
	test("42.0f");
	test("42.42f");
	test(".0f");
	test("42.f");
	test("1.e30f");
	test("1.e42f");
	test("+inff");
	test("-inff");
	test("nanf");

	std::cout << YELLOW "----- DOUBLE -----" RESET << std::endl;
	test("42.0");
	test("42.42");
	test(".0");
	test("42.");
	test("1.e42");
	test("1.e310");
	test("+inf");
	test("-inf");
	test("nan");

	std::cout << YELLOW "----- RANDOM STRING -----" RESET << std::endl;
	test("42.42.42");
	test("abcd");
	test("");
}
#endif
