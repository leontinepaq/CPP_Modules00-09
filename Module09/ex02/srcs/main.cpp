/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:55:42 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/27 16:13:48 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static int putError(std::string mess)
{
	std::cerr << "Error: " << mess << std::endl;
	return 1;
}

int	parseElements(char ** elements, size_t size, std::vector<unsigned int> &vector)
{
	if (!elements || !elements[0])
		return putError("no element to sort");
	size_t i = 0;
	vector.clear();
	vector.reserve(size);
	while (elements[i] && i < size)
	{
		std::stringstream	ss(elements[i]);
		unsigned int			value;
		ss >> std::noskipws >> value;
		if (ss.fail() || ss.peek() != std::stringstream::traits_type::eof())
			return putError("invalid element (all elements must be unsigned int)");
		vector.push_back(value);
		i++;
	}
	return 0;
}

int measureSortVector(double &duration, t_vector &elementsVect)
{
	std::clock_t start = std::clock();
	if (PmergeMe::sort(elementsVect))
		return 1;
	std::clock_t end = std::clock();
	duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	return 0;
}

int measureSortList(double &duration, t_list &elementsList)
{
	std::clock_t start = std::clock();
	if (PmergeMe::sort(elementsList))
		return 1;
	std::clock_t end = std::clock();
	duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	return 0;
}


int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << RED << "Error: wrong number of arguments" << RESET << std::endl;
		return 1;
	}
	
	std::vector<unsigned int> elementsVect;
	if (parseElements(av + 1, ac -1, elementsVect))
		return 1;
	std::list<unsigned int> elementsList(elementsVect.begin(), elementsVect.end());
	
	double durationVectSort;
	std::cout << MAGENTA << "Sorting " << elementsVect.size() << " elements" << RESET << std::endl;
	std::cout << MAGENTA << "> Sort vector using PmergeMe" << RESET << std::endl;
	std::cout << WHITE << "Before:\t" << BLUE << elementsVect << RESET << std::endl;
	if (measureSortVector(durationVectSort, elementsVect))
		return 1;
	std::cout << WHITE << "After:\t" << BLUE << elementsVect << RESET << std::endl;
	std::cout << WHITE << "Time to process a range of " << elementsVect.size() << " elements with std::vector: " << CYAN << durationVectSort << " ms." << RESET << std::endl;
	std::cout << std::endl;

	double durationListSort;
	std::cout << MAGENTA << "> Sort list using PmergeMe" << RESET << std::endl;
	std::cout << WHITE << "Before:\t" << BLUE << elementsList << RESET << std::endl;
	if (measureSortList(durationListSort, elementsList))
		return 1;	
	std::cout << WHITE << "After:\t" << BLUE << elementsList << RESET << std::endl;
	std::cout << WHITE << "Time to process a range of " << elementsVect.size() << " elements with std::list: " << CYAN << durationListSort << " ms." << RESET << std::endl;
	std::cout << std::endl;
	

	return 0;
}