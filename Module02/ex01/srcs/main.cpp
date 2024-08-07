/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:12:33 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/07 12:07:17 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

#define BLUE "\033[1;34m"
#define RESET "\033[0m"

int main( void ) 
{
	std::cout << BLUE << "Declare a Fixed variable a" << RESET << std::endl;
	Fixed a;
	std::cout << std::endl;

	std::cout << BLUE << "Declare a Fixed variable b with value 10" << RESET << std::endl;
	Fixed const b( 10 );
	std::cout << std::endl;

	std::cout << BLUE << "Declare a Fixed variable c with value 42.42" << RESET << std::endl;
	Fixed const c( 42.42f);
	std:: cout << std::endl;

	std::cout << BLUE << "Copy construct a Fixed variable d from b" << RESET << std::endl;
	Fixed const d( b );
	std::cout << std::endl;

	std::cout << BLUE << "A is assigned the value 1234.4321" << RESET << std::endl;
	a = Fixed( 1234.4321f);
	std::cout << std::endl;
	
	std::cout << BLUE << "Display the values of a, b, c and d" << RESET << std::endl;
	std::cout << BLUE << "As fixed" << RESET << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << std::endl;
	
	std::cout << BLUE << "As integer" << RESET << std::endl;
	std::cout << "a is " << a.toInt() << std::endl;
	std::cout << "b is " << b.toInt() << std::endl;
	std::cout << "c is " << c.toInt() << std::endl;
	std::cout << "d is " << d.toInt() << std::endl;
	std::cout << std::endl;

	std::cout << BLUE << "As bits" << RESET << std::endl;
	std::cout << "a is ";
	a.printBits();
	std::cout << "b is ";
	b.printBits();
	std::cout << "c is ";
	c.printBits();
	std::cout << "d is ";
	d.printBits();
	std::cout << std::endl;
	return 0;
}

// int main( void ) {
// Fixed a;
// Fixed const b( 10 );
// Fixed const c( 42.42f);
// Fixed const d( b );
// a = Fixed( 1234.4321f);
// std::cout << "a is " << a << std::endl;
// std::cout << "b is " << b << std::endl;
// std::cout << "c is " << c << std::endl;
// std::cout << "d is " << d << std::endl;
// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
// std::cout << "d is " << d.toInt() << " as integer" << std::endl;
// return 0;
// }
