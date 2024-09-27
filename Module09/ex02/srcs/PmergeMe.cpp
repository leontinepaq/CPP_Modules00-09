/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:10:57 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/27 16:14:55 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>


PmergeMe::PmergeMe() : _nbElements(0), _lastElement(0)
{
	// std::cout << "[PmergeMe] Default constructor called" << std::endl;
}

PmergeMe::PmergeMe(t_vector &vector) : _nbElements(vector.size()), _lastElement(vector.back())
{
	// std::cout << "[PmergeMe] Parametric constructor called" << std::endl;
}

PmergeMe::PmergeMe(t_list &list) : _nbElements(list.size()), _lastElement(list.back())
{
	// std::cout << "[PmergeMe] Parametric constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &src) :
	_nbElements(src._nbElements), _lastElement(src._lastElement)
{
	// std::cout << "[PmergeMe] Copy constructor called" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &src)
{
	// std::cout << "[PmergeMe] Assignment operator called" << std::endl;
	if (this == &src)
		return *this;
	_nbElements = src._nbElements;
	_lastElement = src._lastElement;
	return *this;
}

PmergeMe::~PmergeMe()
{
	// std::cout << "[PmergeMe] Destructor called" << std::endl;
}

static int putError(std::string mess)
{
	std::cerr << RED << "Error: " << mess << RESET << std::endl;
	return 1;
}

std::ostream  &operator<<(std::ostream &os, std::vector<size_t> vect)
{
	std::vector<size_t>::iterator	it = vect.begin();
	
 	for (it = vect.begin(); it != vect.end(); ++it)
	{
		os << *it;
		if (it != --vect.end())
			os << " ";
	}
	return os;
}

void	generateJacobsthalSequence(std::vector<size_t> &vect, size_t size)
{
	size_t	prev = 0;
	size_t	curr = 1;
	size_t	next = 0;
	
	vect.clear();
	vect.push_back(prev);
	if (size == 1)
		return;
	while (next < size)
	{
		next = curr + 2 * prev;
		if (next > size)
			next = size;
		vect.push_back(next);
		prev = curr;
		curr = next;
	}
	vect.push_back(size);
}

int PmergeMe::sort(t_list &list)
{
	PmergeMe	pmergeMe(list);
	
	if (pmergeMe.isListSorted(list))
	{
		std::cout << GREEN << "Vector is sorted !" << RESET << std::endl;
		return 0;
	}
	pmergeMe.sortList(list);
	if (pmergeMe.isListSorted(list) == false)
		return putError("list is not sorted");
	std::cout << GREEN << "List is sorted !" << RESET << std::endl;
	return 0;
}


int PmergeMe::sort(t_vector &vector)
{
	PmergeMe	pmergeMe(vector);
	
	if (pmergeMe.isVectorSorted(vector))
	{
		std::cout << GREEN << "Vector is sorted !" << RESET << std::endl;
		return 0;
	}
	pmergeMe.sortVector(vector);
	if (pmergeMe.isVectorSorted(vector) == false)
		return putError("vector is not sorted");
	std::cout << GREEN << "Vector is sorted !" << RESET << std::endl;
	return 0;
}

std::ostream  &operator<<(std::ostream &os, t_vector &vector)
{
	t_vector::iterator	it = vector.begin();
	
	int i = 0;
 	for (; it != vector.end(); ++it)
	{
		os << *it;
		if (it != --vector.end())
			os << " ";
		if (i++ > 20)
		{
			os << "[...]";
			break ;
		}
		os << " ";
	}
	return os;
}

std::ostream  &operator<<(std::ostream &os, t_pairsVector &vector)
{
	t_pairsVector::iterator	it = vector.begin();
	int i = 0;
 	for (it = vector.begin(); it != vector.end(); ++it)
	{
		os << WHITE  << "[ " << CYAN << it->first << " " << MAGENTA << it->second << WHITE << " ]" << RESET;
		if (it != --vector.end())
			os << " ";
		if (i++ > 10)
		{
			os << "[...]";
			break ;
		}
	}
	return os;
}

std::ostream  &operator<<(std::ostream &os, t_list &list)
{
	t_list::iterator	it = list.begin();
	
	int i = 0;
 	for (; it != list.end(); ++it)
	{
		os << *it;
		if (it != --list.end())
			os << " ";
		if (i++ > 20)
		{
			os << "[...]";
			break ;
		}
		os << " ";
	}
	return os;
}

std::ostream  &operator<<(std::ostream &os, t_pairsList &list)
{
	t_pairsList::iterator	it = list.begin();
	int i = 0;
 	for (it = list.begin(); it != list.end(); ++it)
	{
		os << WHITE  << "[ " << CYAN << it->first << " " << MAGENTA << it->second << WHITE << " ]" << RESET;
		if (it != --list.end())
			os << " ";
		if (i++ > 10)
		{
			os << "[...]";
			break ;
		}
	}
	return os;
}
