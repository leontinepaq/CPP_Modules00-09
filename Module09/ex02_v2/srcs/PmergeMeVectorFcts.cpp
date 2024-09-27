/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVectorFcts.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:13:05 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/27 21:18:02 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeBis.hpp"

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

static bool operator<(const t_vector &a, const t_vector &b)
{
	return a.back() < b.back();
}

static bool operator>(const t_vector &a, const t_vector &b)
{
	return a.back() > b.back();
}

static size_t	binarySearchMatVect(const t_vectMatrix &matrix, t_vector element, size_t low, size_t high)
{
	if (low >= high)
	{
		t_vectMatrix::const_iterator	it = matrix.begin();
		std::advance(it, low);
		return (element > *it) ? low +1 : low;
	}

	size_t	mid = (low + high) / 2;
	t_vectMatrix::const_iterator	it = matrix.begin();
	std::advance(it, mid);
	if (element == *it)
		return mid;
	else if (element < *it)
	{
		if (mid == 0)
			return 0;
		return binarySearchMatVect(matrix, element, low, mid - 1);
	}
	return binarySearchMatVect(matrix, element, mid + 1, high);
}

static void	binaryInsertMatVect(t_vectMatrix &matrix, t_vector element, size_t size)
{
	if (size > matrix.size())
		size = matrix.size();
	size_t loc = binarySearchMatVect(matrix, element, 0, size);
	matrix.insert(matrix.begin() + loc, element);
	LOG(GREY << "	  > element to insert = "<< CYAN << element << GREY <<  " -> inserted at position " << loc << RESET);
}

static void	dividePairs(t_vectMatrix &matrix, size_t nbElements)
{
	t_vectMatrix::iterator	it = matrix.begin();
	t_vectMatrix			tmp;
	tmp.reserve(nbElements);
	
	size_t		sizeVect = matrix[0].size();
	t_vector	a, b;
	a.reserve(sizeVect / 2);
	b.reserve(sizeVect / 2);
	for (size_t i = 0; i < nbElements / 2; i++)
	{
		for (size_t j = 0; j < sizeVect; j++)
		{
			if (j < sizeVect / 2)
				a.push_back((*it)[j]);
			else
				b.push_back((*it)[j]);
		}
		tmp.push_back(a);
		tmp.push_back(b);
		it++;	
		a.clear();
		b.clear();
	}
	matrix = tmp;
}

static void	insertSortVectMatrix(t_vectMatrix &matrix, t_vectMatrix &sortedMatrix)
{
	size_t	nbElements = matrix.size();
	LOG(WHITE << "	3 - Sorted pair matrix: " << RESET << sortedMatrix);
	dividePairs(sortedMatrix, nbElements);
	
	
	if (nbElements < 2)
		return ;

	matrix.clear();
	matrix.reserve(nbElements);
	matrix.push_back(sortedMatrix[0]);

	for (t_vectMatrix::iterator it = sortedMatrix.begin(); it < sortedMatrix.end(); it += 2)
		matrix.push_back(*(it + 1));	

	LOG(WHITE << "4-	1rst sorted vector:	" << matrix << RESET << " (first value and biggest number of each pair, before insertion of smallest values)");

	std::vector<size_t> jacobsthalSeq;
	generateJacobsthalSequence(jacobsthalSeq, nbElements / 2);

	size_t	currLevel = 2;
	size_t	maxElementsToSort = 3;

	LOG(WHITE << "5 - Insert using Jacobsthal sequence:	" << RESET);
	while (jacobsthalSeq[currLevel - 1] < nbElements / 2)
	{
		for (size_t i = jacobsthalSeq[currLevel] - 1; i >= jacobsthalSeq[currLevel - 1]; i--)
			binaryInsertMatVect(matrix, sortedMatrix[2 * i], maxElementsToSort);
		LOG(WHITE << "	" << currLevel << "th sorted vector:	" << matrix << RESET 
				<< " (after insertion of small elements from pairs " << jacobsthalSeq[currLevel] - 1 << " to " << jacobsthalSeq[currLevel - 1] << " within the first " << maxElementsToSort << " elements of the vector)");
		++currLevel;
		maxElementsToSort = pow(2, currLevel) - 1;
		if (maxElementsToSort > nbElements)
			maxElementsToSort = nbElements;
	}
}

t_vector minVect(const t_vector &a, const t_vector &b)
{
	return (a < b) ? a : b;
}

t_vector maxVect(const t_vector &a, const t_vector &b)
{
	return (a > b) ? a : b;
}

static void	sortPairs(t_vectMatrix &matrix, t_vectMatrix &sortedMatrix)
{
	for (t_vectMatrix::iterator it = matrix.begin(); it < matrix.end() ; it += 2)
	{
		t_vector tmp;
		t_vector min = minVect(*it, *(it + 1));
		t_vector max = maxVect(*it, *(it + 1));
		for (t_vector::iterator itVect = min.begin(); itVect < min.end(); itVect++)
			tmp.push_back(*itVect);
		for (t_vector::iterator itVect = max.begin(); itVect < max.end(); itVect++)
			tmp.push_back(*itVect);
		sortedMatrix.push_back(tmp);		
	}
}

t_vectMatrix PmergeMe::sortVectMat(t_vectMatrix &matrix)
{
	LOG(WHITE  << std::endl << "---------------------------------------MERGE INSERT---------------------------------------" << RESET << std::endl);
	LOG(WHITE << "0 - Unsorted vector matrix: " << RESET << matrix);
	t_vectMatrix sortedMatrix;
	sortPairs(matrix, sortedMatrix);
	LOG(WHITE << "1 + 2 - Matrix by pairs : 	" << RESET << sortedMatrix);
	if (sortedMatrix.size() < 2)
	{
		return sortedMatrix;
	}
	LOG(YELLOW << "-- Recursive sort --" << RESET);
	sortVectMat(sortedMatrix);
	LOG(WHITE << "3 - Sorted matrix: 	" << RESET << sortedMatrix);
	LOG(YELLOW << "-- Insertion sort --" << RESET);
	insertSortVectMatrix(matrix, sortedMatrix);
	return matrix;
}
