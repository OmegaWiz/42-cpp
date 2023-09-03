/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:48:09 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/03 13:41:27 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Untitled Shrubbery Creation Form", 145, 137), _target("Untitled"){
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other), _target(other._target) {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
	(void) other;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137), _target(target){
}

void ShrubberyCreationForm::action() const {
	try
	{
		std::ofstream file(this->getName() + "_shrubbery");
		if (!file.is_open()) {
			throw std::runtime_error("Error: File \"" + this->getName() + "_shrubbery" + "\" could not be opened");
		}
		file << "                A\n";
		file << "             /  |  \\\n";
		file << "            /   |   \\\n";
		file << "           B    C    D\n";
		file << "          / \\   |   /| \\\n";
		file << "         E   F  G  H I J\n";
		file << "            / \\\n";
		file << "           K   L\n";
		file << std::endl << std::endl;
		file << "                A\n";
		file << "             /  |  \\\n";
		file << "            /   |   \\\n";
		file << "           B    C    D\n";
		file << "          / \\   |   /| \\\n";
		file << "         E   F  G  H I J\n";
		file << "            / \\\n";
		file << "           K   L\n";
		file.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw (AException(e.what()));
	}
}

std::ostream &operator<<(std::ostream &output, ShrubberyCreationForm const &form) {
	output << "ShrubberyCreationForm \"" << form.getName() << "\" is " << (form.getIsSigned() ? "signed. " : "not signed. ") << "gradeToSign: " << form.getGradeToSign() << " gradeToExecute: " << form.getGradeToExecute() << std::endl;
	return (output);
};
