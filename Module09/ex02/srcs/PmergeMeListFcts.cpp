/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeListFcts.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:13:05 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/25 16:53:55 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	PmergeMe::isListSorted(void)
{
	if (_list.empty())
		return true;

	t_list::const_iterator it = _list.begin();
	t_list::const_iterator itNext = it;
	itNext++;
	while (itNext != _list.end())
	{
		if (*it > *itNext)
			return false;
		it++;
		itNext++;
	}
	return true;
}

void	PmergeMe::fillPairsList(void)
{
	_pairsList.clear();
	const size_t		size = _list.size();
	t_list::iterator	it = _list.begin();
	
	for (size_t i = 0; i < size / 2; ++i)
	{
		const unsigned int		a = *(it++);
		const unsigned int		b = *(it++);
		_pairsList.push_back(std::make_pair(std::min(a, b), std::max(a, b)));
	}
}

t_pairsList PmergeMe::merge(const t_pairsList &listA, const t_pairsList &listB)
{
	t_pairsList listRes;
	t_pairsList::const_iterator itA = listA.begin();
	t_pairsList::const_iterator itB = listB.begin();

	while (itA != listA.end() && itB != listB.end())
	{
		if (itA->second < itB->second)
		{
			listRes.push_back(*itA);
			itA++;
		}
		else
		{
			listRes.push_back(*itB);
			itB++;
		}
	}
	listRes.insert(listRes.end(), itA, listA.end());
	listRes.insert(listRes.end(), itB, listB.end());
	return listRes;
}

t_pairsList	PmergeMe::mergeSortPairsList(const t_pairsList &list)
{
	if (list.size() <= 1)
		return list;
	
	t_pairsList					listA, listB;
	t_pairsList::const_iterator	it = list.begin();
	size_t						mid = list.size() / 2;

	std::advance(it, mid);
	listA.insert(listA.end(), list.begin(), it);
	listB.insert(listB.end(), it, list.end());

	listA = mergeSortPairsList(listA);
	listB = mergeSortPairsList(listB);

	return merge(listA, listB);
}

size_t	PmergeMe::binarySearchList(const t_list &list, unsigned int element, size_t low, size_t high)
{
	if (low >= high)
	{
		t_list::const_iterator	it = list.begin();
		std::advance(it, low);
		return (element > *it) ? low +1 : low;
	}

	size_t	mid = (low + high) / 2;
	t_list::const_iterator	it = list.begin();
	std::advance(it, mid);
	if (element == *it)
		return mid;
	else if (element < *it)
		return binarySearchList(list, element, low, mid - 1);
	return binarySearchList(list, element, mid + 1, high);
}

void	PmergeMe::binaryInsertList(unsigned int element, size_t size)
{
	if (size > _list.size())
		size = _list.size();
	size_t loc = binarySearchList(_list, element, 0, size);
	t_list::iterator	it = _list.begin();
	std::advance(it, loc);
	_list.insert(it, element);
	LOG(GREY << "	  > element to insert = "<< CYAN << element << GREY <<  " -> inserted at position " << loc << RESET);
}

void	PmergeMe::insertSortList(void)
{
	if (_pairsList.empty())
		return ;

	_list.clear();
	_list.push_back(_pairsList.begin()->first);

	for (t_pairsList::iterator it = _pairsList.begin(); it != _pairsList.end(); it++)
		_list.push_back(it->second);
	LOG(WHITE << "	1rst sorted list:	" << _list << RESET << " (first value and biggest number of each pair, before insertion of smallest values)");

	std::vector<size_t> jacobsthalSeq;
	generateJacobsthalSequence(jacobsthalSeq, _pairsList.size());

	size_t	currLevel = 2;
	size_t	maxElementsToSort = 3;
	t_pairsList::iterator it = _pairsList.begin();

	while (maxElementsToSort <= _nbElements)
	{
		std::advance(it, jacobsthalSeq[currLevel] - jacobsthalSeq[currLevel - 1]);
		for (size_t i = jacobsthalSeq[currLevel]; i > jacobsthalSeq[currLevel - 1]; i--)
			binaryInsertList((it--)->first, maxElementsToSort);
		std::advance(it, jacobsthalSeq[currLevel] - jacobsthalSeq[currLevel - 1]);
		LOG(WHITE << "	" << currLevel << "th sorted list:	" << _list << RESET 
				<< " (after insertion of small elements from pairs " << jacobsthalSeq[currLevel]- 1 << " to " << jacobsthalSeq[currLevel - 1] << " within the first " << maxElementsToSort << " elements of the list)");
		++currLevel;
		maxElementsToSort = pow(2, currLevel) - 1;
	}
	if (_nbElements % 2 == 1)
		binaryInsertList(_lastElement, _nbElements);
}

void PmergeMe::sortList(void)
{
	if (_list.empty())
		return ;
	if (isListSorted())
		return ;
	LOG(WHITE << "Unsorted list: 		" << _list << RESET);
	fillPairsList();
	LOG(WHITE << "Pairs list: 		" << _pairsList << RESET << " (list into pairs whose second element is the biggest)");
	LOG(YELLOW << "-- Merge sort --" << RESET);
	_pairsList = mergeSortPairsList(_pairsList);
	LOG(WHITE << "Sorted pairs list: 	" << _pairsList << RESET << " (pairs sorted by their second element with a merge sort)");
	LOG(YELLOW << "-- Insertion sort --" << RESET);
	insertSortList();
	LOG(WHITE << "Sorted list: 		" << _list << RESET);
	if (isListSorted() == false)
		std::cout << RED << "Error: list is not sorted" << RESET << std::endl;
	else
		std::cout << GREEN << "List is sorted !" << RESET << std::endl;
	return ;
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
