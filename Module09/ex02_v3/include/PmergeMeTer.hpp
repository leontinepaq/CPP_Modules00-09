/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeTer.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:49:05 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/10/01 17:19:16 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME
# define PMERGEME

# define COMMENTS_ON 1
# if COMMENTS_ON
    # define LOG(x) std::cout << x << std::endl
#  else
    #define LOG(x)
# endif

#include "Colors.hpp"

#include <algorithm> 
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <cmath>
#include <ctime>
#include <limits>


typedef std::pair <unsigned int, unsigned int> t_pair;
typedef std::list <unsigned int> t_list;
typedef std::list <std::pair <unsigned int, unsigned int> > t_pairsList;
typedef std::vector <unsigned int> t_vector;



class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(t_vector &vector);
		PmergeMe(t_list &list);
		PmergeMe(const PmergeMe &src);
		PmergeMe& operator=(const PmergeMe &src);
		~PmergeMe();
		size_t			_nbElements;
		unsigned int	_lastElement;
		void			sortList(t_list &list);
		t_vector 		fusionInsertSort(t_vector &vector, unsigned int level);

	public:
		static int		sort(t_vector &vector);
		static int		sort(t_list &list);
		static bool		isVectorSorted(t_vector &vector);
		static bool		isListSorted(t_list &list);

};

void	generateJacobsthalSequence(t_vector &vect, size_t size);

std::ostream  &operator<<(std::ostream &os, t_list &list);
std::ostream  &operator<<(std::ostream &os, t_pairsList &list);
std::ostream  &operator<<(std::ostream &os, t_vector &vector);
bool operator>(const t_vector &a, const t_vector &b);
bool operator<(const t_vector &a, const t_vector &b);


#endif
