/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:49:05 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/25 03:33:27 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME
# define PMERGEME

# define COMMENTS_ON 0
# if COMMENTS_ON
    # define LOG(x) std::cout << x << std::endl
#  else
    #define LOG(x)
# endif

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
		t_pairsList merge(const t_pairsList listA, const t_pairsList listB);
		t_pairsList	mergeSortPairsList(const t_pairsList &list);
		size_t		binarySearchList(const t_list &list, t_unsInt element, size_t low, size_t high);
		void		binaryInsertList(t_unsInt element, size_t size);
		void		insertSortList(void);
		int			sortList(void);
		
	public:
		static int	sort(char **elements, size_t size);
};

void	generateJacobsthalSequence(std::vector<size_t> &vect, size_t size);

std::ostream  &operator<<(std::ostream &os, t_list &list);
std::ostream  &operator<<(std::ostream &os, t_pairsList &list);

#endif
