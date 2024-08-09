/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:07:54 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/09 17:02:21 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include <iostream>

// ICharacter::ICharacter()
// {
// 	std::cout << ORANGE "[ICharacter]" GREY " Default constructor called" RESET << std::endl;
// }


// ICharacter::ICharacter(const ICharacter &src)
// {
// 	std::cout << ORANGE "[ICharacter]" GREY " Copy constructor called" RESET << std::endl;
// }


// ICharacter& ICharacter::operator=(const ICharacter &src)
// {
// 	std::cout << ORANGE "[ICharacter]" GREY " Assignment operator called" RESET << std::endl;
// }


ICharacter::~ICharacter()
{
	std::cout << ORANGE "[ICharacter]" GREY " Destructor called" RESET << std::endl;
}

