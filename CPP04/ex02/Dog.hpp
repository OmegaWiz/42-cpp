/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:23:11 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/08/02 07:39:12 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	public:
		Dog();
		~Dog();
		Dog(Dog const &dog);
		Dog& operator=(Dog const &dog);

		void makeSound() const;

	private:
		Brain *_brain;
};

#endif
