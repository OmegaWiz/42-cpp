/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:31:25 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/03 14:05:21 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "AException.hpp"

class Intern {
	public:
		Intern();
		~Intern();
		Intern(Intern const &other);
		Intern &operator=(Intern const &other);

		AForm *makeForm(std::string const &formName, std::string const &target);
		AForm *makePresidentialPardonForm(std::string const &target);
		AForm *makeRobotomyRequestForm(std::string const &target);
		AForm *makeShrubberyCreationForm(std::string const &target);

		class FormNotFoundException : public AException {
			public:
				FormNotFoundException();
				virtual const char *what() const throw();
		};
};

#endif
