/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:41:59 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/17 11:42:46 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert [string]" << std::endl;
		return (1);
	}
	ScalarConverter scalar;
	scalar.convert(argv[1]);
	scalar.printChar();
	scalar.printInt();
	scalar.printFloat();
	scalar.printDouble();
	return (0);
}
