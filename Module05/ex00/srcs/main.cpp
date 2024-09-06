/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 22:56:05 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/06 17:55:30 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define MAIN_NB 1

#if MAIN_NB == 0
void	followBureaucratCareer(std::string name, int initGrade)
{
	try
	{
		Bureaucrat bureaucrat(name, initGrade);
		std::cout << GREEN "Bureaucrat " << bureaucrat.getName()
			<< " created with grade " << bureaucrat.getGrade() << RESET << std::endl;
		std::string answer;
		while (1)
		{
			std ::cout << CYAN "Status: " << bureaucrat << RESET << std::endl;
			
			std::cout << "> What do you want to do with this bureaucrat?"
				" (i: increment grade, d: decrement grade, e: end career): ";
			std::getline(std::cin, answer);
			if (answer == "i")
				bureaucrat.incrementGrade();
			else if (answer == "d")
				bureaucrat.decrementGrade();
			else if (answer == "e")
				return ;
		}		
	}
	catch (std::exception & e)
	{
		std::cerr << RED "Exception catched: " << e.what() << RESET << std::endl;
	}
}

int	main(void)
{
	std::cout << YELLOW "Welcome to the Bureaucrat career simulator!" RESET << std::endl;
	while (1)
	{
		std::string name;
		int grade;
		std::string answer;

		std::cout << YELLOW "Let's create a new bureaucrat!" RESET << std::endl;
		std::cout << "> Enter a name: ";
		std::getline(std::cin, name);
		std::cout << "> Enter a grade: ";
		std::cin >> grade;
		std::cin.ignore();
		followBureaucratCareer(name, grade);
		std::cout << std::endl << "> Do you want to create another bureaucrat? (y/n): ";
		std::getline(std::cin, answer);
		if (answer != "y")
			break;
		std::cout << std::endl;
	}
	std::cout << YELLOW "Goodbye!" RESET << std::endl;
	
	return 0;
}
#endif

#if MAIN_NB == 1
int main(void)
{
	try
	{
		std::string name = "John";
		int grade = 42; //try with 0, 1, 150, 151
		std::cout << YELLOW "Create a new bureaucrat:" RESET << std::endl;
		std::cout << WHITE "Name : " << name << std::endl
			<<"Grade : " << grade << RESET << std::endl;
		Bureaucrat bureaucrat(name, grade);
		std::cout << WHITE "Status: " << bureaucrat << RESET << std::endl;
		std::cout << std::endl;

		std::cout << YELLOW "Increment the grade:" RESET << std::endl;
		bureaucrat.incrementGrade();
		std::cout << WHITE "Status: " << bureaucrat << RESET << std::endl;
		std::cout << std::endl;
		
		std::cout << YELLOW "Decrement the grade:" RESET << std::endl;
		bureaucrat.decrementGrade();
		std::cout << WHITE "Status: " << bureaucrat << RESET << std::endl;
		std::cout << std::endl;
		
		std::cout << YELLOW "Decrement the grade again:" RESET << std::endl;
		bureaucrat.decrementGrade();
		std::cout << WHITE "Status: " << bureaucrat << RESET << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << RED "Exception catched: " << e.what() << RESET << std::endl;
	}
	return 0;
}
#endif
