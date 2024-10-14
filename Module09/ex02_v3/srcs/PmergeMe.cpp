/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:10:57 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/10/14 13:52:10 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeTer.hpp"
#include <iostream>


PmergeMe::PmergeMe()
{
	// std::cout << "[PmergeMe] Default constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	(void) src;
	// std::cout << "[PmergeMe] Copy constructor called" << std::end;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &src)
{
	// std::cout << "[PmergeMe] Assignment operator called" << std::endl;
	(void) src;
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



void	generateJacobsthalSequence(t_vector &vect, size_t size)
{
	unsigned int	prev = 0;
	unsigned int	curr = 1;
	unsigned int	next = 0;
	
	vect.clear();
	vect.push_back(prev);
	if (size == 1)
		return;
	while (next < size)
	{
		next = curr + 2 * prev;
		if (next >= size - 1)
			break ;
		vect.push_back(next);
		prev = curr;
		curr = next;
	}
	vect.push_back(size - 1);
}

int PmergeMe::sort(t_list &list)
{
	PmergeMe	pmergeMe;
	
	if (pmergeMe.isListSorted(list))
	{
		std::cout << GREEN << "List is sorted !" << RESET << std::endl;
		return 0;
	}
	pmergeMe.fusionInsertSort(list, 0);
	if (pmergeMe.isListSorted(list) == false)
		return putError("list is not sorted");
	std::cout << GREEN << "List is sorted !" << RESET << std::endl;
	return 0;
}

int PmergeMe::sort(t_vector &vector)
{
	PmergeMe		pmergeMe;

	if (isVectorSorted(vector))
	{
		std::cout << GREEN << "Vector is sorted !" << RESET << std::endl;
		return 0;
	}
	pmergeMe.fusionInsertSort(vector, 0);
	LOG("");
	if (isVectorSorted(vector) == false)
		return putError("vector is not sorted");
	std::cout << GREEN << "Vector is sorted !" << RESET << std::endl;
	return 0;
}
