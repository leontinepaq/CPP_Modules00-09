/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVectorFcts.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:13:05 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/27 16:12:07 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	PmergeMe::isVectorSorted(t_vector &vector)
{
	if (vector.size() < 2)
		return true;

	for (size_t i = 1; i < vector.size(); i++)
	{
		if (vector[i - 1] > vector[i])
			return false;
	}
	return true;
}

static void	fillPairsVector(t_vector &vector, t_pairsVector &pairsVector)
{
	pairsVector.clear();
	const size_t		size = vector.size();
	t_vector::iterator	it = vector.begin();
	
	for (size_t i = 0; i < size / 2; ++i)
	{
		const unsigned int		a = *(it++);
		const unsigned int		b = *(it++);
		pairsVector.push_back(std::make_pair(std::min(a, b), std::max(a, b)));
	}
}

static t_pairsVector merge(const t_pairsVector &vectorA, const t_pairsVector &vectorB)
{
	t_pairsVector vectorRes;
	vectorRes.reserve(vectorA.size() + vectorB.size()); //avoid reallocations

	t_pairsVector::const_iterator itA = vectorA.begin();
	t_pairsVector::const_iterator itB = vectorB.begin();

	while (itA != vectorA.end() && itB != vectorB.end())
	{
		if (itA->second < itB->second)
		{
			vectorRes.push_back(*itA);
			itA++;
		}
		else
		{
			vectorRes.push_back(*itB);
			itB++;
		}
	}
	vectorRes.insert(vectorRes.end(), itA, vectorA.end());
	vectorRes.insert(vectorRes.end(), itB, vectorB.end());
	return vectorRes;
}

static t_pairsVector	mergeSortPairsVector(const t_pairsVector &vector)
{
	if (vector.size() <= 1)
		return vector;
	
	size_t			mid = vector.size() / 2;

	t_pairsVector	vectorA, vectorB;
	vectorA.reserve(mid);
	vectorB.reserve(vector.size() - mid);

	std::copy(vector.begin(), vector.begin() + mid, std::back_inserter(vectorA));
	std::copy(vector.begin() + mid, vector.end(), std::back_inserter(vectorB));

	vectorA = mergeSortPairsVector(vectorA);
	vectorB = mergeSortPairsVector(vectorB);

	return merge(vectorA, vectorB);
}

static size_t	binarySearchVector(const t_vector &vector, unsigned int element, size_t low, size_t high)
{
	if (low >= high)
	{
		t_vector::const_iterator	it = vector.begin();
		std::advance(it, low);
		return (element > *it) ? low +1 : low;
	}

	size_t	mid = (low + high) / 2;
	t_vector::const_iterator	it = vector.begin();
	std::advance(it, mid);
	if (element == *it)
		return mid;
	else if (element < *it)
	{
		if (mid == 0)
			return 0;
		return binarySearchVector(vector, element, low, mid - 1);
	}
	return binarySearchVector(vector, element, mid + 1, high);
}

static void	binaryInsertVector(t_vector &vector, unsigned int element, size_t size)
{
	if (size > vector.size())
		size = vector.size();
	size_t loc = binarySearchVector(vector, element, 0, size);
	vector.insert(vector.begin() + loc, element);
	LOG(GREY << "	  > element to insert = "<< CYAN << element << GREY <<  " -> inserted at position " << loc << RESET);
}

static void	insertSortVector(t_vector &vector, t_pairsVector &pairsVector, size_t nbElements)
{
	if (pairsVector.empty())
		return ;

	vector.clear();
	vector.reserve(nbElements);

	vector.push_back(pairsVector.begin()->first);

	for (t_pairsVector::iterator it = pairsVector.begin(); it != pairsVector.end(); it++)
		vector.push_back(it->second);
	LOG(WHITE << "	1rst sorted vector:	" << vector << RESET << " (first value and biggest number of each pair, before insertion of smallest values)");

	size_t nbPairs = pairsVector.size();
	std::vector<size_t> jacobsthalSeq;
	generateJacobsthalSequence(jacobsthalSeq, nbPairs);

	size_t	currLevel = 2;
	size_t	maxElementsToSort = 3;

	while (jacobsthalSeq[currLevel - 1] < nbPairs)
	{
		for (size_t i = jacobsthalSeq[currLevel] - 1; i >= jacobsthalSeq[currLevel - 1]; i--)
			binaryInsertVector(vector, pairsVector[i].first, maxElementsToSort);
		LOG(WHITE << "	" << currLevel << "th sorted vector:	" << vector << RESET 
				<< " (after insertion of small elements from pairs " << jacobsthalSeq[currLevel] - 1 << " to " << jacobsthalSeq[currLevel - 1] << " within the first " << maxElementsToSort << " elements of the vector)");
		++currLevel;
		maxElementsToSort = pow(2, currLevel) - 1;
		if (maxElementsToSort > nbElements)
			maxElementsToSort = nbElements;
	}
}

void PmergeMe::sortVector(t_vector &vector)
{
	t_pairsVector	pairsVector;
	
	LOG(WHITE  << std::endl << "---------------------------------------COMMENTS---------------------------------------" << RESET << std::endl);
	LOG(WHITE << "Unsorted vector: 	" << vector << RESET);
	fillPairsVector(vector, pairsVector);
	LOG(WHITE << "Pairs vector: 		" << pairsVector << RESET << " (vector into pairs whose second element is the biggest)");
	LOG(YELLOW << "-- Merge sort --" << RESET);
	pairsVector = mergeSortPairsVector(pairsVector);
	LOG(WHITE << "Sorted pairs vector: 	" << pairsVector << RESET << " (pairs sorted by their second element with a merge sort)");
	LOG(YELLOW << "-- Insertion sort --" << RESET);
	insertSortVector(vector, pairsVector, _nbElements);
	if (_nbElements % 2 == 1)
		binaryInsertVector(vector, _lastElement, _nbElements);
	LOG(WHITE << "Sorted vector: 		" << vector << RESET);
	LOG(WHITE << "--------------------------------------------------------------------------------------" << RESET << std::endl);
}
