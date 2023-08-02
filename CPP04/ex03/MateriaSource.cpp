/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 08:33:17 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/08/02 08:34:04 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		if (this->_materia[i])
			delete this->_materia[i];
}

MateriaSource::MateriaSource(MateriaSource const &materiaSource) {
	*this = materiaSource;
}

MateriaSource& MateriaSource::operator=(MateriaSource const &materiaSource) {
	if (this != &materiaSource)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materia[i])
				delete this->_materia[i];
			this->_materia[i] = materiaSource._materia[i]->clone();
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m) {
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] == NULL)
		{
			this->_materia[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] && this->_materia[i]->getType() == type)
			return (this->_materia[i]->clone());
	}
	return (NULL);
}
