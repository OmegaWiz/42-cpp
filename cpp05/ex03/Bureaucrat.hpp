/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:39:53 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/03 13:03:34 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "AForm.hpp"
# include "AException.hpp"

class AForm;

class Bureaucrat {
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat &operator=(Bureaucrat const &other);

		Bureaucrat(std::string name, int grade);

		std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form);
		void executeForm(AForm const &form);

		class GradeTooHighException : public AException {
			public:
				GradeTooHighException();
				const char* what() const throw();
		};
		class GradeTooLowException : public AException {
			public:
				GradeTooLowException();
				const char* what() const throw();
		};

	private:
		std::string const _name;
		int _grade;
};

std::ostream& operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif
