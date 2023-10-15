/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:15:37 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/10/15 14:17:59 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(MutantStack const &other){
			*this = other;
		}
		MutantStack &operator=(MutantStack const &other)
		{
			if (this != &other)
				std::stack<T>::operator=(other);
			return (*this);
		}
		virtual ~MutantStack() {}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() { return (std::stack<T>::c.begin()); }
		iterator end() { return (std::stack<T>::c.end()); }
};

#endif
