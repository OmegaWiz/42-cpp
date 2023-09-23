/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 04:44:37 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/23 12:17:53 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void print(int &x)
{
	std::cout << x << " ";
}

void add(int &x)
{
	x += 1;
}

void sub(int &x)
{
	x -= 1;
}

void mul(int &x)
{
	x *= 2;
}

void div(int &x)
{
	x /= 2;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	std::cout << "First array: ";
	::iter(arr, 5, print);
	std::cout << std::endl;

	std::cout << "Apply add 1: ";
	::iter(arr, 5, add);
	::iter(arr, 5, print);
	std::cout << std::endl;

	std::cout << "Apply sub 1: ";
	::iter(arr, 5, sub);
	::iter(arr, 5, print);
	std::cout << std::endl;

	std::cout << "Apply mul 2: ";
	::iter(arr, 5, mul);
	::iter(arr, 5, print);
	std::cout << std::endl;

	std::cout << "Apply div 2: ";
	::iter(arr, 5, div);
	::iter(arr, 5, print);
	std::cout << std::endl;
	return (0);
}
