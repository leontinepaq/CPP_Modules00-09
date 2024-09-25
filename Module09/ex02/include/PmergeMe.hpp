/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:49:05 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/25 16:54:10 by lpaquatt         ###   ########.fr       */
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

typedef std::pair <unsigned int, unsigned int> t_pair;
typedef std::list <unsigned int> t_list;
typedef std::list <std::pair <unsigned int, unsigned int> > t_pairsList;
typedef std::vector <unsigned int> t_vector;
typedef std::vector <std::pair <unsigned int, unsigned int> > t_pairsVector;

class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe& operator=(const PmergeMe &src);
		~PmergeMe();
		size_t			_nbElements;
		unsigned int	_lastElement;
		t_vector		_vector;
		t_pairsVector	_pairsVector;
		t_list			_list;
		t_pairsList		_pairsList;
		int				insertElements(char ** elements);
			
		bool			isVectorSorted(void);
		void			fillPairsVector(void);
		t_pairsVector 	merge(const t_pairsVector &vectorA, const t_pairsVector &vectorB);
		t_pairsVector	mergeSortPairsVector(const t_pairsVector &vector);
		size_t			binarySearchVector(const t_vector &vector, unsigned int element, size_t low, size_t high);
		void			binaryInsertVector(unsigned int element, size_t size);
		void			insertSortVector(void);
		void			sortVector(void);

		bool			isListSorted(void);
		void			fillPairsList(void);
		t_pairsList 	merge(const t_pairsList &listA, const t_pairsList &listB);
		t_pairsList		mergeSortPairsList(const t_pairsList &list);
		size_t			binarySearchList(const t_list &list, unsigned int element, size_t low, size_t high);
		void			binaryInsertList(unsigned int element, size_t size);
		void			insertSortList(void);
		void			sortList(void);

	public:
		static int	sort(char **elements);
};

void	generateJacobsthalSequence(std::vector<size_t> &vect, size_t size);

std::ostream  &operator<<(std::ostream &os, t_list &list);
std::ostream  &operator<<(std::ostream &os, t_pairsList &list);
std::ostream  &operator<<(std::ostream &os, t_vector &vector);
std::ostream  &operator<<(std::ostream &os, t_pairsVector &vector);

#endif
