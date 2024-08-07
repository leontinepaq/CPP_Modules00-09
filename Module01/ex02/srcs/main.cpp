/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:25:15 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/07 13:39:59 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Address of the string:\t\t\t" << &str << std::endl;
	std::cout << "Address in the string pointer:\t\t" << stringPTR << std::endl;
	std::cout << "Address of the string reference:\t" << &stringREF << std::endl;
	std::cout << std::endl;
	
	std::cout << "Value of the string:\t\t\t" << str << std::endl;
	std::cout << "Value pointed by the string pointer:\t" << *stringPTR << std::endl;
	std::cout << "Value of the string reference:\t\t" << stringREF << std::endl;
	return (0);
}
