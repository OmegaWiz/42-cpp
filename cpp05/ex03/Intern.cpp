/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:44:40 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/03 14:05:39 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
}

Intern::~Intern() {
}

Intern::Intern(Intern const &other) {
	*this = other;
}

Intern &Intern::operator=(Intern const &other) {
	if (this != &other) {
	}
	return *this;
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) {
	AForm *form = NULL;
	int	N = 3;
	std::string formNames[] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	typedef AForm *(Intern::*functions)(std::string const &target);
	functions fcns[] = {
		&Intern::makePresidentialPardonForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makeShrubberyCreationForm
	};

	try
	{
		for (int i = 0; i < N; i++) {
			if (formNames[i] == formName) {

					form = (this->*fcns[i])(target);
					std::cout << "Intern makes " << target << std::endl;
					return form;
				}
		}
		throw FormNotFoundException();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Intern cannot make " << target << " because " << e.what() << std::endl;
	}
	return form;
}

AForm *Intern::makePresidentialPardonForm(std::string const &target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomyRequestForm(std::string const &target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeShrubberyCreationForm(std::string const &target) {
	return new ShrubberyCreationForm(target);
}

Intern::FormNotFoundException::FormNotFoundException() : AException() {
	_msg = "Form not found";
}

const char *Intern::FormNotFoundException::what() const throw() {
	return ("Form not found");
}
