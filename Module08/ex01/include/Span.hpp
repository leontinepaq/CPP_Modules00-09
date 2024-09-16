/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:34:19 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/16 18:47:01 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span 
{
	public:
		Span();
		Span(unsigned int maxValues);
		Span(const Span &src);
		Span& operator=(const Span &src);
		~Span();
		void	addNumber(int number);
		int		shortestSpan();
		int		longuestSpan();

	private:
		std::vector<int>	_numbers;
		unsigned int		_maxValues;
		unsigned int	getLengthNumber();
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
