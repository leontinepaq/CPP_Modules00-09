/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 22:56:05 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/30 21:24:08 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define MAIN_NB 0


#if MAIN_NB == 0
int	main(void)
{
	std::cout << YELLOW "CREATE THREE FORMS" RESET << std::endl;
	ShrubberyCreationForm	shrubberyForm("Hogwards");
	RobotomyRequestForm		robotomyForm("Dudley Dursley");
	PresidentialPardonForm	presidentialForm("Sirius Black");
	std::cout << std::endl;

	std::cout << YELLOW "CREATE TWO BUREAUCRATS" RESET << std::endl;
	Bureaucrat	boss("Albus", 1);
	Bureaucrat	executant("Severus", 50);
	std ::cout << YELLOW "First bureaucrat: " << boss << RESET;
	std ::cout << YELLOW "Second bureaucrat: " << executant << RESET;
	std::cout << std::endl;

	std::cout << YELLOW "FIRST FORM - SHRUBBERY" RESET << std::endl;
	std ::cout << shrubberyForm;
	executant.signForm(shrubberyForm);
	executant.executeForm(shrubberyForm);
	std::cout << std::endl;

	std::cout << YELLOW "SECOND FORM - ROBOTOMY" RESET << std::endl;
	std ::cout << robotomyForm;
	executant.signForm(robotomyForm);
	executant.executeForm(robotomyForm);
	std::cout << std::endl;
	boss.executeForm(robotomyForm);
	std::cout << std::endl;

	std::cout << YELLOW "THIRD FORM - PRESIDENTIAL PARDON" RESET << std::endl;
	std ::cout << presidentialForm;
	boss.executeForm(presidentialForm);
	boss.signForm(presidentialForm);
	boss.executeForm(presidentialForm);
	std::cout << std::endl;

	std::cout << YELLOW "END OF THE PROGRAM" RESET << std::endl;
}
#endif

#if MAIN_NB == 1
int	main(void)
{
	std::cout << YELLOW "CREATE ONE BUREAUCRAT" RESET << std::endl;
	Bureaucrat	boss("Albus", 1);
	std ::cout << YELLOW "Bureaucrat: " << boss << RESET;
	std::cout << std::endl;

	std::cout << YELLOW "CREATE AND SIGN TWO FORMS" RESET << std::endl;
	ShrubberyCreationForm	shrubberyForm("Hogwards");
	RobotomyRequestForm		robotomyForm("Dudley Dursley");
	boss.signForm(shrubberyForm);
	boss.signForm(robotomyForm);
	std::cout << std::endl;

	std::cout << YELLOW "PLANT PLENTY OF TREES" RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << YELLOW "- Tree " << i + 1 << RESET << std::endl;
		boss.executeForm(shrubberyForm);
	}
	std::cout << std::endl;

	std::cout << YELLOW "TRY TO ROBOTOMIZE MULTIPLE TIMES" RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << YELLOW "- Robotomization " << i + 1 << RESET << std::endl;
		boss.executeForm(robotomyForm);
	}
	std::cout << std::endl;

	std::cout << YELLOW "END OF THE PROGRAM" RESET << std::endl;
}
#endif
