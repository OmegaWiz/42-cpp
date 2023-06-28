/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:19:41 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/06/28 11:17:14 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon()
{
	std::cout << this->_type << " is destroyed" << std::endl;
}

std::string const	&Weapon::getType(void)
{
	return (this->_type);
}

void				Weapon::setType(std::string type)
{
	this->_type = type;
}
