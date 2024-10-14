/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVectorFcts.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:13:05 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/10/03 15:54:25 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeTer.hpp"

bool	PmergeMe::isVectorSorted(t_vector &vector)
{
	if (vector.size() < 2)
		return true;

	for (size_t i = 1; i < vector.size(); i++)
	{
		if (vector[i - 1] < vector[i])
			return false;
	}
	return true;
}

void	swap(t_vector &vector, size_t i, size_t j)
{
	unsigned int tmp;

	if (vector.size() < std::max(i, j))
		return ;
	tmp = vector[i];
	vector[i] = vector[j];
	vector[j] = tmp;
}

static size_t	binarySearchVector(const t_vector &vector, unsigned int element, size_t low, size_t high)
{
	if (low >= high)
		return (element < vector[low]) ? low +1 : low;

	size_t	mid = (low + high) / 2;
	if (element == vector[mid])
		return mid;
	else if (element > vector[mid])
	{
		if (mid == 0)
			return 0;
		return binarySearchVector(vector, element, low, mid - 1);
	}
	return binarySearchVector(vector, element, mid + 1, high);
}

static size_t	binaryInsertVector(t_vector &vector, unsigned int element, size_t size)
{
	if (size > vector.size())
		size = vector.size();
	size_t loc = binarySearchVector(vector, element, vector.size() - size,  vector.size() -1);
	vector.insert(vector.begin() + loc, element);
	LOG(GREY << "	  > element to insert = "<< CYAN << element << GREY <<  " -> inserted at position " << loc);
	return loc;
}

static void sortPairs(t_vector &vector, t_vector &S, t_vector &pend, t_vector &swapTrack)
{
	size_t size = vector.size();

	for (size_t i = 0; i < size; i += 2)
	{
		if (i + 1 < size)
		{
			if (vector[i] < vector[i + 1])
			{
				swap(vector, i, i + 1);
				swap(swapTrack, i, i + 1);
			}
			S.push_back(vector[i]);
		}
		else
			pend.push_back(vector[i]);
	}
	LOG(WHITE << "1 + 2 - Sorted big elements by pairs :\t" << vector);
	LOG(CYAN << "S = " << S);
}

static void smallSort(t_vector &vector, t_vector &swapTrack, unsigned int level)
{
	size_t	size = vector.size();

	if (size == 2)
	{
		if (vector[0] < vector[1])
		{
			swap(vector, 0, 1);
			swap(swapTrack, 0, 1);
		}
	}
	(void) level;
	LOG(GREEN << std::endl << "-----------------------------------------EXIT LEVEL " << level << "-----------------------------------------" << std::endl
		<< "Sorted vector:\t" << vector << std::endl
		<< "SwapTrack: " << swapTrack<< std::endl
		<< "----------------------------------------------------------------------------------------------");
}

static unsigned int	indexMoved(t_tracking &swapTrack, size_t index, bool odd)
{
	return swapTrack.v[2 * swapTrack.rec[index] + odd];
}

static void trackMovement(t_tracking &swapTrack, size_t loc, size_t index, int odd)
{
	if (odd == -1)
		swapTrack.combined.insert(swapTrack.combined.begin() + loc, index);
	else
		swapTrack.combined.insert(swapTrack.combined.begin() + loc, indexMoved(swapTrack, index, odd));
}

static void insertSort(t_vector &S, t_vector &pend, t_tracking &swapTrack)
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
	LOG(WHITE << "	1rst sorted vector:	" << S);

	// INSERT EVERY ELEMENT OF PEND INTO S FOLLOWING THE JACOBSTHAL SEQUENCE
	while (currLevel < jacobsthalSeq.size())
	{
		for (size_t i = jacobsthalSeq[currLevel]; i > jacobsthalSeq[currLevel - 1]; i--)
		{
			size_t	index = sizePend - 1 - i;
			size_t loc = binaryInsertVector(S, pend[index], maxElementsToSort);
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

t_vector PmergeMe::fusionInsertSort(t_vector &vector, unsigned int level)
{
	LOG(WHITE << std::endl << "-------------------------------------MERGE INSERT LEVEL " << level << "-------------------------------------" << std::endl);
	LOG(WHITE << "0 - Unsorted vector : " << vector);
	
	size_t size = vector.size();
	
	// CREATE A VECTOR THAT WILL TRACK THE MOVEMENTS WHEN SORTING
	t_tracking swapTrack;
	for (size_t i = 0; i < size; i++)
		swapTrack.v.push_back(i);

	// LESS THAN 3 ELEMENTS -> BREAK THE RECURSION
	if (size < 3)
	{
		smallSort(vector, swapTrack.v, level);
		return (swapTrack.v);
	}

	// SORT BY PAIRS AND CREATE A S VECTOR TO RECURSIVELY SORT
	t_vector 	S, pend;
	S.reserve(size / 2);
	sortPairs(vector, S, pend, swapTrack.v);

	// RECURSIVELY SORT S
	swapTrack.rec = fusionInsertSort(S, level + 1);
	
	LOG(WHITE << std::endl << "----------------------------------------BACK TO LEVEL " << level << "---------------------------------------");
	LOG(WHITE << "3 - Sorted S vector: 	" << S);
	
	size_t	sizeS = S.size();
	
	// PUSH SMALL ELEMENTS INTO PEND ACCORDINGLY TO THE MOVEMENTS OF THE BIG ELEMENT
	for (size_t i = 0; i < sizeS; i++)
		pend.push_back(vector[2 * swapTrack.rec[i] + 1]);
	LOG(CYAN << "Pend = " << pend);

	// COMBINE THE VECTORS TRACKING MOVEMENTS
	swapTrack.combined.reserve(size);
	for (size_t i = 0; i < sizeS; i++)
		trackMovement(swapTrack, i, i, 0);
	// INSERT SORT THE PEND VECTOR INTO THE S VECTOR
	insertSort(S, pend, swapTrack);
	
	vector = S;
	LOG(GREEN << std::endl << "-----------------------------------------EXIT LEVEL " << level << "-----------------------------------------" << std::endl
		<< "Sorted vector:\t" << vector << std::endl
		<< "SwapTrack:\t" << swapTrack.combined<< std::endl
		<< "----------------------------------------------------------------------------------------------");
	return swapTrack.combined;
}
