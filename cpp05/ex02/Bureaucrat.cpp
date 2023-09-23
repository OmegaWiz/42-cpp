/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:39:52 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/03 13:25:42 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Armel"), _grade(150) {
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade) {
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
	if (this != &other) {
		_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	try
	{
		if (grade < 1) {
			_grade = 1;
			throw Bureaucrat::GradeTooHighException();
		} else if (grade > 150) {
			_grade = 150;
			throw Bureaucrat::GradeTooLowException();
		} else {
			_grade = grade;
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
}

std::string Bureaucrat::getName() const {
	return (_name);
}

int Bureaucrat::getGrade() const {
	return (_grade);
}

void Bureaucrat::incrementGrade() {
	try
	{
		if (_grade - 1 < 1) {
			throw Bureaucrat::GradeTooHighException();
		} else {
			_grade--;
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
}

void Bureaucrat::decrementGrade() {
	try
	{
		if (_grade + 1 > 150) {
			throw Bureaucrat::GradeTooLowException();
		} else {
			_grade++;
		}
	}
	catch(const AException& e)
	{
		std::cerr << e.getMsg() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Bureaucrat::signForm(AForm &form) {
	try
	{
		if (form.getGradeToSign() < _grade) {
			throw AForm::GradeTooLowException();
		} else {
			form.beSigned(*this);
			std::cout << _name << " signed " << form.getName() << std::endl;
		}
	}
	catch(const AException& e)
	{
		std::cerr << _name << " couldn't sign " << form.getName() << " because " << e.getMsg() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) {
	try
	{
		if (!form.getIsSigned()) {
			throw AForm::FormNotSignedException();
		} else if (form.getGradeToExecute() < _grade) {
			throw AForm::GradeTooLowException();
		} else {
			form.execute(*this);
			std::cout << _name << " executed " << form.getName() << std::endl;
		}
	}
	catch(const AException& e)
	{
		std::cerr << _name << " couldn't execute " << form.getName() << " because " << e.getMsg() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException() : AException() {
	_msg = "Error: Grade exceeds maximum";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Error: Grade exceeds maximum");
}

Bureaucrat::GradeTooLowException::GradeTooLowException() : AException() {
	_msg = "Error: Grade exceeds minimum";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Error: Grade exceeds minimum");
}

std::ostream& operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (out);
}