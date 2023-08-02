/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 08:28:31 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/08/02 08:58:53 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {
}

AMateria::~AMateria() {
}

AMateria::AMateria(AMateria const &aMateria) {
	*this = aMateria;
}

AMateria& AMateria::operator=(AMateria const &aMateria) {
	if (this != &aMateria)
		this->_type = aMateria._type;
	return (*this);
}

AMateria::AMateria(std::string const &type) : _type(type) {
}

std::string const &AMateria::getType() const {
	return (this->_type);
}

void AMateria::use(ICharacter& target) {
	std::cout << "* use " << this->_type << " at " << target.getName() << " *" << std::endl;
}
