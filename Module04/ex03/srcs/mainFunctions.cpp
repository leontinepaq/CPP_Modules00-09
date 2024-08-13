/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainFunctions.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:29:28 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/12 21:03:54 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mainHeader.hpp"

static ICharacter *getCharacter(t_params params, std::string display_mess)
{
	std::string	name;
	std::cout << YELLOW << display_mess << RESET << std::endl << "> ";
	std::getline(std::cin, name);
	if (name != params.name1 && name != params.name2)
	{
		std::cout << RED "Unknown character" RESET << std::endl;
		return 0;
	}
	if (name == params.name1)
		return (params.char1);
	else
		return (params.char2);
}

static int getIndex(std::string display_mess)
{
	std::string index;
	int idx;
	std::cout << YELLOW << display_mess << RESET << std::endl << "> ";
	std::getline(std::cin, index);
	std::istringstream iss(index);
	if (!(iss >> idx))
	{
		std::cout << RED "Invalid index : you must enter a number" RESET << std::endl;
		return (-1);
	}
	return (idx);
}

void help(void)
{
	std::cout << std::endl << YELLOW "Rules: " << std::endl;
	std::cout << WHITE "- You can learn materias (spells) and give them to your characters" << std::endl;
	std::cout << WHITE "- You can use materias from the inventory of your characters to heal or attack" << std::endl;
	std::cout << WHITE "- A character has " << NB_MATERIA << " pockets in its inventory" << std::endl;
	std::cout << WHITE "- You can only give a materia to a character if you already learned it" << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW "Available commands:" RESET << std::endl;
	std::cout << WHITE "- exit" RESET << " : exit the game" << std::endl;
	std::cout << WHITE "- help" RESET << " : display available commands" << std::endl;
	std::cout << WHITE "- display book" RESET << " : display the known materias in your spell book" << std::endl;
	std::cout << WHITE "- learn" RESET << " : write a new materiain your spell book" << std::endl;
	std::cout << WHITE "- erase" RESET << " : erase a materia from your spell book" << std::endl;
	std::cout << WHITE "- equip" RESET << " : give a materia to a character" << std::endl;
	std::cout << WHITE "- unequip" RESET << " : remove a materia from a character" << std::endl;
	std::cout << WHITE "- use" RESET << " : use a materia from a character" << std::endl;
}

void learn(t_params &params)
{
	std::cout << YELLOW "Here are the available materias you can learn:" RESET << std::endl;
	std::cout << WHITE "- ice" RESET << " : shoot an ice bolt a character" << std::endl;
	std::cout << WHITE "- cure" RESET << " : heal a character" << std::endl;
	std::cout << YELLOW "What type of materia do you want to learn?" RESET << std::endl << "> ";
	std::string type;
	std::getline(std::cin, type);
	if (type != "ice" && type != "cure")
	{
		std::cout << RED "Unknown materia type" RESET << std::endl;
		return ;
	}
	if (type == "ice")
		params.book->learnMateria(new Ice());
	else
		params.book->learnMateria(new Cure());
}

void erase(t_params &params)
{
	params.book->displayKnownMaterias();
	int	idx = getIndex("Which page of your book do you want to erase?");
	if (idx == -1)
		return ;
	params.book->eraseMateria(idx);
}

void display(t_params &params)
{
	params.book->displayKnownMaterias();
}

void equip(t_params &params)
{
	ICharacter *ch = getCharacter(params, "Which character do you want to equip?");
	if (!ch)
		return ;
	std::string type;
	std::cout << YELLOW "What type of materia do you want to give to " << ch->getName() << "?" RESET << std::endl << "> ";
	std::getline(std::cin, type);
	AMateria* m = params.book->createMateria(type);
	if (!m)
		return ;
	ch->equip(m);
}

void	unequip(t_params &params)
{
	ICharacter *ch = getCharacter(params, "Which character do you want to unequip?");
	if (!ch)
		return ;
	ch->displayInventory();
	int idx = getIndex("Which pocket of the inventory do you want to unequip?");
	if (idx == -1)
		return ;
	ch->unequip(idx);
}

void use(t_params params)
{
	ICharacter *chUser = getCharacter(params, "Which character will use a materia?");
	if (!chUser)
		return ;
	chUser->displayInventory();

	int idx = getIndex("In which pocket is the materia to use?");
	if (idx == -1)
		return ;
	
	ICharacter *chTarget = getCharacter(params, "Which character will be targeted?");
	if (!chTarget)
		return ;
	chUser->use(idx, *chTarget);	
}