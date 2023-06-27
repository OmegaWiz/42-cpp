/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 08:24:14 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/06/27 10:22:57 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	main(void)
{
	Phonebook	phonebook;
	std::string	command;

	std::cout << "Enter a command: ";
	while (std::getline(std::cin, command))
	{
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
			return (0);
		else
		{
			std::cout << "Invalid command" << std::endl << std::endl;
			std::cout << "Possible Commands: " << std::endl;
			std::cout << "ADD" << std::endl;
			std::cout << "SEARCH" << std::endl;
			std::cout << "EXIT" << std::endl;
		}
		std::cin.clear();
		std::cout << "Enter a command: ";
	}
	return (0);
}
