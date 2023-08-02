/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:43:56 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/08/02 09:11:21 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"

#include "MateriaSource.hpp"
#include "Character.hpp"

int main()
{
	std::cout << "standard tests----------------------------------------" << std::endl;
	MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << "------------------------------------------------------" << std::endl;

	// Test 1: Equipping and Using Materia
	MateriaSource* src1 = new MateriaSource();
	src1->learnMateria(new Ice());
	src1->learnMateria(new Cure());

	ICharacter* me1 = new Character("me");
	ICharacter* bob1 = new Character("bob");

	me1->equip(src1->createMateria("ice"));
	me1->equip(src1->createMateria("cure"));

	me1->use(0, *bob1); // Use "ice" Materia on "bob"
	me1->use(1, *bob1); // Use "cure" Materia on "bob"

	delete me1;
	delete src1;
	delete bob1;

	std::cout << "------------------------------------------------------" << std::endl;

	// Test 2: Learning Materia Limit
	src1 = new MateriaSource();
	src1->learnMateria(new Ice());
	src1->learnMateria(new Cure());
	src1->learnMateria(new Ice());
	src1->learnMateria(new Cure());

	// Attempt to add more Materia than the limit (e.g., 4)
	Cure* testcure = new Cure();
	src1->learnMateria(testcure); // This should not be added

	delete src1;
	delete testcure;

	std::cout << "------------------------------------------------------" << std::endl;

	// Test 3: Using Unavailable Materia
	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	me = new Character("me");
	bob = new Character("bob");

	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));

	// Try using Materia at index 2 when only two Materia are equipped
	me->use(2, *bob); // This should not cause any issues

	delete me;
	delete src;
	delete bob;

	std::cout << "------------------------------------------------------" << std::endl;

	// Test 4: Character Health and Healing
	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	me = new Character("me");
	bob = new Character("bob");

	me->equip(src->createMateria("cure"));

	// Use "cure" Materia on "me" to heal
	me->use(0, *me);

	delete me;
	delete src;
	delete bob;
	std::cout << "------------------------------------------------------" << std::endl;

	// Test 5: Character and Materia Memory Management
	// Create various characters and Materia objects, equip and use Materia, and finally delete them.
	// Check for memory leaks using tools like Valgrind.

	MateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Ice());
	src2->learnMateria(new Ice());
	src2->learnMateria(new Ice());

	Character* character1 = new Character("Character 1");
	Character* character2 = new Character("Character 2");

	character1->equip(src2->createMateria("fire"));
	character1->equip(src2->createMateria("water"));

	character2->equip(src2->createMateria("wind"));
	character2->equip(src2->createMateria("earth"));

	// Use Materia
	character1->use(0, *character2); // Use "fire" on character2
	character1->use(1, *character2); // Use "water" on character2

	// Delete Materia and characters
	delete character1;
	delete character2;
	delete src2;

	return (0);
}
