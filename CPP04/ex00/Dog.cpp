/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:27:48 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/08/02 07:38:54 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->setType("Dog");
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(Dog const &dog) {
	*this = dog;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(Dog const &dog) {
	if (this != &dog)
	{
		this->setType(dog.getType());
	}
	std::cout << "Dog assignation operator called" << std::endl;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}
