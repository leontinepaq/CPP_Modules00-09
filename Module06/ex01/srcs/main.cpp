/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:24:22 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/06 16:38:47 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

/*
reinterpret_cast is the most dangerous cast, and should be used very sparingly. It turns one type directly into another — such as casting the value from one pointer to another, or storing a pointer in an int, or all sorts of other nasty things
Largely, the only guarantee you get with reinterpret_cast is that normally if you cast the result back to the original type, you will get the exact same value (but not if the intermediate type is smaller than the original type).
*/

int main(void)
{
	Data dataPreSerializer(42, "Hello world");

	std::cout << CYAN "Data before serialization:" RESET << std::endl;
	std::cout << WHITE "Value: " RESET << dataPreSerializer.getValue() << std::endl;
	std::cout << WHITE "String: " RESET << dataPreSerializer.getStr() << std::endl;
	std::cout << WHITE "Address: " RESET << &dataPreSerializer << std::endl;
	std::cout << std::endl;
	
	std::cout << BLUE "Serialization:" RESET << std::endl;
	uintptr_t raw = Serializer::serialize(&dataPreSerializer);
	std::cout << WHITE "Raw: " RESET << raw << std::endl;
	std::cout << std::endl;
	
	std::cout << BLUE "Deserialization" RESET << std::endl;
	Data *dataPostSerializer = Serializer::deserialize(raw);

	std::cout << CYAN "Data after deserialization:" RESET << std::endl;
	std::cout << WHITE "Value: " RESET << dataPostSerializer->getValue() << std::endl;
	std::cout << WHITE "String: " RESET << dataPostSerializer->getStr() << std::endl;
	std::cout << WHITE "Address: " RESET << dataPostSerializer << std::endl;
	std::cout << std::endl;

	if (dataPreSerializer.getValue() == dataPostSerializer->getValue()
		&& dataPreSerializer.getStr() == dataPostSerializer->getStr()
		&& &dataPreSerializer == dataPostSerializer)
		std::cout << GREEN "Serialization and deserialization successful" RESET << std::endl;
	else
		std::cout << RED "Serialization and deserialization failed" RESET << std::endl;

}