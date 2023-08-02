/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:16:19 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/08/02 07:34:33 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	public:
		Cat();
		~Cat();
		Cat(Cat const &cat);
		Cat& operator=(Cat const &cat);

		void makeSound() const;

	private:
		Brain *_brain;
};

#endif
