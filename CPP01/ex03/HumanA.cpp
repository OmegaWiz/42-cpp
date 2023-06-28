/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:22:20 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/06/28 11:19:47 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	return ;
}

HumanA::~HumanA()
{
	std::cout << this->_name << " is dead" << std::endl;
	return ;
}

void	HumanA::attack(void)
{
	std::string str = this->_weapon.getType();
	std::cout << this->_name << " attacks with his " << str << std::endl;
}
