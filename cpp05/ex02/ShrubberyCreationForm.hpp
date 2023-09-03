/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:48:09 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/02 18:55:50 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &other);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
		ShrubberyCreationForm(std::string target);

		std::string getTarget() const;
		void action() const;

	private:
		ShrubberyCreationForm();
		std::string const _target;
};

std::ostream& operator<<(std::ostream &out, ShrubberyCreationForm const &form);

#endif
