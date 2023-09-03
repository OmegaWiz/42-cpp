/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:43:56 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/02 19:31:01 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <fstream>
#include <sys/stat.h>

int main()
{
	std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;

	Bureaucrat b1("sunny1", 146);
	std::cout << b1;
	Bureaucrat b2("sunny2", 145);
	std::cout << b2;
	Bureaucrat b3("sunny3", 144);
	std::cout << b3;
	ShrubberyCreationForm scf1("armel");
	std::cout << scf1;
	b1.signForm(scf1);
	b1.executeForm(scf1);
	b2.signForm(scf1);
	b2.executeForm(scf1);
	b3.signForm(scf1);
	b3.executeForm(scf1);
	std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;

	Bureaucrat b4("sunny4", 138);
	std::cout << b4;
	Bureaucrat b5("sunny5", 137);
	std::cout << b5;
	Bureaucrat b6("sunny6", 136);
	std::cout << b6;
	ShrubberyCreationForm scf2("aoudin");
	std::cout << scf2;
	b4.signForm(scf2);
	b4.executeForm(scf2);
	b5.signForm(scf2);
	b5.executeForm(scf2);
	b6.signForm(scf2);
	b6.executeForm(scf2);
	std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;

	Bureaucrat b7("sunny7", 73);
	std::cout << b7;
	Bureaucrat b8("sunny8", 72);
	std::cout << b8;
	Bureaucrat b9("sunny9", 71);
	std::cout << b9;
	RobotomyRequestForm rrf1("milya");
	std::cout << rrf1;
	b7.signForm(rrf1);
	b7.executeForm(rrf1);
	b8.signForm(rrf1);
	b8.executeForm(rrf1);
	b9.signForm(rrf1);
	b9.executeForm(rrf1);
	std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;

	Bureaucrat b10("jlimb1", 46);
	std::cout << b10;
	Bureaucrat b11("jlimb2", 45);
	std::cout << b11;
	Bureaucrat b12("jlimb3", 44);
	std::cout << b12;
	RobotomyRequestForm rrf2("cpasty");
	std::cout << rrf2;
	b10.signForm(rrf2);
	b10.executeForm(rrf2);
	b11.signForm(rrf2);
	b11.executeForm(rrf2);
	b12.signForm(rrf2);
	b12.executeForm(rrf2);
	std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;

	Bureaucrat b13("jlimb4", 26);
	std::cout << b13;
	Bureaucrat b14("jlimb5", 25);
	std::cout << b14;
	Bureaucrat b15("jlimb6", 24);
	std::cout << b15;
	PresidentialPardonForm ppf1("vlad");
	std::cout << ppf1;
	b13.signForm(ppf1);
	b13.executeForm(ppf1);
	b14.signForm(ppf1);
	b14.executeForm(ppf1);
	b15.signForm(ppf1);
	b15.executeForm(ppf1);
	std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;

	Bureaucrat b16("jlimb7", 6);
	std::cout << b16;
	Bureaucrat b17("jlimb8", 5);
	std::cout << b17;
	Bureaucrat b18("jlimb9", 4);
	std::cout << b18;
	PresidentialPardonForm ppf2("VLAD");
	std::cout << ppf2;
	b16.signForm(ppf2);
	b16.executeForm(ppf2);
	b17.signForm(ppf2);
	b17.executeForm(ppf2);
	b18.executeForm(ppf2);
	b18.signForm(ppf2);
	std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;

	Bureaucrat q("Queen of Ladkrabang", 1);
	std::cout << q;
	RobotomyRequestForm rrf3("42Bangkok");
	std::cout << rrf3;
	q.executeForm(rrf3);
	q.signForm(rrf3);
	q.executeForm(rrf3);
	q.executeForm(rrf3);
	q.executeForm(rrf3);
	std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
	try
	{
		std::ofstream ofs("no_shrubbery");
		if (!ofs.is_open()) {
			throw std::runtime_error("Couldn't open file");
		}
		if (chmod("no_shrubbery", S_IRUSR | S_IRGRP | S_IROTH) == -1) {
			throw std::runtime_error("Couldn't chmod file");
		}
		ofs.close();
		ShrubberyCreationForm scf3("no");
		std::cout << scf3;
		q.signForm(scf3);
		q.executeForm(scf3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
