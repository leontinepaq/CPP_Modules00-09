/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeOld.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:10:57 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/25 00:10:43 by lpaquatt         ###   ########.fr       */
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
		t_unsInt		value;
		ss >> std::noskipws >> value;
		if (ss.fail() || ss.peek() != std::stringstream::traits_type::eof())
			return putError("invalid element (all elements must be t_unsInt)");
		_list.push_back(value);
		_vector.push_back(value);
		i++;
	}
	return 0;
}

bool	PmergeMe::isListSorted(void)
{
	std::list<t_unsInt>::iterator it = _list.begin();
	std::list<t_unsInt>::iterator itNext = _list.begin();
	itNext++;
	for (it = _list.begin(); it != _list.end(); ++it)
	{
		if (*it > *itNext)
			return false;
		itNext++;
	}
	return true;
}

// std::list<t_unsInt> PmergeMe::merge (std::list<t_unsInt> listA, std::list<t_unsInt> listB)
// {
// 	std::list<t_unsInt> list;

// 	while (!listA.empty() && !listB.empty())
// 	{
// 		if (*listA.begin() > *listB.begin())
// 		{
// 			list.push_back(*listB.begin());
// 			listB.pop_front();
// 		}
// 		else
// 		{
// 			list.push_back(*listA.begin());
// 			listA.pop_front();
// 		}
// 	}
// 	while (!listA.empty())
// 	{
// 		list.push_back(*listA.begin());
// 		listA.pop_front();
// 	}
// 	while (!listB.empty())
// 	{
// 		list.push_back(*listB.begin());
// 		listB.pop_front();
// 	}
// 	return list;
// }

std::list<t_unsInt>	PmergeMe::mergeSortList(std::list<t_unsInt> list)
{
	if (list.size() == 1)
		return list;

	std::list<t_unsInt> 			listA;
	std::list<t_unsInt> 			listB;
	std::list<t_unsInt>::iterator	it = list.begin();
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

// int PmergeMe::sortList(void)
// {
// 	if (_list.empty())
// 		return 0;
// 	if (isListSorted())
// 		return 0;
// 	_list = mergeSortList(_list);
// 	std::list<t_unsInt>::iterator	it = _list.begin();
	
//  	for (it = _list.begin(); it != _list.end(); ++it)
// 	{
// 		std::cout << *it << std::endl;
// 	}
// 	return 0;
// }

static std::ostream  &operator<<(std::ostream &os, std::list<t_unsInt> list)
{
	std::list<t_unsInt>::iterator	it = list.begin();
	
 	for (it = list.begin(); it != list.end(); ++it)
	{
		os << *it;
		if (it != --list.end())
			os << " ";
	}
	return os;
}

static void	pushBackList(std::list<t_unsInt> &dest, std::list<t_unsInt> &src, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (!src.empty())
		{
			dest.push_back(*src.begin());
			src.pop_front();
		}
	}
}

static void sortGroups(std::list<t_unsInt> &list, size_t size)
{
	std::list<t_unsInt> 			listA;
	std::list<t_unsInt> 			listB;
	std::list<t_unsInt> 			listRes;

	while (list.size() >= 2 *size)
	{
		pushBackList(listA, list, size);
		pushBackList(listB, list, size);
		if (listA.back() < listB.back())
		{
			pushBackList(listRes, listA, size);
			pushBackList(listRes, listB, size);
		}
		else
		{
			pushBackList(listRes, listB, size);
			pushBackList(listRes, listA, size);
		}
	}
	pushBackList(listRes, list, list.size());
	list = listRes;
}

std::list<t_unsInt>	PmergeMe::mergeSortList(std::list<t_unsInt> list, size_t size)
{
	if (2 * size > list.size())
		return list;
	// std::cout << "Entering merge sort of size " << size << std::endl;
	sortGroups(list, size);
	std::cout << "After first merge sort of size " << size << ", list: " << list << std::endl;
	mergeSortList(list, size * 2);
	// std::cout << "Leaving merge sort of size " << size << std::endl;
	return list;
}
void	PmergeMe::sortPairsList(void)
{
	t_unsInt	a;
	t_unsInt	b;
	size_t			size = _list.size();
	for (size_t i = 0; i < size / 2; i++)
	{
		a = *_list.begin();
		_list.pop_front();
		b = *_list.begin();
		_list.pop_front();
		_list.push_back(std::min(a, b));
		_list.push_back(std::max(a, b));
	}
	if (size % 2 == 1)
	{
		_list.push_back(*_list.begin());
		_list.pop_front();
	}
}


int PmergeMe::sortList(void)
{
	if (_list.empty())
		return 0;
	if (isListSorted())
		return 0;
	std::cout << "Unsorted list: 		" << _list << std::endl;
	sortPairsList();
	std::cout << "Sorted pairs list: 	" << _list << std::endl;
	_list = mergeSortList(_list, 2);
	std::cout << "List sorted: 		" << _list << std::endl;
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

// static void	generateJacobsthalSequence(std::vector<size_t> &vect, size_t size)
// {
// 	size_t	prev = 0;
// 	size_t	curr = 1;
// 	size_t	next = 0;
	
// 	vect.clear();
// 	vect.push_back(prev);
// 	if (size == 1)
// 		return;
// 	vect.push_back(curr);
// 	while (next < size)
// 	{
// 		next = curr + 2 * prev;
// 		if (next > size)
// 			next = size;
// 		for(size_t j = next; j > curr; j--)
// 			vect.push_back(j);
// 		prev = curr;
// 		curr = next;
// 	}
// 	std::cout << "test > Jacobsthal vect v0: " << vect <<  std::endl;
// }