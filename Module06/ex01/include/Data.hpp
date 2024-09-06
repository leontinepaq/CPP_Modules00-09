/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:08:47 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/06 16:20:30 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
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

class Data
{
	private:
		int _value;
		std::string _str;
		
	public:
		Data();
		Data(int value, std::string str);
		Data(const Data &src);
		Data& operator=(const Data &src);
		~Data();
		void setValue(int value);
		int getValue() const;
		void setStr(std::string str);
		std::string getStr() const;
};

#endif
