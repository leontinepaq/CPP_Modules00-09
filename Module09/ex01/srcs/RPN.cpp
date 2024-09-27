/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:27:52 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/27 12:03:29 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

RPN::RPN() : _expr("")
{
	// std::cout << "[RPN] Default constructor called" << std::endl;
}

RPN::RPN(std::string expr): _expr(expr)
{
	// std::cout << "[RPN] Parameric constructor called" << std::endl;
}

RPN::RPN(const RPN &src): _exprStack(src._exprStack), _expr(src._expr)
{
	// std::cout << "[RPN] Copy constructor called" << std::endl;
}

RPN& RPN::operator=(const RPN &src)
{
	// std::cout << "[RPN] Assignment operator called" << std::endl;
	_expr = src._expr;
	_exprStack = src._exprStack;
	return *this;
}

RPN::~RPN()
{
	// std::cout << "[RPN] Destructor called" << std::endl;
}

void	RPN::checkOperation(std::string &operation)
{
	if (operation.length() != 1)
		throw (invalidInputException());
	unsigned char c = operation[0];
	if (!std::isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/')
		throw invalidInputException();
}

float	RPN::calculate(float operand1, float operand2, char op)
{
	double	res;
	
	if (op == '+')
		res = operand1 + operand2;
	else if (op == '-')
		res = operand1 - operand2;
	else if (op == '*')
		res = operand1 * operand2;
	if (op == '/')
	{
		if (operand2 == 0)
			throw (impossibleToExecuteException());
		res = operand1 / operand2;
	}
	if (res > std::numeric_limits<float>::max() 
		|| res < -std::numeric_limits<float>::max()
		)
		throw (impossibleToExecuteException());

	return static_cast<float>(res);
}

void	RPN::executeOperation(unsigned char op)
{
	if (_exprStack.size() < 2)
		throw (impossibleToExecuteException());

	float	operand2 = _exprStack.top();
	_exprStack.pop();
	float	operand1 = _exprStack.top();
	_exprStack.pop();
	_exprStack.push(calculate(operand1, operand2, op));
}

void	RPN::executeRPN(void)
{
	if (_expr.empty())
		return ;
	while (!_exprStack.empty())
		_exprStack.pop();
	std::istringstream	exprStream(_expr);
	std::string	operation;
	while (getline(exprStream, operation, ' '))
	{
		checkOperation(operation);
		unsigned char c = operation[0];
		if (std::isdigit(c))
			_exprStack.push(c - '0');
		else
			executeOperation(c);
	}
	if (_exprStack.size() != 1)
		throw (impossibleToExecuteException());
	std::cout << _exprStack.top() << std::endl;
}

float	RPN::executeExpression(std::string expr)
{
	try
	{
		RPN	rpn(expr);
		rpn.executeRPN();
	}
	catch(const invalidInputException& e)
	{
		std::cerr << "Error: "<< e.what() << std::endl; 
	}
	catch(const impossibleToExecuteException& e)
	{
		std::cerr << "Error: "<< e.what() << std::endl; 
	}
	catch(const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}

const char* RPN::invalidInputException::what() const throw()
{
	return "Invalid input";
}

//float overflow, division by 0, not enough operands, not enough operators
const char* RPN::impossibleToExecuteException::what() const throw()
{
	return "Impossible to execute the expression";
}
