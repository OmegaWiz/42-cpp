/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:11:57 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/02 16:05:18 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

Form::Form() : _name("Untitled Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
};

Form::~Form() {
};

Form::Form(Form const &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
};

Form &Form::operator=(Form const &other) {
	if (this != &other) {
		_isSigned = other.getIsSigned();
	}
	return (*this);
};

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	try
	{
		if (gradeToSign < 1) {
			throw Form::GradeTooHighException();
		} else if (gradeToSign > 150) {
			throw Form::GradeTooLowException();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		if (gradeToExecute < 1) {
			throw Form::GradeTooHighException();
		} else if (gradeToExecute > 150) {
			throw Form::GradeTooLowException();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
};

std::string			Form::getName() const {
	return (_name);
};

bool				Form::getIsSigned() const {
	return (_isSigned);
};

int					Form::getGradeToSign() const {
	return (_gradeToSign);
};

int					Form::getGradeToExecute() const {
	return (_gradeToExecute);
};

const char *Form::GradeTooHighException::what() const throw() {
	return ("Error: Grade too high");
};

const char *Form::GradeTooLowException::what() const throw() {
	return ("Error: Grade too low");
};

void	Form::beSigned(Bureaucrat &bureaucrat) {
	try
	{
		if (bureaucrat.getGrade() > _gradeToSign) {
			throw Form::GradeTooLowException();
		} else {
			_isSigned = true;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
};

std::ostream &operator<<(std::ostream &output, Form const &form) {
	output << "Form \"" << form.getName() << "\" is " << (form.getIsSigned() ? "signed. " : "not signed. ") << "gradeToSign: " << form.getGradeToSign() << " gradeToExecute: " << form.getGradeToExecute() << std::endl;
	return (output);
};
