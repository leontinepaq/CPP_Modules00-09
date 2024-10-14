/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeTer.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:49:05 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/10/14 13:56:55 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME
# define PMERGEME

# define COMMENTS_ON 1
# if COMMENTS_ON
    # define LOG(x) std::cout << x << RESET << std::endl
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

typedef std::list <unsigned int> t_list;
typedef std::vector <unsigned int> t_vector;

typedef struct	s_trackingL 
{
	t_list		l;
	t_list		rec;
	t_list		combined;
} 	t_trackingL;

typedef struct	s_tracking 
{
	t_vector	v;
	t_vector	rec;
	t_vector	combined;
} 	t_tracking;

class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe& operator=(const PmergeMe &src);
		~PmergeMe();

		t_vector 		fusionInsertSort(t_vector &vector, unsigned int level);
		t_list			fusionInsertSort(t_list &list, unsigned int level);
	public:
		static int		sort(t_vector &vector);
		static int		sort(t_list &list);
		static bool		isVectorSorted(t_vector &vector);
		static bool		isListSorted(t_list &list);

};

void	generateJacobsthalSequence(t_vector &vect, size_t size);

std::ostream  &operator<<(std::ostream &os, t_list &list);
std::ostream  &operator<<(std::ostream &os, t_vector &vector);
bool operator>(const t_vector &a, const t_vector &b);
bool operator<(const t_vector &a, const t_vector &b);


#endif
