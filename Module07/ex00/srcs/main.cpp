/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:47:31 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/09 17:14:19 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "templates.hpp"
#include <iostream>

#define BOLD "\033[1m"
#define RESET "\033[0m"

class MyClass {};

int main( void ) {
int a = 2;
int b = 3;

std::cout << BOLD "INT TESTS" RESET << std::endl;
std::cout << "a = " << a << ", b = " << b << std::endl;

std::cout << BOLD "SWAP" RESET << std::endl;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;

std::cout << BOLD "MIN MAX" RESET << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::cout << std::endl;

std::cout << BOLD "STRING TESTS" RESET << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
std::cout << "c = " << c << ", d = " << d << std::endl;

std::cout << BOLD "SWAP" RESET << std::endl;
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;

std::cout << BOLD "MIN MAX" RESET << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
std::cout << std::endl;

std::cout << BOLD "POINTERS TESTS" RESET << std::endl;
std::string *e = &c;
std::string *f = 0;
std::cout << "e = " << e << ", f = " << f << std::endl;

std::cout << BOLD "SWAP" RESET << std::endl;
::swap(e, f);
std::cout << "e = " << e << ", f = " << f << std::endl;

std::cout << BOLD "MIN MAX" RESET << std::endl;
std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
std::cout << std::endl;

std::cout << BOLD "CLASS TESTS" RESET << std::endl;
MyClass g;
MyClass h;
std::cout << BOLD "SWAP" RESET << std::endl;
::swap(g, h);
std::cout << BOLD "MIN MAX" RESET << std::endl;
// min( g, h ); // does not compile
return 0;
}
