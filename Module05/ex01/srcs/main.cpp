/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 22:56:05 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/06 18:09:40 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main(void)
{
	try {
		std::cout << YELLOW "Create a bureaucrat and two forms" RESET << std::endl;
		Bureaucrat	bureaucrat("Michelle Obama", 16);
		Form		form("Form 1", 15, 20);
		Form		form2("Form 2", 100, 100);
		// Form		WrongForm("Wrong form", 0, 100);
		std::cout << std::endl;

		std::cout << YELLOW "Bureaucrat created:" RESET << std::endl;
		std::cout << bureaucrat << std::endl;
		
		std::cout << YELLOW "Forms created:" RESET << std::endl;	
		std::cout << form << std::endl;
		std::cout << form2 << std::endl << std::endl;

		std::cout << YELLOW "Bureaucrat tries to sign forms" RESET << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.signForm(form2);
		std::cout << std::endl;
		std::cout << form << std::endl;
		std::cout << form2 << std::endl << std::endl;

		std::cout << YELLOW "Bureaucrat tries to execute forms" RESET << std::endl;
		bureaucrat.executeForm(form);
		bureaucrat.executeForm(form2);
		std::cout << std::endl;

		std::cout << YELLOW "New bureaucrat tries to execute forms" RESET << std::endl;
		Bureaucrat	bureaucrat2("Jean Castex", 150);
		std::cout << bureaucrat2;
		bureaucrat2.executeForm(form);
		bureaucrat2.executeForm(form2);
		std::cout << std::endl;
		
		std::cout << YELLOW "First bureaucrat tries to sign forms after being promoted" RESET << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat;
		bureaucrat.signForm(form);
		bureaucrat.signForm(form2);
		std::cout << std::endl;
		std::cout << form << std::endl;
		std::cout << form2 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << RED "Exception catched: " << e.what() << RESET << std::endl;
	}
	return 0;
}