/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 08:56:18 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/06/29 09:40:14 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

bool isOnLine(Point a, Point b, Point point)
{
	float slope;
	float y_intercept;

	slope = (b.getY() - a.getY()) / (b.getX() - a.getX());
	y_intercept = a.getY() - slope * a.getX();
	if (point.getY() == slope * point.getX() + y_intercept)
		return (true);
	return (false);
}

Fixed abs(Fixed a)
{
	if (a.toFloat() < 0)
		return (a.toFloat() * -1);
	return (a.toFloat());
}

Fixed area(Point a, Point b, Point c)
{
	Fixed area;

	area = ((a.getX() * b.getY()) + (c.getX() * a.getY()) + (b.getX() * c.getY())) - ((c.getX() * b.getY()) + (b.getX() * a.getY()) + (a.getX() * c.getY()));
	area = abs(area / Fixed(2));
	return (area);
}

bool bsp(Point a, Point b, Point c, Point point)
{
	// std::cout << std::endl << "bsp" << std::endl;
	// std::cout << "a: " << a << std::endl;
	// std::cout << "b: " << b << std::endl;
	// std::cout << "c: " << c << std::endl;
	// std::cout << "point: " << point << std::endl;
	if (isOnLine(a, b, point) || isOnLine(b, c, point) || isOnLine(c, a, point))
		return (false);
	Fixed area_abc = area(a, b, c);
	// std::cout << "area_abc: " << area_abc << std::endl;
	Fixed area_abp = area(a, b, point);
	// std::cout << "area_abp: " << area_abp << std::endl;
	Fixed area_acp = area(a, c, point);
	// std::cout << "area_acp: " << area_acp << std::endl;
	Fixed area_bcp = area(b, c, point);
	// std::cout << "area_bcp: " << area_bcp << std::endl;
	if (area_abc >= (area_abp + area_acp + area_bcp))
		return (true);
	return (false);
}

