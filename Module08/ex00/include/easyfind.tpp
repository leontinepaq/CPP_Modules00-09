/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:46:31 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/16 15:57:03 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

class NotFoundException: public std::exception
{
	virtual const char* what() const throw()
	{
		return "Value not found in the container";
	}
};

template < typename T > typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), value);
	if (it != container.end())
			return it;
	throw (NotFoundException());
}
