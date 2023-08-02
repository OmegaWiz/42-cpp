/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 08:27:08 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/08/02 08:27:24 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include <string>
# include <iostream>

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource();
		virtual ~MateriaSource();
		MateriaSource(MateriaSource const &materiaSource);
		MateriaSource& operator=(MateriaSource const &materiaSource);

		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
	private:
		AMateria* _materia[4];
};

#endif
