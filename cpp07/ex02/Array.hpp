/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 04:54:41 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/23 13:58:50 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T> class Array
{
	public:
		Array();
		Array(unsigned int len);
		Array(Array const &other);
		~Array();
		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		Array &operator=(Array const &other);
		T &operator[](unsigned int index);
		unsigned int size() const;

	private:
		T *_arr;
		unsigned int _len;
};

# include "Array.tpp"

#endif
