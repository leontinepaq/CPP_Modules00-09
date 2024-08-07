/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:26:59 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/07 15:37:48 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(const Point &src) : _x(src._x), _y(src._y)
{
}

// affectation cannot be done on const Fixed
Point &Point::operator=(const Point &src)
{
	(void)src;
	return *this;
}

Point::~Point()
{
}

bool Point::operator==(const Point &src) const
{
	return (getX() == src.getX() && getY() == src.getY());
}

Fixed const Point::getX() const
{
	return _x;
}

Fixed const Point::getY() const
{
	return _y;
}

std::ostream &operator<<(std::ostream &os, const Point &src)
{
	os << "Point(" << src.getX() << ", " << src.getY() << ")";
	return os;
}
