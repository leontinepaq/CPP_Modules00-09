/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:16:59 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/19 17:28:06 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <limits>
#include <stack>
#include <string>
#include <sstream>

class RPN
{
	private:
		RPN();
		RPN(std::string expression);
		RPN(const RPN &src);
		RPN& operator=(const RPN &src);
		~RPN();
		std::stack<int>		_exprStack;
		std::string			_expr;
		void	checkOperation(std::string &operation);
		int		calculate(int operand1, int operand2, char op);
		void	executeOperation(unsigned char op);
		void	executeRPN(void);
		class invalidInputException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class impossibleToExecuteException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	public:
		static int	executeExpression(std::string);
};

#endif
