/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:05:37 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/06/27 11:25:41 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include<string>

class Zombie
{
	public:
		Zombie();
		~Zombie();

		void		setName(std::string name);
		std::string	getName(void);
		void		announce(void);
	private:
		std::string _name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif
