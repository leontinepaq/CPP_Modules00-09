/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:43:46 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/30 21:20:29 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>


class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
		void		drawTree(std::ofstream &os) const;
		void		executeAction(void) const;
		
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();
		std::string	getTarget(void) const;
};

#endif
