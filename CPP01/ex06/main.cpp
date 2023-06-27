/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:13:26 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/06/27 14:59:08 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	complainLevel(std::string complain)
{
	if (complain == "debug")
		return (0);
	else if (complain == "info")
		return (1);
	else if (complain == "warning")
		return (2);
	else if (complain == "error")
		return (3);
	return (-1);
}

int	main(int argc, char **argv)
{
	Harl	harl = Harl();
	std::string complain;
	if (argc != 1)
		complain = "";
	else
		complain = argv[1];
	int complainCnt = 1;

	switch(complainLevel(complain))
	{
		case -1:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		case 0:
			for (int i = 0; i < complainCnt; i++)
				harl.complain("debug");
		case 1:
			for (int i = 0; i < complainCnt; i++)
				harl.complain("info");
		case 2:
			for (int i = 0; i < complainCnt; i++)
				harl.complain("warning");
		case 3:
			for (int i = 0; i < complainCnt; i++)
				harl.complain("error");
	}
	return (0);
}
