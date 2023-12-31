/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:43:56 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/13 11:11:35 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <string>
#include <iostream>

int main()
{
	std::cout << "standard tests----------------------------------------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	std::cout << "------------------------------------------------------" << std::endl;
	const Animal* cat1 = new Cat();
	cat1->makeSound();
	const Animal cat2(*cat1);
	cat2.makeSound();
	delete cat1;
	cat2.makeSound();
	std::cout << "------------------------------------------------------" << std::endl;
	const Cat* cat3 = new Cat();
	cat3->makeSound();
	const Cat cat4(*cat3);
	cat4.makeSound();
	delete cat3;
	cat4.makeSound();
	std::cout << "------------------------------------------------------" << std::endl;
	const WrongAnimal* Armel = new WrongAnimal();
	const WrongCat* Milya = new WrongCat();
	std::cout << Armel->getType() << " " << std::endl;
	std::cout << Milya->getType() << " " << std::endl;
	Armel->makeSound();
	Milya->makeSound();
	delete Armel;
	delete Milya;
}
