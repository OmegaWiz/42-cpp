/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:32:16 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/17 12:14:19 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	this->_char = 0;
	this->_int = 0;
	this->_float = 0;
	this->_double = 0;
	this->_str = "";
	this->_isImpossible = true;
}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	if (this != &other)
	{
		this->_str = other._str;
		this->_char = other._char;
		this->_int = other._int;
		this->_float = other._float;
		this->_double = other._double;
	}
	return (*this);
}

void	ScalarConverter::convert(std::string const &str)
{
	this->_str = str;
	if (this->_str == "nan" || this->_str == "nanf")
		this->_double = std::numeric_limits<double>::quiet_NaN();
	else if (this->_str == "-inf" || this->_str == "-inff")
		this->_double = -std::numeric_limits<double>::infinity();
	else if (this->_str == "+inf" || this->_str == "+inff")
		this->_double = std::numeric_limits<double>::infinity();
	else
	{
		this->_double = std::strtod(this->_str.c_str(), NULL);
		if (this->_double == 0 && this->_str[0] != '0')
			throw ImpossibleException();
		if (this->_double < std::numeric_limits<int>::min() || this->_double > std::numeric_limits<int>::max())
			throw ImpossibleException();
		this->_isImpossible = false;
	}
	this->_int = static_cast<int>(this->_double);
	this->_float = static_cast<float>(this->_double);
	this->_char = static_cast<char>(this->_double);
}

void	ScalarConverter::printChar()
{
	try
	{
		if (this->_double == std::numeric_limits<double>::quiet_NaN() || this->_double == -std::numeric_limits<double>::infinity() || this->_double == std::numeric_limits<double>::infinity())
			throw ImpossibleException();
		if (this->_isImpossible)
			throw ImpossibleException();
		if (this->_char < 32 || this->_char > 126)
			throw NonDisplayableException();
		std::cout << "char: '" << this->_char << "'" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "char: " <<  e.what() << '\n';
	}
}

void	ScalarConverter::printInt()
{
	try
	{
		if (this->_double == std::numeric_limits<double>::quiet_NaN() || this->_double == -std::numeric_limits<double>::infinity() || this->_double == std::numeric_limits<double>::infinity())
			throw ImpossibleException();
		if (this->_isImpossible)
			throw ImpossibleException();
		std::cout << "int: " << this->_int << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "int: " << e.what() << '\n';
	}

}

void	ScalarConverter::printFloat()
{
	std::cout << "float: " <<  std::setprecision(std::numeric_limits<float>::digits10 + 1) << this->_float << "f" << "\n";
}

void	ScalarConverter::printDouble()
{
	std::cout << "double: " << std::setprecision(std::numeric_limits<double>::digits10 + 1) << this->_double << "\n";
}

const char *ScalarConverter::NonDisplayableException::what() const throw()
{
	return ("Non displayable");
}

const char *ScalarConverter::ImpossibleException::what() const throw()
{
	return ("impossible");
}
