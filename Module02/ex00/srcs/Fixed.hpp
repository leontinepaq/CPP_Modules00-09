/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:12:37 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/07 15:29:00 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed 
{
	private:
		int				 _value;
		static const int _nb_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &src);
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		void	printBits(void);

};

#endif