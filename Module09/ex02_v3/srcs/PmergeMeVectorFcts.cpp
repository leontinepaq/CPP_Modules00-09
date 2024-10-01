/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVectorFcts.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:13:05 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/10/01 18:12:36 by lpaquatt         ###   ########.fr       */
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

// void	sortPairs(t_vector &vector, t_vector &S ,size_t size, unsigned int level)
// {
	
// 	S.clear();
// 	S.reserve(size);
// 	size_t		sizeS = size / (int)pow(2, level + 1);
// 	t_vector	swapTrack;
	
// 	std::cout << ORANGE << "Test >\tsize  = " << size << RESET << std::endl;
// 	std::cout << ORANGE << "\tsizeS  = " << sizeS << RESET << std::endl;
	
// 	for (size_t i = 0; i < 2 * sizeS; i++)
// 		swapTrack.push_back(i);

// 	//sort main chain
// 	for (size_t i = 0; i + 1 < 2 * sizeS; i += 2)
// 	{
// 		if (vector[i] < vector[i + 1])
// 		{
// 			unsigned int tmp;
// 			tmp = vector[i];
// 			vector[i] = vector[i + 1];
// 			vector[i + 1] = tmp;
// 			swapTrack[i / 2] = i + 1;
// 			swapTrack[sizeS + i / 2] = i;			
// 		}
// 		else
// 		{
// 			swapTrack[i / 2] = i;
// 			swapTrack[sizeS + i / 2] = i + 1;	
// 		}
// 		S.push_back(vector[i]);		
// 	}
// 	for (size_t i = 0; i < 2 * sizeS; i+= 2)
// 		S.push_back(vector[i + 1]);
// 	//sort pend
// 	for (size_t i = 2 * sizeS; i < size; i ++)
// 		S.push_back(vector[i - i % (2 * sizeS) + swapTrack[ i % (2  *sizeS)]]);
// }

// void	insertSort(t_vector &vector, t_vector &S, size_t size, unsigned int level)
// {
// 	size_t	sizeS = size / (int)pow(2, level + 1);

// 	std::cout << ORANGE << "test >\tS = " << S
// 		<< "\n\tsizeS = " << sizeS << std::endl;

// 	if (sizeS == 1)
// 	{
// 		vector = S;
// 		return;
// 	}
// 	vector.clear();
// 	vector.reserve(size);
// 	(void) level;
// }

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
	{
		t_vector::const_iterator	it = vector.begin();
		std::advance(it, low);
		return (element < *it) ? low +1 : low;
	}

	size_t	mid = (low + high) / 2;
	t_vector::const_iterator	it = vector.begin();
	std::advance(it, mid);
	if (element == *it)
		return mid;
	else if (element > *it)
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
	size_t loc = binarySearchVector(vector, element, vector.size() - size,  vector.size());
	vector.insert(vector.begin() + loc, element);
	LOG(GREY << "	  > element to insert = "<< CYAN << element << GREY <<  " -> inserted at position " << loc << RESET);
	return loc;
}

t_vector PmergeMe::fusionInsertSort(t_vector &vector, unsigned int level)
{
	LOG(WHITE << std::endl << "-------------------------------------MERGE INSERT LEVEL " << level << "-------------------------------------" << RESET << std::endl);
	LOG(WHITE << "0 - Unsorted vector : " << RESET << vector);
	
	size_t size = vector.size();
	
	t_vector swapTrack;
	for (size_t i = 0; i < size; i++)
		swapTrack.push_back(i);

	if (size <= 1)
		return swapTrack;
	else if (size == 2)
	{
		if (vector[0] < vector[1])
		{
			swap(vector, 0, 1);
			swap(swapTrack, 0, 1);
		}
		LOG(GREEN << std::endl << "-----------------------------------------EXIT LEVEL " << level << "-----------------------------------------" << std::endl
			<< "Sorted vector:\t" << vector << std::endl
			<< "SwapTrack: " << swapTrack<< std::endl
			<< "----------------------------------------------------------------------------------------------");
		return swapTrack;
	}

	t_vector 	S, pend;
	S.reserve(size / 2);

	LOG(CYAN << "> Constructing S");
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
	LOG(WHITE << "1 + 2 - Sorted big elements by pairs :\t" << RESET << vector);
	LOG(CYAN << "S = " << S << std::endl
		<< "swapTrack = " << swapTrack);

	t_vector swapTrackRec = fusionInsertSort(S, level + 1);
	LOG(WHITE << std::endl << "----------------------------------------BACK TO LEVEL " << level << "---------------------------------------" << RESET);
	LOG(WHITE << "3 - Sorted S vector: 	" << RESET << S);

	size_t	sizeS = S.size();
	for (size_t i = 0; i < sizeS; i++)
		pend.push_back(vector[2 * swapTrackRec[i] + 1]);

	t_vector	combinedSwapTrack;
	combinedSwapTrack.reserve(size);
	
	for (size_t i = 0; i < sizeS; i++)
		combinedSwapTrack.push_back(swapTrack[2 * swapTrackRec[i]]);
	std::cout << ORANGE << "CombinedSwapTrack: " << combinedSwapTrack << std::endl;
		
	S.push_back(pend.back());
	// pend.pop_back();
	combinedSwapTrack.push_back(swapTrack[2 * swapTrackRec[sizeS - 1] + 1]);
	LOG(WHITE << "4 - Add the smallest element to S: 	" << RESET << S);
	std::cout << ORANGE << "CombinedSwapTrack: " << combinedSwapTrack << std::endl;
	std::cout << ORANGE << "pend: " << pend << std::endl;

	size_t sizePend = pend.size();
	
	LOG(WHITE << "	1rst sorted vector:	" << S << RESET << " (first value and biggest number of each pair, before insertion of smallest values)");
	t_vector jacobsthalSeq;
	size_t	currLevel = 1;
	size_t	maxElementsToSort = 3;
	generateJacobsthalSequence(jacobsthalSeq, sizePend);
	std::cout << ORANGE << "JacobsthalSeq: " << jacobsthalSeq << std::endl;
	while (currLevel < jacobsthalSeq.size())
	{
		for (size_t i = jacobsthalSeq[currLevel]; i > jacobsthalSeq[currLevel - 1]; i--)
		{
			std::cout << ORANGE << "Inserting >> " << pend[sizePend - i - 1]<< RESET << std::endl;
			size_t loc = binaryInsertVector(S, pend[sizePend - 1 - i], maxElementsToSort);
			combinedSwapTrack.insert(combinedSwapTrack.begin() + loc, swapTrack[2 * swapTrackRec[sizePend - 1 - i] + 1]);
		}
		LOG(WHITE << "	" << currLevel + 1 << "th sorted vector:	" << S << RESET);
				// << " (after insertion of small elements from pairs " << jacobsthalSeq[currLevel] - 1 << " to " << jacobsthalSeq[currLevel - 1] << " within the first " << maxElementsToSort << " elements of the vector)");
		currLevel++;
		maxElementsToSort = pow(2, currLevel) - 1;
		if (maxElementsToSort > sizePend)
			maxElementsToSort = sizePend;
		// return combinedSwapTrack;
	}
	
	vector = S;
	return combinedSwapTrack;
}
