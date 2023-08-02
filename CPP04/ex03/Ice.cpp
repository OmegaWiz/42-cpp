/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 08:31:31 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/08/02 08:31:50 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
}

Ice::~Ice() {
}

Ice::Ice(Ice const &ice) {
	*this = ice;
}

Ice& Ice::operator=(Ice const &ice) {
	if (this != &ice)
		this->_type = ice._type;
	return (*this);
}

Ice::Ice(std::string const &type) : AMateria(type) {
}

AMateria* Ice::clone() const {
	return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
