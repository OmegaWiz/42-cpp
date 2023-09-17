/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:23:38 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/17 15:26:03 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
	this->s1 = "";
	this->n = 0;
	this->next = NULL;
}

Data::~Data()
{}

Data::Data(Data const &other)
{
	*this = other;
}

Data &Data::operator=(Data const &other)
{
	if (this != &other)
	{
		this->s1 = other.s1;
		this->n = other.n;
		this->next = other.next;
	}
	return (*this);
}
