/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:35:54 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/13 02:00:12 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mainHeader.hpp"

#define FUN_MAIN 1


#if FUN_MAIN == 1
void startGame(t_params &params)
{
	std::cout << YELLOW "Welcome to the game !" RESET << std::endl;
	help();
	std::cout << std::endl;

	std::cout << YELLOW "Let's start by creating your two characters" RESET << std::endl;
	std::cout << WHITE "How do you want to call your first character?" RESET << std::endl << "> ";
	std::getline(std::cin, params.name1);
	params.char1 = new Character(params.name1);
	std::cout << WHITE "How do you want to call your second character?" RESET << std::endl << "> ";
	std::getline(std::cin, params.name2);
	while (params.name1 == params.name2)
	{
		std::cout << RED "You can't have two characters with the same name" RESET << std::endl;
		std::cout << WHITE "How do you want to call your second character?" RESET << std::endl << "> ";
		std::getline(std::cin, params.name2);
	}
	params.char2 = new Character(params.name2);
	params.book = new MateriaSource();
	std::cout << std::endl;
	std::cout << YELLOW "Perfect, let's start the game !" RESET << std::endl;
	std::cout << YELLOW "You can type a command or 'help' to see the available commands" RESET << std::endl;
}

void execCmd(std::string cmd, t_params &params)
{
	if (cmd == "help")
		help();
	else if (cmd == "learn")
		learn(params);
	else if (cmd == "erase")
		erase(params);
	else if (cmd == "display book")
		display(params);
	else if (cmd == "equip")
		equip(params);
	else if (cmd == "unequip")
		unequip(params);
	else if (cmd == "use")
		use(params);
	else
		std::cout << RED "Unknown command, use 'help' to see available commands" RESET << std::endl;
}

int main(void)
{
	t_params params;
	
	startGame(params);
	while (true)
	{
		std::string	cmd;
		std::cout << std::endl << YELLOW "What do you want to do?" RESET << std::endl << "> ";
		std::getline(std::cin, cmd);
		if (cmd == "exit")
			break;
		else 
			execCmd(cmd, params);
		if (std::cin.eof())
			break;
	}
	std::cout << std::endl << YELLOW "Thx for playing to the game !!" RESET << std::endl << std::endl;
	delete params.char1;
	delete params.char2;
	delete params.book;
}
#endif

#if FUN_MAIN == 0
int main()
{
	std::cout << YELLOW "Creating a spell book" RESET << std::endl;
	IMateriaSource* book = new MateriaSource();
	std::cout << std::endl;

	std::cout << YELLOW "Learning Ice" RESET << std::endl;
	book->learnMateria(new Ice());
	std::cout << std::endl;
	std::cout << YELLOW "Learning Cure" RESET << std::endl;
	book->learnMateria(new Cure());
	std::cout << std::endl;
	
	std::cout << YELLOW "Displaying the known materias" RESET << std::endl;
	book->displayKnownMaterias();
	std::cout << std::endl;
	
	std::cout << YELLOW "Creating my character" RESET << std::endl;
	ICharacter* me = new Character("me");
	
	std::cout << YELLOW "Equipping it with Ice, Cure and Fire" RESET << std::endl;
	AMateria* tmp;
	tmp = book->createMateria("ice");
	me->equip(tmp);
	tmp = book->createMateria("cure");
	me->equip(tmp);
	tmp = book->createMateria("fire");
	me->equip(tmp);
	std::cout << std::endl;

	std::cout << YELLOW "Creating a character Bob and using Ice and Cure" RESET << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;
	
	std::cout << YELLOW "Deleting the characters and the book" RESET << std::endl;
	delete bob;
	delete me;
	delete book;
	return 0;
}
#endif

/*main from subject*/
#if FUN_MAIN == -1
int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}
#endif

#if FUN_MAIN == -2
int main() 
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		std::cout << std::endl;

		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << "1. Create new MateriaSource and learn materias (check maximum too):" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		AMateria *mat = new Cure();
		src->learnMateria(mat);
		std::cout << std::endl;
		
		std::cout << "2. Create 2 new characters and test deep copy:" << std::endl;
		Character *dur0 = new Character("Alice");
		ICharacter *dur1 = new Character(*dur0);
		delete dur0;
		delete dur1;
		std::cout << std::endl;

		std::cout << "3. Create materias and equip them (also check unknown materias):" << std::endl;
		AMateria* tmp;
		ICharacter *dur2 = new Character("Alice");
		tmp = src->createMateria("ice");
		dur2->equip(tmp);
		tmp = src->createMateria("cure");
		dur2->equip(tmp);
		tmp = src->createMateria("hi");
		dur2->equip(tmp);
		delete src;
		std::cout << std::endl;

		std::cout << "4. Check maximum equipped too:" << std::endl;
		AMateria *cure = new Cure();
		AMateria *ice = new Ice();
		dur2->equip(cure);
		dur2->equip(cure);
		dur2->equip(ice);
		dur2->unequip(2);
		// delete cure; // Cure must be deleted manually when unequipped
		dur2->unequip(2);
		dur2->unequip(6);
		std::cout << std::endl;

		std::cout << "5. Use materias on new chacarter:" << std::endl;
		ICharacter* bob = new Character("Bob");
		dur2->use(0, *bob);
		dur2->use(1, *bob);
		dur2->use(2, *bob);
		dur2->use(6, *bob);
		dur2->use(-4, *bob);
		dur2->use(3, *bob);
		delete bob;
		std::cout << std::endl;

		delete dur2;

		return (0); 
	}
}
#endif
