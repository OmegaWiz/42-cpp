/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:06:51 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/03 13:13:57 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"
# include "AException.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm();
		virtual ~AForm();
		AForm(AForm const &other);
		AForm &operator=(AForm const &other);
		AForm(std::string name, int gradeToSign, int gradeToExecute);

		std::string		getName() const;
		bool			getIsSigned() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;

		class GradeTooHighException : public AException {
			public:
				GradeTooHighException();
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public AException {
			public:
				GradeTooLowException();
				virtual const char *what() const throw();
		};

		class FormNotSignedException : public AException {
			public:
				FormNotSignedException();
				virtual const char *what() const throw();
		};

		class ActionNotExecutedException : public AException {
			public:
				ActionNotExecutedException();
				virtual const char *what() const throw();
		};

		void				beSigned(Bureaucrat &bureaucrat);
		void				execute(Bureaucrat const &executor) const;
		virtual void		action() const = 0;

	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExecute;
};

std::ostream &operator<<(std::ostream &output, AForm const &form);

#endif
