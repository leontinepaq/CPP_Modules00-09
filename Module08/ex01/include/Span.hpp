/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:34:19 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/17 17:36:38 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <set>
#include <iterator>
#include <cmath>

class Span 
{
	public:
		Span();
		Span(unsigned int maxValues);
		Span(const Span &src);
		Span& operator=(const Span &src);
		~Span();
		void	addNumber(int number);
		void	addNumber(std::multiset<int>::iterator begin, std::multiset<int>::iterator end);
		void	printNumbers();
		int		shortestSpan();
		int		longuestSpan();

	private:
		std::multiset<int>	_numbers;
		unsigned int		_maxValues;
		class TooManyNumbersException: public std::exception
		{
			virtual const char* what() const throw();
		};
		class NotEnoughNumbersException: public std::exception
		{
			virtual const char* what() const throw();
		};
};

#endif
