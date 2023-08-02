/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:43:56 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/08/02 20:14:15 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

int main()
{
	std::cout << "----------Bureaucrat test----------" << std::endl;
	std::cout << "----------Default Constructor----------" << std::endl;
	Bureaucrat b1;
	std::cout << b1;

	std::cout << "----------Copy Constructor, Deep Copy----------" << std::endl;
	Bureaucrat *b2 = new Bureaucrat();
	std::cout << *b2;
	Bureaucrat b3(*b2);
	delete b2;
	std::cout << b3;

	std::cout << "----------Assign Operator, Deep Copy----------" << std::endl;
	Bureaucrat *b4 = new Bureaucrat();
	std::cout << *b4;
	Bureaucrat b5 = *b4;
	delete b4;
	std::cout << b5;

	std::cout << "----------Constructor with parameters----------" << std::endl;
	Bureaucrat b6("Milya", 10);
	std::cout << b6;

	std::cout << "----------getName() attribute----------" << std::endl;
	std::cout << b6.getName() << std::endl;

	std::cout << "----------getGrade() attribute----------" << std::endl;
	std::cout << b6.getGrade() << std::endl;

	std::cout << "----------incrementGrade() method----------" << std::endl;
	b6.incrementGrade();
	std::cout << b6;

	std::cout << "----------decrementGrade() method----------" << std::endl;
	b6.decrementGrade();
	std::cout << b6;

	std::cout << "----------GradeTooHighException----------" << std::endl;
	Bureaucrat b7("Vlad", 0);
	Bureaucrat b8("Vlad", -1);
	Bureaucrat b9("Vlad", 1);
	std::cout << b9;
	b9.incrementGrade();

	std::cout << "----------GradeTooLowException----------" << std::endl;
	Bureaucrat b10("Vlad", 151);
	Bureaucrat b11("Vlad", 150);
	std::cout << b11;
	b11.decrementGrade();

	return (0);
}
