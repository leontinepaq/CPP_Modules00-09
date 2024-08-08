/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:35:54 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/08 17:08:18 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"

int main()
{
	std::cout << YELLOW "CREATING ANIMALS" RESET << std::endl;
	std::cout << WHITE "Creating a random animal" << std::endl;
	const Animal* randomAnimal = new Animal();
	std::cout << WHITE "Creating Idefix the dog" << std::endl;
	const Animal* idefix = new Dog();
	std::cout << WHITE "Creating a Felix the cat" << std::endl;
	const Animal* felix = new Cat();
	std::cout << std::endl;

	std::cout << YELLOW "GETING ANIMAL TYPES" RESET << std::endl;
	std::cout << WHITE "Idefix is a " << idefix->getType() << std::endl;
	std::cout << WHITE "Felix is a " << felix->getType() << std::endl;
	std::cout << WHITE "Random animal is an " << randomAnimal->getType() << std::endl;
	std::cout << std::endl;
	
	std::cout << YELLOW "MAKING SOUNDS" RESET << std::endl;
	std::cout << WHITE "Idefix makes a sound : " RESET;
	idefix->makeSound();
	std::cout << WHITE "Felix makes a sound : " RESET;
	felix->makeSound();
	std::cout << WHITE "Random animal makes a sound : " RESET;
	randomAnimal->makeSound();
	std::cout << std::endl;

	std::cout << YELLOW "DELETING ANIMALS" RESET << std::endl;
	std::cout << WHITE "Deleting Idefix" << std::endl;
	delete idefix;
	std::cout << WHITE "Deleting Felix" << std::endl;
	delete felix;
	std::cout << WHITE "Deleting Random animal" << std::endl;
	delete randomAnimal;
	std::cout << std::endl;

	std::cout << YELLOW "WRONG ANIMAL" RESET << std::endl;
	std::cout << WHITE "Creating a wrong cat Feloux" << std::endl;
	const WrongAnimal* feloux = new WrongCat();
	std::cout << WHITE "Feloux is a " << feloux->getType() << std::endl;
	std::cout << WHITE "Feloux makes a sound : " RESET;
	feloux->makeSound();
	std::cout << WHITE "Deleting Feloux" << std::endl;
	delete feloux;

	return 0;
}

