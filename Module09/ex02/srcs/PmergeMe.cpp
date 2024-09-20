/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:10:57 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/20 17:38:39 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe()
{
	// std::cout << "[PmergeMe] Default constructor called" << std::endl;
}


// PmergeMe::PmergeMe(const PmergeMe &src)
// {
// 	std::cout << "[PmergeMe] Copy constructor called" << std::endl;
// }


// PmergeMe& PmergeMe::operator=(const PmergeMe &src)
// {
// 	std::cout << "[PmergeMe] Assignment operator called" << std::endl;
// }


PmergeMe::~PmergeMe()
{
	// std::cout << "[PmergeMe] Destructor called" << std::endl;
}

static int putError(std::string mess)
{
	std::cerr << "Error: " << mess << std::endl;
	return 1;
}


int	PmergeMe::insertElements(char ** elements)
{
	//vider les list et vector
	if (!elements || !elements[0])
		return putError("no element to sort");
	int i = 0;
	while (elements[i])
	{
		std::stringstream	ss(elements[i]);
		unsigned int		value;
		ss >> std::noskipws >> value;
		if (ss.fail() || ss.peek() != std::stringstream::traits_type::eof())
			return putError("invalid element (all elements must be unsigned int)");
		_list.push_back(value);
		_vector.push_back(value);
		i++;
	}
	return 0;
}

bool	PmergeMe::isListSorted(void)
{
	std::list<unsigned int>::iterator it = _list.begin();
	std::list<unsigned int>::iterator itNext = _list.begin();
	itNext++;
	for (it = _list.begin(); it != _list.end(); ++it)
	{
		if (*it > *itNext)
			return false;
		itNext++;
	}
	return true;
}

std::list<unsigned int> PmergeMe::merge (std::list<unsigned int> listA, std::list<unsigned int> listB)
{
	std::list<unsigned int> list;

	while (!listA.empty() && !listB.empty())
	{
		if (*listA.begin() > *listB.begin())
		{
			list.push_back(*listB.begin());
			listB.pop_front();
		}
		else
		{
			list.push_back(*listA.begin());
			listA.pop_front();
		}
	}
	while (!listA.empty())
	{
		list.push_back(*listA.begin());
		listA.pop_front();
	}
	while (!listB.empty())
	{
		list.push_back(*listB.begin());
		listB.pop_front();
	}
	return list;
}

std::list<unsigned int>	PmergeMe::mergeSortList(std::list<unsigned int> list)
{
	if (list.size() == 1)
		return list;

	std::list<unsigned int> 			listA;
	std::list<unsigned int> 			listB;
	std::list<unsigned int>::iterator	it = list.begin();
	size_t								i = 0;
	
 	for (it = list.begin(); it != list.end(); ++it)
	{
		if (i++ < list.size() / 2)
			listA.push_back(*it);
		else
			listB.push_back(*it);
	}
	listA = mergeSortList(listA);
	listB = mergeSortList(listB);
	
	return merge(listA, listB);	
}

int PmergeMe::sortList(void)
{
	if (_list.empty())
		return 0;
	if (isListSorted())
		return 0;
	_list = mergeSortList(_list);
	std::list<unsigned int>::iterator	it = _list.begin();
	
 	for (it = _list.begin(); it != _list.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	return 0;
}


int PmergeMe::sort(char **elements, size_t size)
{
	(void) size;
	PmergeMe PM;
	if (PM.insertElements(elements))
		return 1;
	PM.sortList(); //erreur possible ?
	return 0;
}
