/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:26:43 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/02 18:55:18 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Untitled Robotomy Request Form", 72, 45), _target("No target"){
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45), _target(target){
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other), _target(other._target){
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
	(void) other;
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const{
	return (_target);
}

void RobotomyRequestForm::action() const{
	std::srand(std::time(0));
	std::cout << "* DRILLING NOISES *" << std::endl;
	if (std::rand() % 2) {
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	} else {
		std::cout << this->getTarget() << " robotomization failed" << std::endl;
	}
}

std::ostream &operator<<(std::ostream &output, RobotomyRequestForm const &form) {
	output << "RobotomyRequestForm \"" << form.getName() << "\" is " << (form.getIsSigned() ? "signed. " : "not signed. ") << "gradeToSign: " << form.getGradeToSign() << " gradeToExecute: " << form.getGradeToExecute() << std::endl;
	return (output);
};
