/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:20:34 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/19 19:17:35 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static int	getLevel(std::string level)
{
	std::string levels_str[NB_LEVELS] = LEVELS;
	
	for (int i = 0; i < NB_LEVELS; i++)
		if (level == levels_str[i])
			return (i);
	return (-1);
}


int main(int ac, char **av)
{
	Harl		harl;
	std::string levels[NB_LEVELS] = LEVELS;
	int			level;
	
	if (ac != 2)
	{
		std::cout << "Usage: ./HarlFilter [DEBUG/INFO/WARNING/ERROR]" << std::endl;
		return (1);
	}
	level = getLevel(av[1]);
	switch (level)
	{
		case (-1):
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		default:
			harl.complain(levels[level]);
			break;
	}
	return (0);
}
