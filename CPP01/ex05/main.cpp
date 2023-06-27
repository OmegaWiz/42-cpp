/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:13:26 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/06/27 14:41:04 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstdlib>

int main()
{
	Harl	harl = Harl();

	std::srand(std::time(NULL));
	int	complainCnt = std::rand() % 10;
	for (int i = 0; i < complainCnt; i++)
		harl.complain("debug");
	complainCnt = std::rand() % 10;
	for (int i = 0; i < complainCnt; i++)
		harl.complain("info");
	complainCnt = std::rand() % 10;
	for (int i = 0; i < complainCnt; i++)
		harl.complain("warning");
	complainCnt = std::rand() % 10;
	for (int i = 0; i < complainCnt; i++)
		harl.complain("error");
	return (0);
}
