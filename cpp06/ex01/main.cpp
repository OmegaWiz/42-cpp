/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:34:52 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/17 15:57:47 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
	Serializer		serializer;
	uintptr_t		ptr;
	Data			*data;
	Data			*data2;

	data = new Data();
	data->s1 = "Hello";
	data->n = 42;
	data->next = new Data();
	data->next->s1 = "World";
	data->next->n = 21;
	data->next->next = NULL;
	std::cout << "Before Serialize: " << std::endl;
	std::cout << data << std::endl;
	std::cout << data->s1 << std::endl;
	std::cout << data->n << std::endl;
	std::cout << data->next->s1 << std::endl;
	std::cout << data->next->n << std::endl;
	std::cout << data->next->next << std::endl;
	ptr = serializer.serialize(data);
	data2 = serializer.deserialize(ptr);
	std::cout << "--------------------------------------\n";
	std::cout << "After Serialize: " << std::endl;
	std::cout << data2 << std::endl;
	std::cout << data2->s1 << std::endl;
	std::cout << data2->n << std::endl;
	std::cout << data2->next->s1 << std::endl;
	std::cout << data2->next->n << std::endl;
	std::cout << data2->next->next << std::endl;
	delete data->next;
	delete data;
	return (0);
}
