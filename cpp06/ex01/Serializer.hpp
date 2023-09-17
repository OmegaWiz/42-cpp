/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:24:04 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/17 12:33:33 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <limits>
# include "Data.hpp"

class Serializer
{
	public:
		Serializer();
		~Serializer();
		Serializer(Serializer const &other);
		Serializer &operator=(Serializer const &other);

		uintptr_t	serialize(Data *ptr);
		Data		*deserialize(uintptr_t raw);
};

#endif
