/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeListFcts.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:13:05 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/25 00:16:13 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	PmergeMe::isListSorted(void)
{
	t_list::iterator it = _list.begin();
	t_list::iterator itNext = _list.begin();
	itNext++;
	for (it = _list.begin(); itNext != _list.end(); ++it)
	{
		if (*it > *itNext)
			return false;
		itNext++;
	}
	return true;
}

std::ostream  &operator<<(std::ostream &os, t_list list)
{
	t_list::iterator	it = list.begin();
	
	int i = 0;
 	for (it = list.begin(); it != list.end(); ++it)
	{
		os << *it;
		if (it != --list.end())
			os << " ";
		if (i++ > 20)
		{
			os << "[...]";
			break ;
		}		
	}
	return os;
}

std::ostream  &operator<<(std::ostream &os, t_pairsList list)
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


void	PmergeMe::fillPairsList(void)
{
	t_unsInt	a;
	t_unsInt	b;
	t_pair		pair;
	
	_pairsList.clear();
	size_t	size = _list.size();
	t_list::iterator	it = _list.begin();
	
	for (size_t i = 0; i < size / 2; i++)
	{
		a = *(it++);
		b = *(it++);
		pair.first = std::min(a,b);
		pair.second = std::max(a,b);
		_pairsList.push_back(pair);
	}
}

t_pairsList PmergeMe::merge(t_pairsList listA, t_pairsList listB)
{
	t_pairsList list;

	while (!listA.empty() && !listB.empty())
	{
		if (listA.begin()->second > listB.begin()->second)
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

t_pairsList	PmergeMe::mergeSortPairsList(t_pairsList &list)
{
	if (list.size() == 1)
		return list;
	
	t_pairsList				listA;
	t_pairsList				listB;
	t_pairsList::iterator	it;
	size_t					mid = list.size() / 2;
	size_t					i = 0;

 	for (it = list.begin(); it != list.end(); ++it)
	{
		if (i++ < mid)
			listA.push_back(*it);
		else
			listB.push_back(*it);
	}
	listA = mergeSortPairsList(listA);
	listB = mergeSortPairsList(listB);
	return merge(listA, listB);
}

size_t	binarySearchList(t_list list, t_unsInt element, size_t low, size_t high)
{
	if (low >= high)
	{
		t_list::iterator	it = list.begin();
		for (size_t i = 0; i < low; i++)
			it++;
		if (element > *it)
			return low +1;
		return low;
	}
	
	size_t	mid = (low + high) / 2;
	t_list::iterator	it = list.begin();
	for (size_t i = 0; i < mid; i++)
		it++;
	if (element == *it)
		return mid + 1;
	
	if (element < *it)
		return binarySearchList(list, element, low, mid - 1);
	return binarySearchList(list, element, mid + 1, high);
}


void	PmergeMe::binaryInsertList(t_unsInt element, size_t size)
{
	size_t loc = binarySearchList(_list, element, 0, size);
	t_list::iterator	it = _list.begin();
	for (size_t i = 0; i < loc && it != _list.end() ; i++)
		it++;
	if (it == _list.end())
		_list.push_back(element);
	else
		_list.insert(it , element);
	if (COMMENTS_ON)
		std::cout << GREY << "	  > element to insert = "<< CYAN << element << GREY <<  " -> inserted at position " << loc << RESET << std::endl;
}

void	PmergeMe::insertSortList(void)
{
	_list.clear();
	if (_pairsList.empty())
		return ;
	_list.push_back(_pairsList.begin()->first);

	for (t_pairsList::iterator it = _pairsList.begin(); it != _pairsList.end(); it++)
		_list.push_back(it->second);
	if (COMMENTS_ON)
		std::cout << WHITE << "	1rst sorted list:	" << _list << RESET << " (first value and biggest number of each pair, before insertion of smallest values)" << std::endl;
	std::vector<size_t> vectJacobsthal;
	generateJacobsthalSequence(vectJacobsthal, _pairsList.size());
	size_t sizeToCheck = 3;
	size_t	n = 2;
	t_pairsList::iterator it = _pairsList.begin();
	while (sizeToCheck <= _nbElements)
	{
		for (size_t i = vectJacobsthal[n - 1]; i < vectJacobsthal[n]; i++)
			it++;
		for (size_t i = vectJacobsthal[n]; i > vectJacobsthal[n-1]; i--)
			binaryInsertList((it--)->first, sizeToCheck);
		for (size_t i = vectJacobsthal[n - 1]; i < vectJacobsthal[n]; i++)
			it++;
		if (COMMENTS_ON)
			std::cout << WHITE << "	" << n << "th sorted list:	" << _list << RESET 
				<< " (after insertion of small elements from pairs " << vectJacobsthal[n]- 1 << " to " << vectJacobsthal[n - 1]
				<< " within the first " << sizeToCheck << " elements of the list)" << std::endl;
		n++;
		sizeToCheck = std::pow(2, n) - 1;
	}
	if (_nbElements % 2 == 1)
		binaryInsertList(_lastElement, _nbElements);
}

int PmergeMe::sortList(void)
{
	if (_list.empty())
		return 0;
	if (isListSorted())
		return 0;
	if (COMMENTS_ON)
		std::cout << WHITE << "Unsorted list: 		" << _list << RESET << std::endl;
	fillPairsList();
	if (COMMENTS_ON)
	{
		std::cout << WHITE << "Pairs list: 		" << _pairsList << RESET << " (list into pairs whose second element is the biggest)" << std::endl;	
		std::cout << YELLOW << "-- Merge sort --" << RESET << std::endl;
	}
	_pairsList = mergeSortPairsList(_pairsList);
	if (COMMENTS_ON)
	{
		std::cout << WHITE << "Sorted pairs list: 	" << _pairsList << RESET << " (pairs sorted by their second element with a merge sort)" << std::endl;
		std::cout << YELLOW << "-- Insertion sort --" << RESET << std::endl;
	}
	insertSortList();
	if (COMMENTS_ON)
	{
		std::cout << WHITE << "Sorted list: 		" << _list << RESET << std::endl;
		if (isListSorted() == false)
			std::cout << RED << "Error: list is not sorted" << RESET << std::endl;
		else
			std::cout << GREEN << "List is sorted !" << RESET << std::endl;
	}
	// if (isListSorted() == false)
	// 	std::cout << RED << "Error: list is not sorted" << RESET << std::endl;
	// else
	// 	std::cout << GREEN << "List is sorted !" << RESET << std::endl;
	return 0;
}
