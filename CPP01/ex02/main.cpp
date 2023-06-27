/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:13:26 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/06/27 11:31:40 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";

	std::string *ptr = &str;
	std::string &ref = str;

	std::cout << "Address of str: " << &str << std::endl;
	std::cout << "Address of ptr: " << &ptr << std::endl;
	std::cout << "Address of ref: " << &ref << std::endl;

	std::cout << "Value of str: " << str << std::endl;
	std::cout << "Value of ptr: " << *ptr << std::endl;
	std::cout << "Value of ref: " << ref << std::endl;
	return (0);
}
