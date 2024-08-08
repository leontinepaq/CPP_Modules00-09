/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:59:36 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/08 16:53:19 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	_type = "Wrongcat";
	std::cout << PURPLE "[WrongCat]" GREY " Default constructor called" RESET << std::endl;
}


WrongCat::WrongCat(const WrongCat &src)
{
	*this = src;
	std::cout << PURPLE "[WrongCat]" GREY " Copy constructor called" RESET << std::endl;
}


WrongCat& WrongCat::operator=(const WrongCat &src)
{
	_type = src._type;
	std::cout << PURPLE "[WrongCat]" GREY " Assignment operator called" RESET << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << PURPLE "[WrongCat]" GREY " Destructor called" RESET << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << PURPLE "Miaouuu" RESET << std::endl;
}
