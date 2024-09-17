/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:47:06 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/17 23:12:15 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "Colors.hpp"

#include <iostream>
#include <list>

#define MAIN_NB 0

#if MAIN_NB == 0
int main()
{
	std::cout << BLUE << "CREATION OF MUTANT STACK" << RESET << std::endl;
	MutantStack<int> mstack;
	std::cout << std::endl;
	
	std::cout << YELLOW << "STACK METHODS" << RESET << std::endl;
	std::cout << BLUE << "PUSHING ELEMENTS 5 AND 17" << RESET << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << WHITE << "> Stack size: " << mstack.size() << RESET << std::endl;
	std::cout << WHITE << "> Top element: " << mstack.top() << RESET << std::endl;

	std::cout << BLUE << "POPING ELEMENT" << RESET << std::endl;
	mstack.pop();
	std::cout << WHITE << "> Stack size: " << mstack.size() << RESET << std::endl;
	std::cout << WHITE << "> Top element: " << mstack.top() << RESET << std::endl;

	std::cout << BLUE << "PUSHING ELEMENTS 3, 5, 737 AND 0" << RESET << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << WHITE << "> Stack size: " << mstack.size() << RESET << std::endl;
	std::cout << WHITE << "> Top element: " << mstack.top() << RESET << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "ITERATORS" << RESET << std::endl;
	std::cout << BLUE << "CREATING ITERATORS AND USING INCREMENT OPERATORS" << RESET << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << WHITE << "> First element: " << *it << RESET << std::endl;
	++it;
	std::cout << WHITE << "> Second element: " << *it << RESET << std::endl;
	--it;
	std::cout << BLUE << "DISPLAYING ALL ELEMENTS" << RESET << std::endl;
	int i = 0;
	while (it != ite)
	{
		std::cout << WHITE << "> Element " << i++ << ": " << *it << std::endl;
		++it;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "CREATION OF STACK FROM MUTANT STACK" << RESET << std::endl;
	std::stack<int> s(mstack);
	return 0;
}
#endif

#if MAIN_NB == 1

static void	compareMStackNList(MutantStack<int> &mstack, std::list<int> list)
{
	if (mstack.top() == list.back())
		std::cout << GREEN << ">> Top elements are the same" << RESET << std::endl;
	else
		std::cout << RED << ">> Top elements are different" << RESET << std::endl;
	if (mstack.size() == list.size())
		std::cout << GREEN << ">> Sizes are the same" << RESET << std::endl;
	else
		std::cout << RED << ">> Sizes are different" << RESET << std::endl;

}

int main()
{
	std::cout << YELLOW << "COMPARISION BETWEEN MUTANT STACK AND LIST" << RESET << std::endl << std::endl;
	std::cout << BLUE << "CREATION OF MUTANT STACK AND A LIST" << RESET << std::endl;
	MutantStack<int> mstack;
	std::list<int> list;
	std::cout << std::endl;

	std::cout << BLUE << "PUSHING ELEMENTS 5 AND 17" << RESET << std::endl;
	mstack.push(5);
	mstack.push(17);
	list.push_back(5);
	list.push_back(17);
	compareMStackNList(mstack, list);
	std::cout << std::endl;
		
	std::cout << BLUE << "POPING ELEMENT" << RESET << std::endl;
	mstack.pop();
	list.pop_back();
	compareMStackNList(mstack, list);
	std::cout << std::endl;

	std::cout << BLUE << "PUSHING ELEMENTS 3, 5, 737 AND 0" << RESET << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	compareMStackNList(mstack, list);
	std::cout << std::endl;

	std::cout << BLUE << "DISPLAYING ELEMENTS" << RESET << std::endl;
	MutantStack<int>::iterator itMstack = mstack.begin();
	MutantStack<int>::iterator iteMstack = mstack.end();
	std::list<int>::iterator itList = list.begin();
	std::list<int>::iterator iteList = list.end();
	int i = 0;
	while (itMstack != iteMstack && itList != iteList)
	{
		if (*itMstack == *itList)
			std::cout << GREEN << ">> Element " << i++ << " are the same" << RESET << std::endl;
		else
			std::cout << RED << ">> Element " << i++ << " are different" << *itMstack << RESET << std::endl;
		++itMstack;
		++itList;
	}
	std::cout << std::endl;

	return 0;
}
#endif
