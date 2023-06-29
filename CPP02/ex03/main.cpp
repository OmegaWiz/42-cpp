/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:16:40 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/06/29 09:44:54 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main( void )
{
	Point a(0, 0);
	Point b(0, 10);
	Point c(10, 0);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "----------------------------------" << std::endl;

	Point d(0, 0);
	Point e(2, 2);
	Point f(10, 10);
	Point g(5, 5);
	Point h(4, 5);
	Point i(0, 8);
	Point j(-2, -3);
	Point test[7] = {d, e, f, g, h, i, j};
	for (int i = 0; i < 7; i++)
	{
		std::cout << "test[" << i << "]: " << test[i];
		if (bsp(a, b, c, test[i]))
			std::cout << " is inside the triangle" << std::endl;
		else
			std::cout << " is outside the triangle" << std::endl;
	}
	std::cout << "----------------------------------" << std::endl;
	return (0);
}
