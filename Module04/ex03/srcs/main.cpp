/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:35:54 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/09 18:21:12 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Character.hpp"

int main()
{
	AMateria *m = new Ice();
	Character *c = new Character("Ludo");

	m->clone();
	m->use(*c);
	c->equip(m->clone());
	
	
	delete m;
	delete c;
}
