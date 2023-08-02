/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:33:21 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/13 09:56:29 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "idea" + std::to_string(i);
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(Brain const &brain) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = brain;
}

Brain& Brain::operator=(Brain const &brain) {
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &brain)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = brain._ideas[i];
	}
	return *this;
}

std::string Brain::getIdea(int index){
	if (index < 0 || index >= 100)
		return (std::string());
	else
		return (this->_ideas[index]);
}
