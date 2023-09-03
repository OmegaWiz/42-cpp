/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:43:56 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/02 16:14:56 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "----------Form test----------" << std::endl;
	Form f1;
	std::cout << f1;
	Form f2("Test Form", 10, 10);
	std::cout << f2;
	Form f3("Test Form", 0, 10);
	std::cout << "----------------------------" << std::endl;
	Form f4("Test Form", 10, 0);
	std::cout << "----------------------------" << std::endl;
	Form f5("Test Form", 0, 0);
	std::cout << "----------------------------" << std::endl;
	Form f6("Test Form", 500, 0);
	std::cout << "----------------------------" << std::endl;
	Form f7("Test Form", 0, 500);
	std::cout << "----------------------------" << std::endl;
	Form b45("B45", 10, 10);
	std::cout << b45;
	Bureaucrat armel("Armel", 10);
	std::cout << armel;
	Bureaucrat vlad("Vlad", 1);
	std::cout << vlad;
	Bureaucrat milya("Milya", 150);
	std::cout << milya;
	b45.beSigned(milya);
	std::cout << b45;
	b45.beSigned(armel);
	std::cout << b45;
	b45.beSigned(vlad);
	std::cout << b45;
	std::cout << "----------------------------" << std::endl;
	Form c8("C8", 10, 10);
	std::cout << c8;
	milya.signForm(c8);
	armel.signForm(c8);
	vlad.signForm(c8);
	return (0);
}
