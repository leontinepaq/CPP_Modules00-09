/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:12:37 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/07 12:04:42 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed 
{
	private:
		int value;
		static const int nb_bits = 8;
		int getRawBits(void) const;
		void setRawBits(int const raw);

	public:
		Fixed();
		Fixed (int const value);
		Fixed (float const value);
		Fixed(const Fixed &src);
		~Fixed();
		Fixed	&operator=(const Fixed &src);
		float	toFloat( void ) const;
		int		toInt( void ) const;
		void	printBits(void) const;

};

std::ostream &operator<<(std::ostream &os, const Fixed &src);

#endif