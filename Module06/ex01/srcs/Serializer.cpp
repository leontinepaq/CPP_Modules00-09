/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:15:20 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/06 16:29:33 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

Serializer::Serializer()
{
	std::cout << GREY "[Serializer] Default constructor called" RESET << std::endl;
}

Serializer::Serializer(const Serializer &src)
{
	std::cout << GREY "[Serializer] Copy constructor called" RESET << std::endl;
	(void)src;
}

Serializer& Serializer::operator=(const Serializer &src)
{
	std::cout << GREY "[Serializer] Assignment operator called" RESET << std::endl;
	(void)src;
	return *this;
}

Serializer::~Serializer()
{
	std::cout << GREY "[Serializer] Destructor called" RESET << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
