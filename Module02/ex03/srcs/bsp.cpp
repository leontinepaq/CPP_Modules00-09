/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:26:55 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/02 17:18:35 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

struct bspNode
{
	std::string	leaf;
	bspNode		*inside;
	bspNode		*outside;
};

static bool areAligned(Point const a, Point const b, Point const c)
{
	Fixed	coeffAB = (b.getY() - a.getY()) / (b.getX() - a.getX());
	Fixed	coeffAC = (c.getY() - a.getY()) / (c.getX() - a.getX());
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

bspNode MakeBspTree(Point const a, Point const b, Point const c)
{
	bspNode	node;
	
	node.front = NULL;
	node.back = NULL;
	return node;	
}

bool isInside(bspNode root, Point const point)
{
	(void)root;
	(void)point;
	return false;
}

bool 	bsp(Point const a, Point const b, Point const c, Point const point)
{
	bspNode	root;
	
	if (checkTriangle(a, b, c) == false)
		return false;
	root = MakeBspTree(a, b, c);
	return isInside(root, point);
}
