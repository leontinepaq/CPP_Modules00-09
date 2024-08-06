/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:26:55 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/06 22:15:20 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#define EXPLAINED 0

#define BLUE "\033[1;34m"
#define LIGHT_BLUE "\033[1;36m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define WHITE "\033[1;37m"
#define RESET "\033[0m"

struct bspNode
{
	bool		isLeaf;
	bool		isInside;
	bspNode		*inside;
	bspNode		*outside;
	Point		*delimiter1;
	Point		*delimiter2;
	Point		*insidePoint;
};

static void printNewNode(Point *a, Point *b, Point *c)
{
	if (EXPLAINED == 0)
		return;
	std::cout << LIGHT_BLUE << "New node created : " << std::endl;
	std::cout << WHITE << "Parameters : " << std::endl;
	std::cout << " - delimiter1 : Point(" << a->getX() << ", " << a->getY() << ")" << std::endl;
	std::cout << " - delimiter2 : Point(" << b->getX() << ", " << b->getY() << ")" << std::endl;
	std::cout << " - insidePoint : Point(" << c->getX() << ", " << c->getY() << ")" << RESET << std::endl << std::endl;
}

static void printNewLeaf(bool isInside)
{
	if (EXPLAINED == 0)
		return ;
	std::cout << GREEN << "New leaf created : " << std::endl;
	std::cout << WHITE << "Parameters :" << std::endl << " - isInside : ";
	if (isInside == true)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	std::cout << RESET << std::endl;
}

void	printExplainEvaluation (Point const point)
{
	if (EXPLAINED == 0)
		return ;
	std::cout << BLUE << "Evaluating if point is inside the triangle : ";
	std::cout << WHITE << "Point : Point(" << point.getX() << ", " << point.getY() << ")" << std::endl;
	std::cout << RESET << std::endl;
}

static void	printIsInside(bspNode *root)
{
	static int i = 0;
	if (EXPLAINED == 0)
		return ;
	if (i == 0)
		printExplainEvaluation(*root->insidePoint);
	std::cout << BLUE << "Evaluating node " << i++ << " :" << std::endl;
	if (root->isLeaf == true)
	{
		std::cout << GREEN << "Leaf evaluated : " << std::endl;
		std::cout << WHITE << "Parameters : " << std::endl
			<< " - Is inside : ";
		if (root->isInside == true)
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;
		std::cout << RESET << std::endl;
		return ;
	}
	std::cout << LIGHT_BLUE << "Node evaluated : " << std::endl;
	std::cout << WHITE << "Parameters : " << std::endl;
	std::cout << " - Delimiter1 : Point(" << root->delimiter1->getX() << ", " << root->delimiter1->getY() << ")" << std::endl;
	std::cout << " - Delimiter2 : Point(" << root->delimiter2->getX() << ", " << root->delimiter2->getY() << ")" << std::endl;
	std::cout << " - InsidePoint : Point(" << root->insidePoint->getX() << ", " << root->insidePoint->getY() << ")" << RESET << std::endl;
	std::cout << std::endl;
};

static void printEvaluationRes(bool res)
{
	if (EXPLAINED == 0)
		return ;
	std::cout << BLUE << "Evaluation result : ";
	if (res == true)
		std::cout << YELLOW << "inside" << std::endl;
	else
		std::cout << RED << "outside" << std::endl;
	std::cout << RESET << std::endl;
}


// CHECK TRIANGLE
// check if points are aligned (not valid for a triangle)
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

//check if triangle is valid
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

// MAKE BSP TREE
// set the node parameters (delimiting line and inside point)
static void setNode(bspNode *node, Point *a, Point *b, Point *c)
{
	printNewNode(a, b, c);
	node->isLeaf = false;
	node->delimiter1 = a;
	node->delimiter2 = b;
	node->insidePoint = c;
}

// create the BSP tree of the triangle (3 nodes and 4 leaves)
static void makeBspTree(bspNode *root, Point *a, Point *b, Point *c)
{
	setNode(root, a, b, c);
	root->outside = new bspNode;
	root->outside->isLeaf = true;
	root->outside->isInside = false;
	printNewLeaf(false);
	
	root->inside = new bspNode;
	setNode(root->inside, a, c, b);
	
	root->inside->outside = new bspNode;
	root->inside->outside->isLeaf = true;
	root->inside->outside->isInside = false;
	printNewLeaf(false);

	root->inside->inside = new bspNode;
	setNode(root->inside->inside, b, c, a);
	
	root->inside->inside->outside = new bspNode;
	root->inside->inside->outside->isLeaf = true;
	root->inside->inside->outside->isInside = false;
	printNewLeaf(false);
	root->inside->inside->inside = new bspNode;
	root->inside->inside->inside->isLeaf = true;
	root->inside->inside->inside->isInside = true;
	printNewLeaf(true);
}

// DELETE TREE
// delete the tree
static void deleteTree(bspNode node)
{
	if (node.isLeaf == false)
	{
		deleteTree(*node.inside);
		deleteTree(*node.outside);
		delete node.inside;
		delete node.outside;
	}
}

// IS INSIDE
// returns which side of the line is the point
static Fixed	getDet(Point const a, Point const b, Point const point)
{
	return 
			(b.getX() - a.getX()) * (point.getY() - a.getY()) 
		- 	(b.getY() - a.getY()) * (point.getX() - a.getX());
}

// check if the point is in the same region as the inside point
static bool	isInsideRegion(bspNode *root, Point const point)
{
	Fixed	detPoint;
	Fixed	detInsidePoint;
	bool	res;
	
	detPoint = getDet(*root->delimiter1, *root->delimiter2, point);
	detInsidePoint = getDet(*root->delimiter1, *root->delimiter2, *root->insidePoint);
	res = (detPoint * detInsidePoint > 0);
	printEvaluationRes(res);
	return res;	
}

// check if the point is inside the triangle (reccursive function)
static bool isInside(bspNode *root, Point const point)
{
	printIsInside(root);
	if (root->isLeaf == true)
		return root->isInside;
	if (isInsideRegion(root, point) == true)
		return (isInside(root->inside, point));
	return (isInside(root->outside, point));
}


// BSP
bool 	bsp(Point const a, Point const b, Point const c, Point const point)
{
	bspNode	root;
	//as there is no assignment operator in Point class -> need to use pointers ..?
	Point 	p1 = Point(a); 
	Point 	p2 = Point(b);
	Point 	p3 = Point(c);
	
	if (checkTriangle(a, b, c) == false)
		return false;
	makeBspTree(&root, &p1, &p2, &p3);
	bool res = isInside(&root, point);
	deleteTree(root);
	return res;
}
