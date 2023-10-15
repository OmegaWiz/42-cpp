/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:58:53 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/10/15 08:46:39 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>


int main(void) {
	std::string s;
	std::cout << "Select a container: vector, list, deque" << std::endl;
	std::cin >> s;
	if (s == "vector") {
		std::vector<int> v;
		for (int i = 0; i < 10; i++)
			v.push_back(i);
		std::cout << "Vector: ";
		for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::cout << "Enter a number to find: ";
		int n;
		std::cin >> n;
		std::vector<int>::iterator it = easyfind(v, n);
		if (it != v.end())
			std::cout << "Found " << n << " at index " << it - v.begin() << std::endl;
		else
			std::cout << "Not found" << std::endl;
	}
	else if (s == "list") {
		std::list<int> l;
		for (int i = 0; i < 10; i++)
			l.push_back(i);
		std::cout << "List: ";
		for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::cout << "Enter a number to find: ";
		int n;
		std::cin >> n;
		std::list<int>::iterator it = easyfind(l, n);
		if (it != l.end())
			std::cout << "Found " << n << std::endl;
		else
			std::cout << "Not found" << std::endl;
	}
	else if (s == "deque") {
		std::deque<int> d;
		for (int i = 0; i < 10; i++)
			d.push_back(i);
		std::cout << "Deque: ";
		for (std::deque<int>::iterator it = d.begin(); it != d.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		std::cout << "Enter a number to find: ";
		int n;
		std::cin >> n;
		std::deque<int>::iterator it = easyfind(d, n);
		if (it != d.end())
			std::cout << "Found " << n << " at index " << it - d.begin() << std::endl;
		else
			std::cout << "Not found" << std::endl;
	}
	else
		std::cout << "Invalid container" << std::endl;
}
