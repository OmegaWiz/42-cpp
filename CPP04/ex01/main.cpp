/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:43:56 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/07/13 09:46:33 by kkaiyawo         ###   ########.fr       */
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
	int				arraySize = 10;
	const Animal*	animalArray[arraySize];
	for (int i = 0; i < arraySize; arraySize++)
	{
		if (i < arraySize / 2)
		{
			animalArray[i] = new Dog();
		}
	}

	return (0);
}
