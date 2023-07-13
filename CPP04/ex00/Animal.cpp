/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:14:03 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/06/29 16:55:19 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(Animal const &animal) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = animal;
}

Animal& Animal::operator=(Animal const &animal) {
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &animal)
		this->_type = animal._type;
	return *this;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal default constructor called" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Animal makeSound called" << std::endl;
}

std::string Animal::getType() const {
	return this->_type;
}

void Animal::setType(std::string type) {
	this->_type = type;
}
