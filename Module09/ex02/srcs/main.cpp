/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:55:42 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/25 13:36:35 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: wrong number of arguments" << std::endl;
		return 1;
	}
	if (PmergeMe::sort(av + 1))
		return 1;
	return 0;
}
