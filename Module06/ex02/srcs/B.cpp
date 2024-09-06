/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:02:06 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/06 17:02:52 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"
#include <iostream>

B::B()
{
	std::cout << GREY "[B] Default constructor called" RESET << std::endl;
}


// B::B(const B &src)
// {
// 	std::cout << GREY "[B] Copy constructor called" RESET << std::endl;
// }


// B& B::operator=(const B &src)
// {
// 	std::cout << GREY "[B] Assignment operator called" RESET << std::endl;
// }

B::~B()
{
	std::cout << GREY "[B] Destructor called" RESET << std::endl;
}

