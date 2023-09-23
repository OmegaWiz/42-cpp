/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:18:41 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/23 15:51:37 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T> Array<T>::Array()
{
	this->_arr = NULL;
	this->_len = 0;
}

template <typename T> Array<T>::Array(unsigned int len)
{
	this->_arr = new T[len];
	this->_len = len;
}

template <typename T> Array<T>::Array(Array const &other)
{
	this->_len = other._len;
	this->_arr = new T[this->_len];
	for (unsigned int i = 0; i < _len; i++)
		this->_arr[i] = other._arr[i];
}

template <typename T> Array<T>::~Array()
{
	if (this->_arr)
		delete [] this->_arr;
}

template <typename T> const char *Array<T>::OutOfBoundsException::what() const throw(){
	return ("Index out of bounds");
}

template <typename T> Array<T> &Array<T>::operator=(Array const &other)
{
	if (this->_arr)
		delete [] this->_arr;
	this->_len = other._len;
	this->_arr = new T[this->_len];
	for (unsigned int i = 0; i < _len; i++)
		this->_arr[i] = other._arr[i];
	return (*this);
}

template <typename T> T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->_len)
		throw OutOfBoundsException();
	return (_arr[index]);
}

template <typename T> unsigned int Array<T>::size() const
{
	return (this->_len);
}
