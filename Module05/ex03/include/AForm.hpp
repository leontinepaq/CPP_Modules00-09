/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 01:18:59 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/30 22:28:21 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		void				checkExecution(const Bureaucrat &executor) const;
		virtual void		executeAction(void) const = 0;

	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &src);
		AForm& operator=(const AForm &src);
		virtual ~AForm();
		const std::string	getName(void) const;
		bool				getSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		void				beSigned(const Bureaucrat &bureaucrat);
		void				execute(Bureaucrat const &executor) const;
		class FormAlreadySignedException: public std::exception
		{
			virtual const char* what() const throw();
		};
		class FormNotSignedException: public std::exception
		{
			virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &os, const AForm &src);

#endif
