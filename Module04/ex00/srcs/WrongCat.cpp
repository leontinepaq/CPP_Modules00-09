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
	std::cout << PURPLE "[WrongCat]" GREY " Default constructor called" RESET << std::endl;
	_type = "Wrongcat";
}


WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	std::cout << PURPLE "[WrongCat]" GREY " Copy constructor called" RESET << std::endl;
	_type = src._type;
}


WrongCat& WrongCat::operator=(const WrongCat &src)
{
	std::cout << PURPLE "[WrongCat]" GREY " Assignment operator called" RESET << std::endl;
	_type = src._type;
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
