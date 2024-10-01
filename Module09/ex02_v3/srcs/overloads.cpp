/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overloads.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:42:32 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/30 19:36:01 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeTer.hpp"

bool operator<(const t_vector &a, const t_vector &b)
{
	return a.back() < b.back();
}

bool operator>(const t_vector &a, const t_vector &b)
{
	return a.back() > b.back();
}


std::ostream  &operator<<(std::ostream &os, std::vector<size_t> vect)
{
	std::vector<size_t>::iterator	it = vect.begin();
	
 	for (it = vect.begin(); it != vect.end(); ++it)
	{
		os << *it;
		if (it != --vect.end())
			os << " ";
	}
	return os;
}

std::ostream  &operator<<(std::ostream &os, t_vector &vector)
{
	t_vector::iterator	it = vector.begin();
	
	int i = 0;
 	for (; it != vector.end(); ++it)
	{
		os << *it;
		if (it != --vector.end())
			os << " ";
		if (i++ > 20)
		{
			os << "[...]";
			break ;
		}
		os << " ";
	}
	return os;
}



std::ostream  &operator<<(std::ostream &os, t_list &list)
{
	t_list::iterator	it = list.begin();
	
	int i = 0;
 	for (; it != list.end(); ++it)
	{
		os << *it;
		if (it != --list.end())
			os << " ";
		if (i++ > 20)
		{
			os << "[...]";
			break ;
		}
		os << " ";
	}
	return os;
}

std::ostream  &operator<<(std::ostream &os, t_pairsList &list)
{
	t_pairsList::iterator	it = list.begin();
	int i = 0;
 	for (it = list.begin(); it != list.end(); ++it)
	{
		os << WHITE  << "[ " << CYAN << it->first << " " << MAGENTA << it->second << WHITE << " ]" << RESET;
		if (it != --list.end())
			os << " ";
		if (i++ > 10)
		{
			os << "[...]";
			break ;
		}
	}
	return os;
}
