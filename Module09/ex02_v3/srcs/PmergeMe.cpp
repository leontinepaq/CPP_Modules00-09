/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:10:57 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/10/01 18:11:15 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeTer.hpp"
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

// static size_t	nextPow2(size_t size)
// {
// 	size_t	pow2 = 1;
// 	while (pow2 < size)
// 		pow2 *= 2;
// 	return pow2;
// }


// static void	fillMatrix(t_vectMatrix &matrix, t_vector &vector)
// {
// 	size_t	size = vector.size();
// 	matrix.reserve(size);
// 	for (size_t i = 0; i < size; i++)
// 	{
// 		t_vector	tmp;
// 		tmp.push_back(vector[i]);
// 		matrix.push_back(tmp);
// 	}
// 	// size_t	pow2 = nextPow2(size);
// 	// //padding
// 	// for (size_t i = size; i < pow2; i++)
// 	// {
// 	// 	t_vector	tmp;
// 	// 	tmp.push_back(std::numeric_limits<unsigned int>::max());
// 	// 	matrix.push_back(tmp);
// 	// }
// }

// static void	putToVector(t_vector &vector, t_vectMatrix &matrix)
// {
// 	size_t	size = vector.size();
// 	vector.clear();
// 	vector.reserve(size);
// 	for (size_t i = 0; i < size; i++)
// 		vector.push_back(matrix[i][0]);
// }

int PmergeMe::sort(t_vector &vector)
{
	PmergeMe		pmergeMe(vector);

	if (isVectorSorted(vector))
	{
		std::cout << GREEN << "Vector is sorted !" << RESET << std::endl;
		return 0;
	}
	pmergeMe.fusionInsertSort(vector, 0);
	if (isVectorSorted(vector) == false)
		return putError("vector is not sorted");
	std::cout << GREEN << "Vector is sorted !" << RESET << std::endl;
	return 0;
}
