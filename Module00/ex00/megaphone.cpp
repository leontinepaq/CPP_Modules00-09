/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:39:10 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/11 14:45:06 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <cctype>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (EXIT_SUCCESS);
	}
	for (int i = 1; i < ac; i++)
		for (int j = 0; av[i][j]; j++)
			std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(av[i][j])));
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}

			// std::cout << (char)toupper(av[i][j]);