/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:58:53 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/10/15 14:43:24 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>


int main(void) {
	std::vector<int> v;
	v.push_back(100);
	v.push_back(-100);
	v.push_back(0);
	v.push_back(42);
	v.push_back(21);
	std::cout << "vector: ";
	for (int i = 0; i < (int) v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
	std::cout << "easyfind(v, 42): " << easyfind(v, 42) - v.begin() << std::endl << std::endl;

	std::list<int> l;
	l.push_back(100);
	l.push_back(-100);
	l.push_back(0);
	l.push_back(42);
	l.push_back(21);
	std::cout << "list: ";
	for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "easyfind(l, -100): " << (easyfind(l, -100) != l.end()) << std::endl << std::endl;

	std::deque<int> d;
	d.push_back(100);
	d.push_back(-100);
	d.push_back(0);
	d.push_back(42);
	d.push_back(21);
	std::cout << "deque: ";
	for (std::deque<int>::iterator it = d.begin(); it != d.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "easyfind(d, 100): " << easyfind(d, 100) - d.begin() << std::endl << std::endl;

	std::cout << "easyfind(d, 1000): " << (easyfind(d, 1000) != d.end() ? "True" : "False") << std::endl << std::endl;

}
