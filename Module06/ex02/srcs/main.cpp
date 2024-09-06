/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:59:07 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/06 17:33:58 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <ctime>
#include <cstdlib>
#include <cstddef>

/*
dynamic_cast is exclusively used for handling polymorphism. You can cast a pointer or reference to any polymorphic type to any other class type 
(a polymorphic type has at least one virtual function, declared or inherited).
You can use it for more than just casting downwards – you can cast sideways or even up another chain.
The dynamic_cast will seek out the desired object and return it if possible.
If it can't, it will return nullptr in the case of a pointer, or throw std::bad_cast in the case of a reference.
*/

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

int main()
{
	Base *base;

	srand(time(0)); // check if it's supposed to be here
	for (int i = 0; i < 10; i++)
	{
		std::cout << YELLOW "Test " << i + 1 << RESET << std::endl;
		base = generate();
		std::cout << CYAN "Identify by pointer: " RESET;
		identify(base);
		std::cout << CYAN "Identify by reference: " RESET;
		identify(*base);
		delete base;
		std::cout << std::endl;
	}
	return 0;
}
