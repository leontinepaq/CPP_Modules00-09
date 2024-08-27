/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp_without_bsp.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:29:54 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/26 22:33:06 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#define EXPLAINED 0

#if EXPLAINED == 1
static Fixed	getDet(Point const a, Point const b, Point const point)
{
	return 
			(b.getX() - a.getX()) * (point.getY() - a.getY()) 
		- 	(b.getY() - a.getY()) * (point.getX() - a.getX());
}

static bool	isInside(Point const a, Point const b, Point const c, Point const point)
{
	bool res;

	std::cout << "Are c and the point on the same side of the line ab?" << std::endl;
	std::cout << "getDet(a, b, point) = " << getDet(a, b, point) << std::endl;
	std::cout << "getDet(a, b, c) = " << getDet(a, b, c) << std::endl;
	res = getDet(a, b, point) * getDet(a, b, c) > 0;
	if (res == false)
	{
		std::cout << "> No, the point is not on the same side of the line ab as c" << std::endl << std::endl;
		return false;
	}
	std::cout << "> Yes, the point is on the same side of the line ab as c" << std::endl << std::endl;

	std::cout << "Are b and the point on the same side of the line ac?" << std::endl;
	std::cout << "getDet(a, c, point) = " << getDet(a, c, point) << std::endl;
	std::cout << "getDet(a, c, b) = " << getDet(a, c, b) << std::endl;
	res = getDet(a, c, point) * getDet(a, c, b) > 0;
	if (res == false)
	{
		std::cout << "> No, the point is not on the same side of the line ac as b" << std::endl << std::endl;
		return false;
	}
	std::cout << "> Yes, the point is on the same side of the line ac as b" << std::endl << std::endl;

	std::cout << "Are a and the point on the same side of the line bc?" << std::endl;
	std::cout << "getDet(b, c, point) = " << getDet(b, c, point) << std::endl;
	std::cout << "getDet(b, c, a) = " << getDet(b, c, a) << std::endl;
	res = getDet(b, c, point) * getDet(b, c, a) > 0;
	if (res == false)
	{
		std::cout << "> No, the point is not on the same side of the line bc as a" << std::endl << std::endl;
		return false;
	}
	std::cout << "> Yes, the point is on the same side of the line bc as a" << std::endl << std::endl;
	return true;
}
#endif

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
		// std::cout << std::endl << "bsp: A triangle should be composed of 3 distinct points" << std::endl;
		return false;
	}
	if (areAligned(a, b, c) == true)
	{
		// std::cout <<  std::endl << "bsp: Corners of a triangle should not be aligned" << std::endl;
		return false;
	}
	return true;
}

#if EXPLAINED == 0

static Fixed	getDet(Point const a, Point const b, Point const point)
{
	return 
			(b.getX() - a.getX()) * (point.getY() - a.getY()) 
		- 	(b.getY() - a.getY()) * (point.getX() - a.getX());
}


static bool	isInside(Point const a, Point const b, Point const c, Point const point)
{
	return
		getDet(a, b, point) * getDet(a, b, c) > 0
		&& getDet(a, c, point) * getDet(a, c, b) > 0
		&& getDet(b, c, point) * getDet(b, c, a) > 0;
}
#endif


bool 	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (checkTriangle(a, b, c) == false)
		return false;
	return isInside(a, b, c, point);
}
