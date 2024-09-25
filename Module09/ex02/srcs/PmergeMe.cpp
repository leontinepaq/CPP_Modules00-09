/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:10:57 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/25 03:50:51 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe() : _nbElements(0), _lastElement(0)
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
	if (!elements || !elements[0])
		return putError("no element to sort");
	_list.clear();
	_vector.clear();
	int i = 0;
	while (elements[i])
	{
		std::stringstream	ss(elements[i]);
		t_unsInt			value;
		ss >> std::noskipws >> value;
		if (ss.fail() || ss.peek() != std::stringstream::traits_type::eof())
			return putError("invalid element (all elements must be t_unsInt)");
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

int PmergeMe::sort(char **elements, size_t size)
{
	(void) size;
	PmergeMe PM1;
	if (PM1.insertElements(elements))
		return 1;
	std::clock_t start = std::clock();
	PM1.sortList();
	std::clock_t end = std::clock();
	double duration1 = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "PM.sortList() took " << duration1 << " ms." << std::endl;

	PmergeMe PM2;
	if (PM2.insertElements(elements))
		return 1;
	start = std::clock();
	PM2._list.sort();
	if (PM2.isListSorted())
		std::cout << GREEN << "List is sorted !" << RESET << std::endl;
	else
		std::cout << RED << "Error: list is not sorted" << RESET << std::endl;
	end = std::clock();
	double duration2 = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "PM._list.sort() took " << duration2 << " ms." << std::endl;

	if (duration1 < duration2)
		std::cout << GREEN << "PM.sortList() is faster than PM._list.sort()" << RESET << std::endl;
	else
		std::cout << ORANGE << "PM.sortList() is slower than PM._list.sort()" << RESET << std::endl;
	return 0;
}
