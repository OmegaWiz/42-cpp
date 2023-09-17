/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:22:24 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/17 15:23:11 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

struct Data
{
	public:
		Data();
		~Data();
		Data(Data const &other);
		Data &operator=(Data const &other);

		std::string	s1;
		int			n;
		Data		*next;
};

#endif
