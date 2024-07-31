/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:12:37 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/29 14:37:30 by lpaquatt         ###   ########.fr       */
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
	public:
		Fixed();
		Fixed (int const value);
		Fixed (float const value);
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &src);
		friend std::ostream &operator<<(std::ostream &os, const Fixed &src);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

#endif