/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp_without_bsp.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:29:54 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/06 23:19:11 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static bool areAligned(Point const a, Point const b, Point const c)
{
	Fixed	coeffAB;
	Fixed	coeffAC;

	if (a.getX() != b.getX())
		coeffAB = (b.getY() - a.getY()) / (b.getX() - a.getX());
	else
		coeffAB = 0;
	if (a.getX() != c.getX())
		coeffAC = (c.getY() - a.getY()) / (c.getX() - a.getX());
	else
		coeffAC = 0;
	return (coeffAB == coeffAC);
}

static bool checkTriangle(Point const a, Point const b, Point const c)
{
	if (a == b || a == c || b == c)
	{
		std::cout << std::endl << "bsp: A triangle should be composed of 3 distinct points" << std::endl;
		return false;
	}
	if (areAligned(a, b, c) == true)
	{
		std::cout <<  std::endl << "bsp: Corners of a triangle should not be aligned" << std::endl;
		return false;
	}
	return true;
}

static Fixed	getDet(Point const a, Point const b, Point const point)
{
	return 
			(b.getX() - a.getX()) * (point.getY() - a.getY()) 
		- 	(b.getY() - a.getY()) * (point.getX() - a.getX());
}

static bool	isInside(Point const a, Point const b, Point const c, Point const point)
{
	Fixed detABP = getDet(a, b, point);
	Fixed detBCP = getDet(b, c, point);
	Fixed detCAP = getDet(c, a, point);

	 return (detABP < 0 && detBCP < 0 && detCAP < 0) 
	 	|| (detABP > 0 && detBCP > 0 && detCAP > 0);
}

bool 	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (checkTriangle(a, b, c) == false)
		return false;
	return isInside(a, b, c, point);
}
