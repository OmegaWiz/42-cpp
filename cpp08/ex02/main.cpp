/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:19:01 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/10/15 14:50:24 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	std::cout << "pushed 5" << std::endl;
	mstack.push(17);
	std::cout << "pushed 17" << std::endl;

	std::cout << "top: " << mstack.top() << std::endl;

	mstack.pop();
	std::cout << "popped 17" << std::endl;

	std::cout << "current mstack size is: " << mstack.size() << std::endl;

	mstack.push(3);
	std::cout << "pushed 3" << std::endl;
	mstack.push(5);
	std::cout << "pushed 5" << std::endl;
	mstack.push(737);
	std::cout << "pushed 737" << std::endl;
	mstack.push(0);
	std::cout << "pushed 0" << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	std::cout << "MutantStack: ";
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	std::stack<int> s(mstack);
	return 0;
}
