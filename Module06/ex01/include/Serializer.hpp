/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:49:35 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/06 16:24:12 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"
#include <iostream>
#include <stdint.h>

# ifndef COLORS
#  define BLUE		"\033[1;34m"
#  define RED		"\033[1;31m"
#  define GREEN		"\033[1;32m"
#  define CYAN		"\033[1;36m"
#  define MAGENTA	"\033[1;35m"
#  define YELLOW	"\033[1;33m"
#  define GREY		"\033[1;30m"
#  define WHITE		"\033[1;37m"
#  define ORANGE	"\033[1;38;5;208m"
#  define PURPLE	"\033[1;38;5;129m"
#  define RESET		"\033[0m"
# endif


class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &src);
		Serializer& operator=(const Serializer &src);
		~Serializer();
		
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
