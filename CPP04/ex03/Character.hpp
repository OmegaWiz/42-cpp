/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 08:25:08 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/08/02 08:44:57 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include <string>
# include <iostream>

class Character : public ICharacter {
	public:
		Character();
		virtual ~Character();
		Character(Character const &character);
		Character& operator=(Character const &character);

		Character(std::string const &name);

		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

	private:
		std::string _name;
		AMateria *_inventory[4];
		// int _count;
};

#endif
