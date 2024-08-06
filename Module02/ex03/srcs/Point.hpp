/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:27:02 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/06 20:27:51 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private :
		Fixed const x;
		Fixed const y;
	
	public :
		Point();
		Point(const float x, const float y);
		Point(const Point &src);
		Point &operator=(const Point &src);
		~Point();
		bool operator==(const Point &src) const;
		Fixed const getX() const;
		Fixed const getY() const;
};

std::ostream &operator<<(std::ostream &os, const Point &src);


#endif