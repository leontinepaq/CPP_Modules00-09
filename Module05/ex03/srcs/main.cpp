/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 22:56:05 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/30 22:39:59 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.cpp"

int	main(void)
{
	AForm	*forms[4];

	std::cout << YELLOW "CREATE ONE INTERN" RESET << std::endl;
	Intern	someRandomIntern;
	std::cout << std::endl;
	
	std::cout << YELLOW "THE INTERN CREATES A SHRUBBERY FORM" RESET << std::endl;
	forms[0] = someRandomIntern.makeForm("shrubbery creation", "home");
	std::cout << std::endl;

	std::cout << YELLOW "THE INTERN CREATES A ROBOTOMY FORM" RESET << std::endl;
	forms[1] = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << std::endl;

	std::cout << YELLOW "THE INTERN CREATES A PRESIDENTIAL PARDON FORM" RESET << std::endl;
	forms[2] = someRandomIntern.makeForm("presidential pardon", "Dark Vador");
	std::cout << std::endl;
	
	std::cout << YELLOW "THE INTERN TRIES TO CREATE AN UNKNOWN FORM" RESET << std::endl;
	forms[3] = someRandomIntern.makeForm("unknown form", "unknown target");
	std::cout << std::endl;

	std::cout << YELLOW "DELETE THE FORMS" RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (forms[i])
			delete forms[i];
	}
	std::cout << std::endl;
	
	std::cout << YELLOW "END OF THE PROGRAM" RESET << std::endl;
}
