/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:18:42 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/23 13:57:40 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template< typename T, typename F >
void	iter(T *array, std::size_t length, F *f)
{
	for (std::size_t i = 0; i < length; i++)
		f(array[i]);
}

#endif
