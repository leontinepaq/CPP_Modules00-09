/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:35:54 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/08 18:08:42 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "Animal.hpp"

int main(void)
{
	std::cout << YELLOW "CREATING ANIMALS" RESET << std::endl;
	std::cout << WHITE "Creating Idefix the dog" << std::endl;
	const Animal* idefix = new Dog();
	std::cout << WHITE "Creating Felix the cat" << std::endl;
	Cat* felix = new Cat();
	std::cout << std::endl;

	std::cout << YELLOW "COPY" RESET << std::endl;
	std::cout << WHITE "Creating a copy of Felix" << std::endl;
	Cat* felixCopy = new Cat(*felix);	
	std::cout << std::endl;
	
	std::cout << YELLOW "DELETING ANIMALS" RESET << std::endl;
	std::cout << WHITE "Deleting Idefix" << std::endl;
	delete idefix;
	std::cout << WHITE "Deleting Felix" << std::endl;
	delete felix;
	std::cout << WHITE "Deleting Felix copy" << std::endl;
	delete felixCopy;
	std::cout << std::endl;

	return 0;
}
