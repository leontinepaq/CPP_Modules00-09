/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:33:42 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/03 17:57:27 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <limits>

# define BLUE		"\033[1;34m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define CYAN		"\033[1;36m"
# define MAGENTA	"\033[1;35m"
# define YELLOW		"\033[1;33m"
# define GREY		"\033[1;30m"
# define WHITE		"\033[1;37m"
# define ORANGE		"\033[1;38;5;208m"
# define PURPLE		"\033[1;38;5;129m"
# define RESET		"\033[0m"


class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(std::string input);
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter& operator=(const ScalarConverter &src);
		~ScalarConverter();
		double		_value;
		bool		_isPseudoLiteral;
		std::string	_input;
		bool	checkInput(std::string input);
		void	printValue() const;
		void	inputToDouble();
		
		
	public:
		static void convert(const char *input);
		
};

#endif
