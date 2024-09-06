/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:02:55 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/06 17:03:32 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"
#include <iostream>

C::C()
{
	std::cout << GREY "[C] Default constructor called" RESET << std::endl;
}


// C::C(const C &src)
// {
// 	std::cout << GREY "[C] Copy constructor called" RESET << std::endl;
// }


// C& C::operator=(const C &src)
// {
// 	std::cout << GREY "[C] Assignment operator called" RESET << std::endl;
// }

C::~C()
{
	std::cout << GREY "[C] Destructor called" RESET << std::endl;
}

