/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:43:56 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/08/02 07:49:20 by kkaiyawo         ###   ########.fr       */
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
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << "------------------------------------------------------" << std::endl;
	int				arraySize = 4;
	const Animal*	animalArray[arraySize];
	for (int i = 0; i < arraySize; i++)
	{
		if (i < arraySize / 2)
		{
			animalArray[i] = new Dog();
		}
		else
		{
			animalArray[i] = new Cat();
		}
		std::cout << "CREATE" << i << std::endl << std::endl;
	}
	for (int i = 0; i < arraySize; i++)
	{
		delete animalArray[i];
		std::cout << "DELETE" << i << std::endl << std::endl;
	}
	std::cout << "------------------------------------------------------" << std::endl;
	const Cat*		cat1 = new Cat();
	const Cat cat2(*cat1);
	delete cat1;
	std::cout << "DELETE" << 1 << std::endl << std::endl;
	cat2.makeSound();

	return (0);
}
