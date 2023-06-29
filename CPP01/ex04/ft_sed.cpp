/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sed.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:04:59 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/06/28 11:03:26 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sed.hpp"

int	ft_sed(std::string filename, std::string s1, std::string s2)
{
	const int read_size = 4096;
	std::ifstream ifs(filename);
	std::string str;
	std::string buf(read_size, '\0');

	if (ifs.is_open() == false)
	{
		std::cout << "ft_sed: Error: " << filename << ": could not open file" << std::endl;
		return (1);
	}
	if (ifs.fail() == true)
	{
		std::cout << "ft_sed: Error: " << filename << ": could not read file" << std::endl;
		return (1);
	}

	while (ifs.read(&buf[0], read_size))
	{
		str.append(buf, 0, ifs.gcount());
	}
	str.append(buf, 0, ifs.gcount());
	ifs.close();

	while (str.find(s1) != std::string::npos)
	{
		int cutPos = str.find(s1);
		std::string tmp = str.substr(0, cutPos);
		tmp += s2;
		tmp += str.substr(cutPos + s1.length());
		str = tmp;
	}

	std::ofstream ofs(filename + ".replace", std::ios::trunc);
	if (ofs.is_open() == false)
	{
		std::cout << "ft_sed: Error: " << filename + ".replace" << ": could not open file" << std::endl;
		return (1);
	}
	ofs << str;
	ofs.close();
	return (0);
}
