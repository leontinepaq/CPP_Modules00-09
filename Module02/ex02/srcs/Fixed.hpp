/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:12:37 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/07 15:31:25 by lpaquatt         ###   ########.fr       */
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
		int					_value;
		static const int	_nb_bits = 8;

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		int 	floatToFixedValue(float value) const;
		
	public:
		Fixed();
		Fixed(int const value);
		Fixed(float const value);
		Fixed(const Fixed &src);
		~Fixed();
		float				toFloat(void) const;
		int					toInt(void) const;
		Fixed				&operator=(const Fixed &src);
		const Fixed			&operator++(void);
		const Fixed			operator++(int);
		const Fixed			&operator--(void);
		const Fixed			operator--(int);
		const Fixed			operator+(const Fixed &src) const;
		const Fixed			operator-(const Fixed &src) const;
		const Fixed			operator*(const Fixed &src) const;
		const Fixed			operator/(const Fixed &src) const;
		bool 				operator>(const Fixed &src) const;
		bool 				operator<(const Fixed &src) const;
		bool 				operator>=(const Fixed &src) const;
		bool 				operator<=(const Fixed &src) const;
		bool 				operator==(const Fixed &src) const;
		bool 				operator!=(const Fixed &src) const;
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
		void 				printBits(void);
};

std::ostream &operator<<(std::ostream &os, const Fixed &src);

#endif
 