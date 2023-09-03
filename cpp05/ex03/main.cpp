/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:43:56 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/03 14:01:46 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "AException.hpp"
#include "AForm.hpp"
#include <fstream>
#include <sys/stat.h>

int main()
{
	std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;

	Intern someRandomIntern;
	AForm* af;
	af = someRandomIntern.makeForm("robotomy request", "42 Bangkok");
	std::cout << *af;

	Bureaucrat q("Queen of Ladkrabang", 1);
	q.signForm(*af);
	q.executeForm(*af);

	delete af;

	std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;

	af = someRandomIntern.makeForm("presidential pardon", "sunny");
	std::cout << *af;
	q.signForm(*af);
	q.executeForm(*af);

	delete af;

	std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;

	af = someRandomIntern.makeForm("shrubbery creation", "home");
	std::cout << *af;
	q.signForm(*af);
	q.executeForm(*af);

	delete af;

	std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;

	af = someRandomIntern.makeForm("nonexist", "fake");

	return (0);
}
