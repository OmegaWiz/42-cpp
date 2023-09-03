/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:20:00 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/02 18:57:22 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Untitled Presidential Pardon Form", 25, 5), _target("Untitled Target"){
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5), _target(target){
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other), _target(other._target){
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
	(void) other;
	return (*this);
}

void PresidentialPardonForm::action() const{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream &operator<<(std::ostream &output, PresidentialPardonForm const &form) {
	output << "PresidentialPardonForm \"" << form.getName() << "\" is " << (form.getIsSigned() ? "signed. " : "not signed. ") << "gradeToSign: " << form.getGradeToSign() << " gradeToExecute: " << form.getGradeToExecute() << std::endl;
	return (output);
};
