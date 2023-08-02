/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 08:32:27 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/08/02 08:33:06 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default") {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i])
			delete this->_inventory[i];
}

Character::Character(Character const &character) {
	*this = character;
}

Character& Character::operator=(Character const &character) {
	if (this != &character)
	{
		this->_name = character._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			this->_inventory[i] = character._inventory[i]->clone();
		}
	}
	return (*this);
}

Character::Character(std::string const &name) : _name(name) {
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

std::string const &Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria* m) {
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3 || this->_inventory[idx] == NULL)
		return ;
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3 || this->_inventory[idx] == NULL)
		return ;
	this->_inventory[idx]->use(target);
}
