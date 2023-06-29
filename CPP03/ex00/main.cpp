/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:21:20 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/06/29 14:02:18 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap clap("Clap");
	ClapTrap clap2("Clap2");
	ClapTrap clap3("Clap3");

	clap.attack("Clap2");
	clap2.takeDamage(2);
	clap2.attack("Clap3");
	clap3.takeDamage(2);
	clap3.beRepaired(2);
	return (0);
}
