/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:01:06 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/06 17:01:53 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include <iostream>

A::A()
{
	std::cout << GREY "[A] Default constructor called" RESET << std::endl;
}


// A::A(const A &src)
// {
// 	std::cout << GREY "[A] Copy constructor called" RESET << std::endl;
// }


// A& A::operator=(const A &src)
// {
// 	std::cout << GREY "[A] Assignment operator called" RESET << std::endl;
// }

A::~A()
{
	std::cout << GREY "[A] Destructor called" RESET << std::endl;
}

