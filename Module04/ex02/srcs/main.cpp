/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:35:54 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/09 15:19:56 by lpaquatt         ###   ########.fr       */
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
	AAnimal* idefix = new Dog();
	std::cout << WHITE "Creating Felix the cat" << std::endl;
	Cat* felix = new Cat();
	std::cout << RED "Imopssible to create a random animal" << std::endl;
	// AAnimal* random = new AAnimal();
	std::cout << std::endl;

	std::cout << YELLOW "MAKING SOUNDS" RESET << std::endl;
	std::cout << WHITE "Idefix says: ";
	idefix->makeSound();
	std::cout << WHITE "Felix says: ";
	felix->makeSound();
	std::cout << std::endl;

	std::cout << YELLOW "DELETING ANIMALS" RESET << std::endl;
	std::cout << WHITE "Deleting Idefix" << std::endl;
	delete idefix;
	std::cout << WHITE "Deleting Felix" << std::endl;
	delete felix;
	return 0;
}
