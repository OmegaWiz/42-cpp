/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 08:21:20 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/08/02 08:21:36 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include <string>
# include <iostream>

class Cure : public AMateria {
	public:
		Cure();
		virtual ~Cure();
		Cure(Cure const &cure);
		Cure& operator=(Cure const &cure);

		Cure(std::string const &type);

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif
