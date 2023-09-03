/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:26:43 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/02 18:54:16 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &other);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
		RobotomyRequestForm(std::string target);

		std::string getTarget() const;
		void action() const;

	private:
		RobotomyRequestForm();
		std::string const _target;
};

std::ostream& operator<<(std::ostream &out, RobotomyRequestForm const &form);

#endif
