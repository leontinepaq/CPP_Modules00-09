/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:20:34 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/07 15:27:16 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl		harl;
	
	if (ac != 2)
	{
		std::cout << "Usage: ./HarlFilter [DEBUG/INFO/WARNING/ERROR]" << std::endl;
		return (1);
	}
	harl.complain(av[1]);
	return (0);
}
