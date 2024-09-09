/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:18:42 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/09 17:49:39 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template< typename T >
void	iter(T *array, std::size_t length, void (*function)(T &))
{
	for (std::size_t i = 0; i < length; i++)
		function(array[i]);
}

#endif
