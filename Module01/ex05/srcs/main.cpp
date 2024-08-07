/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:20:34 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/07 14:51:22 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#define BOLD	"\033[1m"
#define RESET	"\033[0m"

int main(void)
{
	Harl harl;

	std::cout << BOLD << "Harl complains : 'DEBUG'" << RESET << std::endl;
	std::cout << "> ";
	harl.complain("DEBUG");
	std::cout << std::endl;
	
	std::cout << BOLD << "Harl complains : 'INFO'" << RESET << std::endl;
	std::cout << "> ";
	harl.complain("INFO");
	std::cout << std::endl;

	std::cout << BOLD << "Harl complains : 'WARNING'" << RESET << std::endl;
	std::cout << "> ";
	harl.complain("WARNING");
	std::cout << std::endl;

	std::cout << BOLD << "Harl complains : 'ERROR'" << RESET << std::endl;
	std::cout << "> ";
	harl.complain("ERROR");
	std::cout << std::endl;

	std::cout << BOLD << "Harl complains : 'BAD_LEVEL'" << RESET << std::endl;
	std::cout << "> ";
	harl.complain("BAD_LEVEL");
	std::cout << std::endl;
	
	std::cout << BOLD << "Harl complains : ''" << RESET << std::endl;
	std::cout << "> ";
	harl.complain("");
	std::cout << std::endl;
	
	return (0);
}
