/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:19:11 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/13 10:36:59 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(){
	this->setType("Cat");
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(Cat const &cat) {
	*this = cat;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(Cat const &cat) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &cat)
	{
		this->setType(cat.getType());
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}
