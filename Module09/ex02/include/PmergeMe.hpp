/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:49:05 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/25 00:16:03 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME
# define PMERGEME

# define COMMENTS_ON 0

#include "Colors.hpp"


#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <cmath>
#include <ctime>

typedef unsigned int t_unsInt;
typedef std::list <t_unsInt> t_list;
typedef std::pair <t_unsInt, t_unsInt> t_pair;
typedef std::list <std::pair <t_unsInt, t_unsInt> > t_pairsList;


class PmergeMe
{
	private:
		PmergeMe();
		// PmergeMe(const PmergeMe &src);
		// PmergeMe& operator=(const PmergeMe &src);
		~PmergeMe();
		std::vector<t_unsInt>		_vector;
		t_list		_list;
		t_pairsList	_pairsList;
		size_t		_nbElements;
		t_unsInt	_lastElement;
		int			insertElements(char ** elements);
		bool		isListSorted(void);
		void		fillPairsList(void);
		int			sortList(void);
		t_pairsList merge(t_pairsList listA, t_pairsList listB);
		t_pairsList	mergeSortPairsList(t_pairsList &list);
		void		binaryInsertList(t_unsInt element, size_t size);
		void		insertSortList(void);
		
	public:
		static int	sort(char **elements, size_t size);
};

void	generateJacobsthalSequence(std::vector<size_t> &vect, size_t size);


#endif
