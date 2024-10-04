/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:34:19 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/10/04 14:49:43 by lpaquatt         ###   ########.fr       */
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
		template <typename it>
		void	addNumber(it begin, it end);
		void	printNumbers();
		int		shortestSpan();
		int		longestSpan();

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

template <typename it>
void	Span::addNumber(it begin, it end)
{
	if (_numbers.size() + std::distance(begin, end) > _maxValues)
		throw(TooManyNumbersException());
	_numbers.insert(begin, end);
}

#endif
