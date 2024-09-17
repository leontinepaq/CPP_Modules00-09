/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:30:12 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/17 23:10:34 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "Colors.hpp"
#include <iostream>

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>()
{
	std::cout << GREY << "[MutantStack] Constructor called" << RESET << std::endl;
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &src) : std::stack<T, Container>(src)
{
	std::cout << GREY << "[MutantStack] Copy constructor called" << RESET << std::endl;
}

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack &src)
{
	std::cout << GREY << "[MutantStack] Assignation operator called" << RESET << std::endl;
	std::stack<T, Container>::operator=(src);
	return (*this);
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
	std::cout << GREY << "[MutantStack] Destructor called" << RESET << std::endl;
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::begin()
{
	return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::end()
{
	return (this->c.end());
}
