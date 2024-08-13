/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:35:54 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/13 03:04:16 by lpaquatt         ###   ########.fr       */
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

	std::cout << YELLOW "GIVING AN IDEA TO FELIX" RESET << std::endl;
	std::cout << WHITE "Felix has an idea: " RESET;
	felix->setIdea(0, "I want to eat fish");
	std::cout << felix->getIdea(0) << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW "COPYING FELIX" RESET << std::endl;
	std::cout << WHITE "Creating Garfield, a copy of Felix" << std::endl;
	Cat* garfield = new Cat(*felix);	
	std::cout << WHITE "Garfield has the same idea as Felix: " RESET;
	std::cout << garfield->getIdea(0) << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW "CHANGING GARFIELD'S IDEA" RESET << std::endl;
	std::cout << WHITE "Garfield changes his mind" RESET << std::endl;
	garfield->setIdea(0, "I want to eat pizza !!!");
	std::cout << WHITE "Garfield's new idea: " RESET;
	std::cout << garfield->getIdea(0) << std::endl;
	std::cout << WHITE "Felix's idea is still the same: " RESET;
	std::cout << felix->getIdea(0) << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW "ASSIGNING FELIX TO A NEW INSTANCE" RESET << std::endl;
	std::cout << WHITE "Creating Grosminet" << std::endl;
	Cat grosminet;
	std::cout << WHITE "Assigning Felix to Grosminet" << std::endl;
	grosminet = *felix;
	std::cout << WHITE "Grosminet's idea: " RESET;
	std::cout << grosminet.getIdea(0) << std::endl;
	std::cout << std::endl;
	
	std::cout << YELLOW "DELETING ANIMALS" RESET << std::endl;
	std::cout << WHITE "Deleting Idefix" << std::endl;
	delete idefix;
	std::cout << WHITE "Deleting Felix" << std::endl;
	delete felix;
	std::cout << WHITE "Deleting Garfield" << std::endl;
	delete garfield;
	std::cout << std::endl;
	
	std::cout << WHITE "Grosminet's idea: " RESET;
	std::cout << grosminet.getIdea(0) << std::endl;
	return 0;
}

// int main(void)
// {
// 	unsigned int N = 6;
// 	const Animal *animals[N];
	
// 	for (unsigned int i = 0; i < N; i++)
// 	{
// 		if (i % 2 == 0)
// 			animals[i] = new Dog();
// 		else
// 			animals[i] = new Cat();
// 	}
// 	std::cout << std::endl;

// 	for (unsigned int i = 0; i < N; i++)
// 	{
// 		delete animals[i];
// 	}
	
// }
