/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 08:21:00 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/08/02 08:21:15 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include <string>
# include <iostream>

class Ice : public AMateria {
	public:
		Ice();
		virtual ~Ice();
		Ice(Ice const &ice);
		Ice& operator=(Ice const &ice);

		Ice(std::string const &type);

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif
