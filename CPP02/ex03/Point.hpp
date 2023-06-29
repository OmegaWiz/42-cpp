/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 08:54:06 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/06/29 09:03:12 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	public:
		Point();
		~Point();
		Point(Point const &point);
		Point& operator=(Point const &point);

		Point(const float x, const float y);

		float getX(void) const;
		float getY(void) const;

	private:
		Fixed const _x;
		Fixed const _y;
};

std::ostream& operator<<(std::ostream &out, Point const &point);

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
