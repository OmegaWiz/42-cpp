/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:21:20 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/06/29 15:02:32 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	DiamondTrap	diamond("Diamond");
	DiamondTrap	diamond2("Diamond2");

	std::cout << diamond.getHitPoints() << std::endl;
	std::cout << diamond.getEnergyPoints() << std::endl;
	std::cout << diamond.getAttackDamage() << std::endl;

	diamond.attack("Diamond2");
	diamond2.takeDamage(30);
	diamond2.beRepaired(10);
	diamond2.attack("Diamond");
	diamond.takeDamage(20);
	diamond.takeDamage(20);
	diamond.beRepaired(10);
	diamond.whoAmI();
	diamond.highFivesGuys();
	diamond.guardGate();
	return (0);
}
