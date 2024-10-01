/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeListFcts.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:13:05 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/10/01 17:19:44 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeTer.hpp"

bool	PmergeMe::isListSorted(t_list &list)
{
	if (list.empty())
		return true;

	t_list::const_iterator it = list.begin();
	t_list::const_iterator itNext = it;
	itNext++;
	while (itNext != list.end())
	{
		if (*it > *itNext)
			return false;
		it++;
		itNext++;
	}
	return true;
}

static void	fillPairsList(t_list &list, t_pairsList &pairsList)
{
	pairsList.clear();
	const size_t		size = list.size();
	t_list::iterator	it = list.begin();
	
	for (size_t i = 0; i < size / 2; ++i)
	{
		const unsigned int		a = *(it++);
		const unsigned int		b = *(it++);
		pairsList.push_back(std::make_pair(std::min(a, b), std::max(a, b)));
	}
}

static t_pairsList merge(const t_pairsList &listA, const t_pairsList &listB)
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

static t_pairsList	mergeSortPairsList(const t_pairsList &list)
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

static size_t	binarySearchList(const t_list &list, unsigned int element, size_t low, size_t high)
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
	{
		if (mid == 0)
			return 0;
		return binarySearchList(list, element, low, mid - 1);
	}
	return binarySearchList(list, element, mid + 1, high);
}

static void	binaryInsertList(t_list &list, unsigned int element, size_t size)
{
	if (size > list.size())
		size = list.size();
	size_t loc = binarySearchList(list, element, 0, size);
	t_list::iterator	it = list.begin();
	std::advance(it, loc);
	list.insert(it, element);
	LOG(GREY << "	  > element to insert = "<< CYAN << element << GREY <<  " -> inserted at position " << loc << RESET);
}

static void	insertSortList(t_list &list, t_pairsList &pairsList, size_t nbElements)
{
	if (pairsList.empty())
		return ;

	list.clear();
	list.push_back(pairsList.begin()->first);

	for (t_pairsList::iterator it = pairsList.begin(); it != pairsList.end(); it++)
		list.push_back(it->second);
	LOG(WHITE << "	1rst sorted list:	" << list << RESET << " (first value and biggest number of each pair, before insertion of smallest values)");

	size_t nbPairs = pairsList.size();
	t_vector jacobsthalSeq;
	generateJacobsthalSequence(jacobsthalSeq, nbPairs);

	size_t	currLevel = 2;
	size_t	maxElementsToSort = 3;
	t_pairsList::iterator it = pairsList.begin();

	while (jacobsthalSeq[currLevel] < nbPairs)
	{
		std::advance(it, jacobsthalSeq[currLevel] - jacobsthalSeq[currLevel - 1]);
		for (size_t i = jacobsthalSeq[currLevel]; i > jacobsthalSeq[currLevel - 1]; i--)
			binaryInsertList(list, (it--)->first, maxElementsToSort);
		std::advance(it, jacobsthalSeq[currLevel] - jacobsthalSeq[currLevel - 1]);
		LOG(WHITE << "	" << currLevel << "th sorted list:	" << list << RESET 
				<< " (after insertion of small elements from pairs " << jacobsthalSeq[currLevel]- 1 << " to " << jacobsthalSeq[currLevel - 1] << " within the first " << maxElementsToSort << " elements of the list)");
		++currLevel;
		maxElementsToSort = pow(2, currLevel) - 1;
		if (maxElementsToSort > nbElements)
			maxElementsToSort = nbElements;
	}
}

void PmergeMe::sortList(t_list &list)
{
	t_pairsList	pairsList;
	
	LOG(WHITE  << std::endl << "---------------------------------------COMMENTS---------------------------------------" << RESET << std::endl);
	LOG(WHITE << "Unsorted list: 	" << list << RESET);
	fillPairsList(list, pairsList);
	LOG(WHITE << "Pairs list: 		" << pairsList << RESET << " (list into pairs whose second element is the biggest)");
	LOG(YELLOW << "-- Merge sort --" << RESET);
	pairsList = mergeSortPairsList(pairsList);
	LOG(WHITE << "Sorted pairs list: 	" << pairsList << RESET << " (pairs sorted by their second element with a merge sort)");
	LOG(YELLOW << "-- Insertion sort --" << RESET);
	insertSortList(list, pairsList, _nbElements);
	if (_nbElements % 2 == 1)
		binaryInsertList(list, _lastElement, _nbElements);
	LOG(WHITE << "Sorted list: 		" << list << RESET);
	LOG(WHITE << "--------------------------------------------------------------------------------------" << RESET << std::endl);
}
