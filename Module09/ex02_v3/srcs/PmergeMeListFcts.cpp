/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeListFcts.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:13:05 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/10/14 13:52:47 by lpaquatt         ###   ########.fr       */
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
		if (*it < *itNext)
			return false;
		it++;
		itNext++;
	}
	return true;
}

static t_list::iterator	next(t_list::iterator it)
{
	it++;
	return it;
}

static void sortPairs(t_list &list, t_list &S, t_list &pend, t_list &swapTrack)
{
	t_list::iterator it = list.begin();
	t_list::iterator itNext = it;
	t_list::iterator itSwap = swapTrack.begin();
	while (it != list.end())
	{
		itNext = next(it);
		if (itNext == list.end())
		{
			pend.push_back(*it);
			break;
		}
		else
		{
			if (*it < *itNext)
			{
				std::iter_swap(it, itNext);
				t_list::iterator itSwapNext = next(itSwap);
				std::iter_swap(itSwap, itSwapNext);
			}
			S.push_back(*it);
		}
		++++itSwap;
		it = next(itNext);
	}
	LOG(WHITE << "1 + 2 - Sorted big elements by pairs :\t" << list);
	LOG(CYAN << "S = " << S);
}

static void smallSort(t_list &list, t_list &swapTrack, unsigned int level)
{
	size_t	size = list.size();

	if (size == 2)
	{
		t_list::iterator it1 = list.begin();
		t_list::iterator it2 = list.begin();
		it2++;
		if (*it1 < *it2)
		{
			std::iter_swap(it1, it2);
			swapTrack.push_back(0);
			swapTrack.pop_front();
		}
	}
	(void) level;
	LOG(GREEN << std::endl << "-----------------------------------------EXIT LEVEL " << level << "-----------------------------------------" << std::endl
		<< "Sorted list:\t" << list << std::endl
		<< "SwapTrack: " << swapTrack<< std::endl
		<< "----------------------------------------------------------------------------------------------");
}

static unsigned int	indexMoved(t_trackingL &swapTrack, size_t index, bool odd)
{
	t_list::iterator itRec = swapTrack.rec.begin();
	std::advance(itRec, index);
	size_t indexSwap = 2 * *itRec + odd;
	t_list::iterator itSwap = swapTrack.l.begin();
	std::advance(itSwap, indexSwap);
	return *itSwap;
}

static void trackMovement(t_trackingL &swapTrack, size_t loc, size_t index, int odd)
{	
	t_list::iterator it = swapTrack.combined.begin();
	std::advance(it, loc);

	if (odd == -1)
		swapTrack.combined.insert(it, index);
	else
		swapTrack.combined.insert(it, indexMoved(swapTrack, index, odd));
}

static t_list::iterator binarySearchList(unsigned int element, t_list::iterator low, t_list::iterator high)
{
    t_list::iterator mid;
	while (std::distance(low, high) > 0)
	{
        mid = low;
		std::advance(mid, std::distance(low, high) / 2);
        if (element == *mid)
            return mid;
        else if (element < *mid)
            low = next(mid);
        else
            high = mid;
    }
    return low;
}

static size_t	binaryInsertList(t_list &list, unsigned int element, size_t size)
{
	if (size > list.size())
		size = list.size();
	t_list::iterator itLow = list.begin();
	t_list::iterator itHigh = list.end();
	std::advance(itLow, list.size() - size);
	t_list::iterator it = binarySearchList(element, itLow, itHigh);
	list.insert(it, element);
	size_t loc = std::distance(list.begin(), it) - 1;
	LOG(GREY << "	  > element to insert = "<< CYAN << element << GREY <<  " -> inserted at position " << loc);
	return loc;
}

