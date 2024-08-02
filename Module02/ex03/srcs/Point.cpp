/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:26:59 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/02 14:22:29 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point::Point(const Point &src) : x(src.x), y(src.y)
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
	return (this->getX() == src.getX() && this->getY() == src.getY());
}

Fixed const Point::getX() const
{
	return this->x;
}

Fixed const Point::getY() const
{
	return this->y;
}

std::ostream &operator<<(std::ostream &os, const Point &src)
{
	os << "Point(" << src.getX() << ", " << src.getY() << ")";
	return os;
}
