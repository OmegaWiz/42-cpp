/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:42:04 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/06/29 16:42:38 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &wrongAnimal) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = wrongAnimal;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const &wrongAnimal) {
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	if (this != &wrongAnimal)
		this->_type = wrongAnimal._type;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal makeSound called" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->_type;
}

void WrongAnimal::setType(std::string type) {
	this->_type = type;
}
