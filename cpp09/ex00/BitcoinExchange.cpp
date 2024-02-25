/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:02:35 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/10/21 13:38:04 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string const &file)
{
	_file = file;
	std::ifstream ifs(file);
	std::string str;
	std::string buf(4096, '\0');
	if (!ifs.is_open())
		throw std::runtime_error("Error: could not open file.");
	while (ifs.read(&buf[0], buf.size()))
	{
		str.append(buf, 0, ifs.gcount());
	}
	if (ifs.bad())
		throw std::runtime_error("Error: could not read file.");
	ifs.close();
	std::cout << str << std::endl;
	
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
	if (this != &other)
	{
		_file = other._file;
	}
	return (*this);
}

