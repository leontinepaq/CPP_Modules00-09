/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVectorFcts.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:13:05 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/25 16:53:55 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	PmergeMe::isVectorSorted(void)
{
	if (_vector.empty())
		return true;

	for (size_t i = 1; i < _vector.size(); i++)
	{
		if (_vector[i - 1] > _vector[i])
			return false;
	}
	return true;
}

void	PmergeMe::fillPairsVector(void)
{
	_pairsVector.clear();
	const size_t		size = _vector.size();
	t_vector::iterator	it = _vector.begin();
	
	for (size_t i = 0; i < size / 2; ++i)
	{
		const unsigned int		a = *(it++);
		const unsigned int		b = *(it++);
		_pairsVector.push_back(std::make_pair(std::min(a, b), std::max(a, b)));
	}
}

t_pairsVector PmergeMe::merge(const t_pairsVector &vectorA, const t_pairsVector &vectorB)
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

t_pairsVector	PmergeMe::mergeSortPairsVector(const t_pairsVector &vector)
{
	if (vector.size() <= 1)
		return vector;
	
	size_t							mid = vector.size() / 2;

	t_pairsVector					vectorA, vectorB;
	vectorA.reserve(mid);
	vectorB.reserve(vector.size() - mid);

	std::copy(vector.begin(), vector.begin() + mid, std::back_inserter(vectorA));
	std::copy(vector.begin() + mid, vector.end(), std::back_inserter(vectorB));

	vectorA = mergeSortPairsVector(vectorA);
	vectorB = mergeSortPairsVector(vectorB);

	return merge(vectorA, vectorB);
}

size_t	PmergeMe::binarySearchVector(const t_vector &vector, unsigned int element, size_t low, size_t high)
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
		return binarySearchVector(vector, element, low, mid - 1);
	return binarySearchVector(vector, element, mid + 1, high);
}

void	PmergeMe::binaryInsertVector(unsigned int element, size_t size)
{
	if (size > _vector.size())
		size = _vector.size();
	size_t loc = binarySearchVector(_vector, element, 0, size);
	_vector.insert(_vector.begin() + loc, element);
	LOG(GREY << "	  > element to insert = "<< CYAN << element << GREY <<  " -> inserted at position " << loc << RESET);
}

void	PmergeMe::insertSortVector(void)
{
	if (_pairsVector.empty())
		return ;

	_vector.clear();
	_vector.reserve(_nbElements);

	_vector.push_back(_pairsVector.begin()->first);

	for (t_pairsVector::iterator it = _pairsVector.begin(); it != _pairsVector.end(); it++)
		_vector.push_back(it->second);
	LOG(WHITE << "	1rst sorted vector:	" << _vector << RESET << " (first value and biggest number of each pair, before insertion of smallest values)");

	std::vector<size_t> jacobsthalSeq;
	generateJacobsthalSequence(jacobsthalSeq, _pairsVector.size());

	size_t	currLevel = 2;
	size_t	maxElementsToSort = 3;

	while (maxElementsToSort <= _nbElements)
	{
		for (size_t i = jacobsthalSeq[currLevel]; i > jacobsthalSeq[currLevel - 1]; i--)
			binaryInsertVector(_pairsVector[i].first, maxElementsToSort);
		LOG(WHITE << "	" << currLevel << "th sorted vector:	" << _vector << RESET 
				<< " (after insertion of small elements from pairs " << jacobsthalSeq[currLevel]- 1 << " to " << jacobsthalSeq[currLevel - 1] << " within the first " << maxElementsToSort << " elements of the vector)");
		++currLevel;
		maxElementsToSort = pow(2, currLevel) - 1;
	}
	if (_nbElements % 2 == 1)
		binaryInsertVector(_lastElement, _nbElements);
}

void PmergeMe::sortVector(void)
{
	if (_vector.empty())
		return ;
	if (isVectorSorted())
		return ;
	LOG(WHITE << "Unsorted vector: 		" << _vector << RESET);
	fillPairsVector();
	LOG(WHITE << "Pairs vector: 		" << _pairsVector << RESET << " (vector into pairs whose second element is the biggest)");
	LOG(YELLOW << "-- Merge sort --" << RESET);
	_pairsVector = mergeSortPairsVector(_pairsVector);
	LOG(WHITE << "Sorted pairs vector: 	" << _pairsVector << RESET << " (pairs sorted by their second element with a merge sort)");
	LOG(YELLOW << "-- Insertion sort --" << RESET);
	insertSortVector();
	LOG(WHITE << "Sorted vector: 		" << _vector << RESET);
	if (isVectorSorted() == false)
		std::cout << RED << "Error: vector is not sorted" << RESET << std::endl;
	else
		std::cout << GREEN << "Vector is sorted !" << RESET << std::endl;
	return ;
}

std::ostream  &operator<<(std::ostream &os, t_vector &vector)
{
	t_vector::iterator	it = vector.begin();
	
	int i = 0;
 	for (; it != vector.end(); ++it)
	{
		os << *it;
		if (it != --vector.end())
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

std::ostream  &operator<<(std::ostream &os, t_pairsVector &vector)
{
	t_pairsVector::iterator	it = vector.begin();
	int i = 0;
 	for (it = vector.begin(); it != vector.end(); ++it)
	{
		os << WHITE  << "[ " << CYAN << it->first << " " << MAGENTA << it->second << WHITE << " ]" << RESET;
		if (it != --vector.end())
			os << " ";
		if (i++ > 10)
		{
			os << "[...]";
			break ;
		}
	}
	return os;
}
