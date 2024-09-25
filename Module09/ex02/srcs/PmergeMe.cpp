/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:10:57 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/25 16:53:55 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm> 

PmergeMe::PmergeMe() : _nbElements(0), _lastElement(0)
{
	// std::cout << "[PmergeMe] Default constructor called" << std::endl;
}


PmergeMe::PmergeMe(const PmergeMe &src) :
	_nbElements(src._nbElements), _lastElement(src._lastElement), _vector(src._vector),
	_pairsVector(src._pairsVector), _list(src._list), _pairsList(src._pairsList)
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
	_vector = src._vector;
	_list = src._list;
	_pairsVector = src._pairsVector;
	_pairsList = src._pairsList;
	return *this;
}

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
	if (!elements || !elements[0])
		return putError("no element to sort");
	_list.clear();
	_vector.clear();
	int i = 0;
	while (elements[i])
	{
		std::stringstream	ss(elements[i]);
		unsigned int			value;
		ss >> std::noskipws >> value;
		if (ss.fail() || ss.peek() != std::stringstream::traits_type::eof())
			return putError("invalid element (all elements must be unsigned int)");
		_list.push_back(value);
		_vector.push_back(value);
		_nbElements++;
		i++;
	}
	if (_nbElements %2 == 1)
		_lastElement = _list.back();
	return 0;
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

int PmergeMe::sort(char **elements)
{
	std::clock_t start;
	std::clock_t end;

	PmergeMe PM1;
	if (PM1.insertElements(elements))
		return 1;
	
	std::cout << MAGENTA << "Sorting " << PM1._nbElements << " elements" << RESET << std::endl;
	std::cout << MAGENTA << "> PmergeMe sorts" << RESET << std::endl;
	start = std::clock();
	PM1.sortList();
	end = std::clock();
	double duration1 = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "PM.sortList() took " << duration1 << " ms." << std::endl;
	
	start = std::clock();
	PM1.sortVector();
	end = std::clock();
	double duration3 = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "PM.sortVector() took " << duration3 << " ms." << std::endl;
	std::cout << std::endl;
	
	PmergeMe PM2;
	if (PM2.insertElements(elements))
		return 1;
	std::cout << MAGENTA << "> Standard sorts" << RESET << std::endl;
	start = std::clock();
	PM2._list.sort();
	end = std::clock();
	if (PM2.isListSorted())
		std::cout << GREEN << "List is sorted !" << RESET << std::endl;
	else
		std::cout << RED << "Error: list is not sorted" << RESET << std::endl;	
	double duration2 = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "PM._list.sort() took " << duration2 << " ms." << std::endl;

	start = std::clock();
	std::sort(PM2._vector.begin(), PM2._vector.end());
	end = std::clock();
	if (PM2.isVectorSorted())
		std::cout << GREEN << "Vector is sorted !" << RESET << std::endl;
	else
		std::cout << RED << "Error: vector is not sorted" << RESET << std::endl;
	double duration4 = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "std::sort() took " << duration4 << " ms." << std::endl;
	std::cout << std::endl;

	if (duration1 < duration2)
		std::cout << GREEN << "PM.sortList() is " << (int)(duration2 / duration1) << " times faster than PM._list.sort()" << RESET << std::endl;
	else
		std::cout << ORANGE << "PM.sortList() is " << (int)(duration1 / duration2) << " times slower than PM._list.sort()" << RESET << std::endl;

	if (duration3 < duration4)
		std::cout << GREEN << "PM.sortVector() is " << (int)(duration4 / duration3) << " times faster than std::sort()" << RESET << std::endl;
	else
		std::cout << ORANGE << "PM.sortVector() is " << (int)(duration3 / duration4) << " times slower than std::sort()" << RESET << std::endl;
	return 0;
}
