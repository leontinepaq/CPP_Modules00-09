/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:49:05 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/20 17:28:21 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME
# define PMERGEME

#include <iostream>
#include <sstream>
#include <vector>
#include <list>

class PmergeMe
{
	private:
		PmergeMe();
		// PmergeMe(const PmergeMe &src);
		// PmergeMe& operator=(const PmergeMe &src);
		~PmergeMe();
		std::vector<unsigned int>	_vector;
		std::list<unsigned int>		_list;
		int		insertElements(char ** elements);
		bool	isListSorted(void);
		std::list<unsigned int> merge(std::list<unsigned int> listA, std::list<unsigned int> listB);
		std::list<unsigned int>	mergeSortList(std::list<unsigned int> list);
		int		sortList(void);
		
	public:
		static int	sort(char **elements, size_t size);
};

#endif