static void insertSort(t_list &S, t_list &pend, t_trackingL &swapTrack)
{
	// ADD THE SMALLEST ELEMENT TO S	
	size_t sizeS = S.size();
	size_t sizePend = pend.size();
	S.push_back(pend.back());
	trackMovement(swapTrack, sizeS, sizeS - 1, 1);
	LOG(WHITE << "4 - Added the smallest element to S: 	" << S);

	// GENERATE JACOBSTHAL SEQUENCE
	t_vector jacobsthalSeq;
	size_t	currLevel = 1;
	size_t	maxElementsToSort = 3;
	generateJacobsthalSequence(jacobsthalSeq, sizePend);
	LOG(BLUE << "JacobsthalSeq: " << jacobsthalSeq);
	LOG(WHITE << "	1rst sorted list:	" << S << RESET);

	// INSERT EVERY ELEMENT OF PEND INTO S FOLLOWING THE JACOBSTHAL SEQUENCE
	while (currLevel < jacobsthalSeq.size())
	{
		for (size_t i = jacobsthalSeq[currLevel]; i > jacobsthalSeq[currLevel - 1]; i--)
		{
			size_t	index = sizePend - 1 - i;
			t_list::iterator it = pend.begin();
			std::advance(it, index);
			size_t loc = binaryInsertList(S, *it, maxElementsToSort);
			if ((sizeS + sizePend) % 2 == 0)
				trackMovement(swapTrack, loc, index, 1);
			else if (index == 0)
				trackMovement(swapTrack, loc, sizeS + sizePend - 1, -1);
			else
				trackMovement(swapTrack, loc, index - 1, 1);
		}
		currLevel++;
		maxElementsToSort = pow(2, currLevel + 1) - 1;
		if (maxElementsToSort > 2 * sizePend)
			maxElementsToSort = 2 * sizePend;
	}
}

t_list PmergeMe::fusionInsertSort(t_list &list, unsigned int level)
{
	LOG(WHITE << std::endl << "-------------------------------------MERGE INSERT LEVEL " << level << "-------------------------------------" << std::endl);
	LOG(WHITE << "0 - Unsorted list : " << list);
	
	size_t size = list.size();
	
	// CREATE A VECTOR THAT WILL TRACK THE MOVEMENTS WHEN SORTING
	t_trackingL swapTrack;
	for (size_t i = 0; i < size; i++)
		swapTrack.l.push_back(i);

	// LESS THAN 3 ELEMENTS -> BREAK THE RECURSION
	if (size < 3)
	{
		smallSort(list, swapTrack.l, level);
		return (swapTrack.l);
	}

	// SORT BY PAIRS AND CREATE A S VECTOR TO RECURSIVELY SORT
	t_list 	S, pend;
	sortPairs(list, S, pend, swapTrack.l);

	// RECURSIVELY SORT S
	swapTrack.rec = fusionInsertSort(S, level + 1);
	
	LOG(WHITE << std::endl << "----------------------------------------BACK TO LEVEL " << level << "---------------------------------------");
	LOG(WHITE << "3 - Sorted S list: 	" << S);
	
	// PUSH SMALL ELEMENTS INTO PEND ACCORDINGLY TO THE MOVEMENTS OF THE BIG ELEMENT
	for (t_list::iterator it = swapTrack.rec.begin(); it != swapTrack.rec.end(); it++)
	{
		t_list::iterator itList = list.begin();
		advance(itList, 2 * *it + 1);
		pend.push_back(*itList);
	}
	LOG(CYAN << "Pend = " << pend);

	// COMBINE THE VECTORS TRACKING MOVEMENTS
	for (size_t i = 0; i < S.size(); i++)
		trackMovement(swapTrack, i, i, 0);
	
	// INSERT SORT THE PEND VECTOR INTO THE S VECTOR
	insertSort(S, pend, swapTrack);
	
	list = S;
	LOG(GREEN << std::endl << "-----------------------------------------EXIT LEVEL " << level << "-----------------------------------------" << std::endl
		<< "Sorted list:\t" << list << std::endl
		<< "SwapTrack:\t" << swapTrack.combined<< std::endl
		<< "----------------------------------------------------------------------------------------------");
	return swapTrack.combined;
}
