/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:12:33 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/08/02 14:32:58 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point a(0.0f, 0.0f);
	Point b(1.0f, 1.0f);
	Point c(2.0f, 2.0f);
	Point p(3.0f, 3.0f);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "p = " << p << std::endl;
	std::cout << "bsp(a, b, c, p) = " << bsp(a, b, c, p) << std::endl;
	return 0;
}