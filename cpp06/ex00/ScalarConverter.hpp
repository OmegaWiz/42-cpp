/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:29:55 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/17 12:13:14 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <limits>

class ScalarConverter
{
	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter &operator=(ScalarConverter const &other);

		void	convert(std::string const &str);
		void	printChar();
		void	printInt();
		void	printFloat();
		void	printDouble();

		class NonDisplayableException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class ImpossibleException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		std::string		_str;
		char			_char;
		int				_int;
		float			_float;
		double			_double;
		bool			_isImpossible;
};

#endif
