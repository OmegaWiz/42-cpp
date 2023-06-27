/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 08:20:11 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/06/27 10:31:50 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <cstdlib>

Phonebook::Phonebook(void)
{
	this->_index = 0;
	this->_size = 0;
	this->_capacity = 8;
	return ;
}

Phonebook::~Phonebook(void)
{
	return ;
}

void	Phonebook::addContact()
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	do
	{
		std::cout << "Enter First Name: ";
		std::getline(std::cin, firstName);
	} while (firstName == "");
	do
	{
		std::cout << "Enter Last Name: ";
		std::getline(std::cin, lastName);
	} while (lastName == "");
	do
	{
		std::cout << "Enter Nickname: ";
		std::getline(std::cin, nickname);
	} while (nickname == "");
	do
	{
		std::cout << "Enter Phone Number: ";
		std::getline(std::cin, phoneNumber);
	} while (phoneNumber == "");
	do
	{
		std::cout << "Enter Darkest Secret: ";
		std::getline(std::cin, darkestSecret);
	} while (darkestSecret == "");
	this->_contacts[this->_index].setFirstName(firstName);
	this->_contacts[this->_index].setLastName(lastName);
	this->_contacts[this->_index].setNickname(nickname);
	this->_contacts[this->_index].setPhoneNumber(phoneNumber);
	this->_contacts[this->_index].setDarkestSecret(darkestSecret);
	this->_contacts[this->_index].setIndex(this->_index + 1);
	this->_index++;
	this->_index %= 8;
	if (this->_size < this->_capacity)
		this->_size++;
	else
		this->_size = this->_capacity;
	std::cout << "Contact added successfully" << std::endl;
}

std::string Phonebook::_trimAndPad(std::string str, size_t len)
{
	if (str.length() > len)
		return (str.substr(0, len - 1) + ".");
	else
	{
		while (str.length() < len)
			str = " " + str;
		return (str);
	}
}

void	Phonebook::searchContact(void)
{
	int			searchIndex;
	std::string	input;

	std::cout << "Saved Contact--------------------------------" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < this->_size; i++)
	{
		std::cout << "|         " << this->_contacts[i].getIndex() << "|";
		std::cout << this->_trimAndPad(this->_contacts[i].getFirstName(), 10) << "|";
		std::cout << this->_trimAndPad(this->_contacts[i].getLastName(), 10) << "|";
		std::cout << this->_trimAndPad(this->_contacts[i].getNickname(), 10) << "|" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}
	std::cout << "Enter index: ";
	std::getline(std::cin, input);
	std::stringstream(input) >> searchIndex;
	if (searchIndex > 0 && searchIndex <= this->_size)
	{
		searchIndex--;
		std::cout << "------------------------------------------" << std::endl;
		std::cout << "First Name: " << this->_contacts[searchIndex].getFirstName() << std::endl;
		std::cout << "Last Name: " << this->_contacts[searchIndex].getLastName() << std::endl;
		std::cout << "Nickname: " << this->_contacts[searchIndex].getNickname() << std::endl;
		std::cout << "Phone Number: " << this->_contacts[searchIndex].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << this->_contacts[searchIndex].getDarkestSecret() << std::endl;
		std::cout << "------------------------------------------" << std::endl;
	}
	else
	{
		if (searchIndex <= 0 || searchIndex > this->_size)
		{
			std::cout << "Phonebook: Error: Index out of range or invalid" << std::endl;
			std::cout << "Valid index range: 1 - 8" << std::endl;
		}
		else
		{
			std::cout << "Phonebook: Error: Invalid index" << std::endl;
			std::cout << "Phonebook currently have " << this->_size << " contacts" << std::endl;
		}
	}
}
