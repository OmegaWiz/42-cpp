/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:11:57 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/03 13:42:42 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Untitled AForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
};

AForm::~AForm() {
};

AForm::AForm(AForm const &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
};

AForm &AForm::operator=(AForm const &other) {
	if (this != &other) {
		_isSigned = other.getIsSigned();
	}
	return (*this);
};

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	try
	{
		if (gradeToSign < 1) {
			throw AForm::GradeTooHighException();
		} else if (gradeToSign > 150) {
			throw AForm::GradeTooLowException();
		}
	}
	catch(const AException& e)
	{
		std::cerr << e.getMsg() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		if (gradeToExecute < 1) {
			throw AForm::GradeTooHighException();
		} else if (gradeToExecute > 150) {
			throw AForm::GradeTooLowException();
		}
	}
	catch(const AException& e)
	{
		std::cerr << e.getMsg() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
};

std::string			AForm::getName() const {
	return (_name);
};

bool				AForm::getIsSigned() const {
	return (_isSigned);
};

int					AForm::getGradeToSign() const {
	return (_gradeToSign);
};

int					AForm::getGradeToExecute() const {
	return (_gradeToExecute);
};

AForm::GradeTooHighException::GradeTooHighException() : AException() {
	_msg = "Error: Grade too high";
};

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Error: Grade too high");
};

AForm::GradeTooLowException::GradeTooLowException() : AException() {
	_msg = "Error: Grade too low";
};

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Error: Grade too low");
};

AForm::FormNotSignedException::FormNotSignedException() : AException() {
	_msg = "Error: Form has not been signed";
};

const char *AForm::FormNotSignedException::what() const throw() {
	return ("Error: Form has not been signed");
};

AForm::ActionNotExecutedException::ActionNotExecutedException() : AException() {
	_msg = "Error: Action cannot be executed";
};

const char *AForm::ActionNotExecutedException::what() const throw() {
	return ("Error: Action cannot be executed");
};

void	AForm::beSigned(Bureaucrat &bureaucrat) {
	try
	{
		if (bureaucrat.getGrade() > _gradeToSign) {
			throw AForm::GradeTooLowException();
		} else {
			_isSigned = true;
		}
	}
	catch(const AException& e)
	{
		std::cerr << e.getMsg() << std::endl;
		throw e;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		throw AException(e.what());
	}
};

void	AForm::execute(Bureaucrat const &executor) const {
	try
	{
		if (!_isSigned) {
			throw AForm::FormNotSignedException();
		} else if (executor.getGrade() > _gradeToExecute) {
			throw AForm::GradeTooLowException();
		} else {
			action();
		}
	}
	catch(const AException& e)
	{
		std::cerr << e.getMsg() << std::endl;
		throw e;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		throw AException(e.what());
	}
};

std::ostream &operator<<(std::ostream &output, AForm const &form) {
	output << "AForm \"" << form.getName() << "\" is " << (form.getIsSigned() ? "signed. " : "not signed. ") << "gradeToSign: " << form.getGradeToSign() << " gradeToExecute: " << form.getGradeToExecute() << std::endl;
	return (output);
};
