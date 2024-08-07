/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:12:33 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/07 11:47:09 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#define BOLD "\033[1m"

int main( void ) {

std::cout << BOLD << "Declare a Fixed variable a" << std::endl;
Fixed a;
std::cout << std::endl;

std::cout << BOLD << "Copy construct a Fixed variable b from a" << std::endl;
Fixed b( a );
std::cout << std::endl;

std::cout << BOLD << "Assign b to a new Fixed variable c" << std::endl;
Fixed c;
c = b;
std::cout << std::endl;

std::cout << BOLD << "Display the raw bits of a, b and c" << std::endl;
int raw_a = a.getRawBits();
std::cout << "a = " << raw_a << std::endl;

int raw_b = b.getRawBits();
std::cout << "b = " << raw_b << std::endl;

int raw_c = c.getRawBits();
std::cout << "c = " << raw_c << std::endl;
std::cout << std::endl;

std::cout << BOLD << "Display the raw bits of a in binary" << std::endl;
a.printBits();
std::cout << std::endl;

return 0;
}

// int main( void ) {
// Fixed a;
// Fixed b( a );
// Fixed c;
// c = b;
// std::cout << a.getRawBits() << std::endl;
// std::cout << b.getRawBits() << std::endl;
// std::cout << c.getRawBits() << std::endl;
// return 0;
// }
