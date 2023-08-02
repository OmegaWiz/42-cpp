/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 08:14:38 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/08/02 08:44:36 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <string>
# include <iostream>

class ICharacter;

class AMateria {
	public:
		AMateria();
		virtual ~AMateria();
		AMateria(AMateria const &amateria);
		AMateria& operator=(AMateria const &amateria);

		AMateria(std::string const &type);

		std::string const &getType() const; //Returns the materia type

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
	protected:
		std::string _type;
};

#endif
