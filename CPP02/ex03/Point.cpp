/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 08:54:46 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/06/29 09:03:24 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::~Point()
{
}

Point::Point(Point const &point) : _x(point._x), _y(point._y)
{
}

Point& Point::operator=(Point const &point)
{
	(void)point;
	return (*this);
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

float Point::getX(void) const
{
	return (this->_x.toFloat());
}

float Point::getY(void) const
{
	return (this->_y.toFloat());
}

std::ostream& operator<<(std::ostream &out, Point const &point)
{
	out << "Point(" << point.getX() << ", " << point.getY() << ")";
	return (out);
}
