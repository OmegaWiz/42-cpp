/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:20:00 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/02 18:56:51 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &other);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
		PresidentialPardonForm(std::string target);

		std::string getTarget() const;
		void action() const;

	private:
		PresidentialPardonForm();
		std::string const _target;
};

std::ostream& operator<<(std::ostream &out, PresidentialPardonForm const &form);

#endif
