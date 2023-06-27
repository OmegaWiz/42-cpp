/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 08:19:45 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/06/27 10:21:04 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

class Phonebook
{
	public:
		Phonebook(void);
		~Phonebook(void);

		void	addContact();
		void	searchContact(void);
;
	private:
		int		_index;
		int		_size;
		int		_capacity;
		Contact _contacts[8];
		std::string _trimAndPad(std::string str, size_t len);
};

#endif
