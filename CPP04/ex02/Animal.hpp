/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:12:23 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/08/02 08:06:42 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {
	public:
		Animal();
		virtual ~Animal() = 0;
		Animal(Animal const &animal);
		Animal& operator=(Animal const &animal);

		Animal(std::string type);

		virtual void makeSound() const = 0;
		std::string getType() const;
		void setType(std::string type);
	protected:
		std::string _type;
};

#endif
