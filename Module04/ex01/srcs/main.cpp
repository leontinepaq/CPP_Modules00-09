/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:35:54 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/08 18:41:53 by lpaquatt         ###   ########.fr       */
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
	std::cout << WHITE "Felix has an idea: " RESET;
	felix->getBrain()->setIdea(0, "I want to eat fish");
	std::cout << felix->getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW "COPY" RESET << std::endl;
	std::cout << WHITE "Creating Garfield, a copy of Felix" << std::endl;
	Cat* Garfield = new Cat(*felix);	
	std::cout << WHITE "Garfield has the same idea as Felix: " RESET;
	std::cout << Garfield->getBrain()->getIdea(0) << std::endl;
	std::cout << WHITE "Garfield changes his mind" RESET << std::endl;
	Garfield->getBrain()->setIdea(0, "I want to eat pizza !!!");
	std::cout << WHITE "Garfield's new idea: " RESET;
	std::cout << Garfield->getBrain()->getIdea(0) << std::endl;
	std::cout << WHITE "Felix's idea is still the same: " RESET;
	std::cout << felix->getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;
	
	std::cout << YELLOW "DELETING ANIMALS" RESET << std::endl;
	std::cout << WHITE "Deleting Idefix" << std::endl;
	delete idefix;
	std::cout << WHITE "Deleting Felix" << std::endl;
	delete felix;
	std::cout << WHITE "Deleting Felix copy" << std::endl;
	delete Garfield;
	std::cout << std::endl;

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
