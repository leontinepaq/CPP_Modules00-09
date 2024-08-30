/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 21:46:03 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/30 23:09:13 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm* makeShrubberyCreationForm(std::string target) const;
		AForm* makeRobotomyRequestForm(std::string target) const;
		AForm* makePresidentialPardonForm(std::string target) const;

	public:
		Intern();
		Intern(const Intern &src);
		Intern& operator=(const Intern &src);
		~Intern();
		AForm	*makeForm(std::string formName, std::string target) const;
		class FormNotFoundException: public std::exception
		{
			virtual const char* what() const throw();
		};
};

#endif
