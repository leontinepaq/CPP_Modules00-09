/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:45:06 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/30 21:27:10 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << GREY "[ShrubberyCreationForm] Default constructor called" RESET << std::endl;
	_target = "home";
	std::srand(std::time(0));
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << GREY "[ShrubberyCreationForm] Parametric constructor called" RESET << std::endl;
	_target = target;
	std::srand(std::time(0));
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src)
{
	std::cout << GREY "[ShrubberyCreationForm] Copy constructor called" RESET << std::endl;
	_target = src._target;
	std::srand(std::time(0));
}

// affectation cannot be done with const members
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << GREY "[ShrubberyCreationForm] Assignment operator called" RESET << std::endl;
	(void)src;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << GREY "[ShrubberyCreationForm] Destructor called" RESET << std::endl;
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return _target;
}

void	ShrubberyCreationForm::drawTree(std::ofstream &dest) const
{
	int	tree = std::rand() % 4;

	std::string files[4] = {"tree0.txt", "tree1.txt", "tree2.txt", "tree3.txt"};
	std::string fileName = "./ascii_trees/" + files[tree];
	std::ifstream src(fileName.c_str());
	if (!src.is_open())
	{
		throw std::runtime_error("it is impossible to open file: " + fileName);
	}
	dest << src.rdbuf();
	dest << std::endl << std::endl;
	std::cout << WHITE << "A new tree has been planted in " << getTarget() << "'s shrubbery" << RESET << std::endl;
	src.close();
}

void	ShrubberyCreationForm::executeAction(void) const
{
	std::string filename = getTarget() + "_shrubbery";
	std::ofstream os(filename.c_str(), std::ios::app);
	if (!os.is_open())
		throw std::runtime_error("it is impossible to open file: " + filename);
	try
	{
		drawTree(os);
	}
	catch (std::exception &e)
	{
		os.close();
		throw ;
	}
	os.close();
}
