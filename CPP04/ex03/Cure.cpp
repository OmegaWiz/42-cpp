/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 08:32:00 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/08/02 08:32:19 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
}

Cure::~Cure() {
}

Cure::Cure(Cure const &cure) {
	*this = cure;
}

Cure& Cure::operator=(Cure const &cure) {
	if (this != &cure)
		this->_type = cure._type;
	return (*this);
}

Cure::Cure(std::string const &type) : AMateria(type) {
}

AMateria* Cure::clone() const {
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
