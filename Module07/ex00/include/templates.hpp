/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:46:47 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/09 17:19:06 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

//similaire à la fonction std::swap
template< typename T >
void swap(T &a, T &b)
{
	T tmp(a);
	a = b;
	b = tmp;
}

//similaire à la fonction std::min
template< typename T >
T	min(T a, T b)
{
	return (!(b < a) ? a : b);
}

//similaire à la fonction std::max
template< typename T >
T	max(T a, T b)
{
	return ((a < b) ? b : a);
}

#endif
