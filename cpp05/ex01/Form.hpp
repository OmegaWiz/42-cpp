/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:06:51 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/02 15:40:09 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form();
		~Form();
		Form(Form const &other);
		Form &operator=(Form const &other);
		Form(std::string name, int gradeToSign, int gradeToExecute);

		std::string		getName() const;
		bool			getIsSigned() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		void				beSigned(Bureaucrat &bureaucrat);

	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExecute;
};

std::ostream &operator<<(std::ostream &output, Form const &form);

#endif
