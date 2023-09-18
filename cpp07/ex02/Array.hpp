/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 04:54:41 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/18 05:10:25 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T> class Array
{
	public:
		Array()
		{
			_arr = NULL;
			_len = 0;
		}

		Array(unsigned int len)
		{
			_arr = new T[len];
			_len = len;
		}

		Array(Array const &other)
		{
			_len = other._len;
			_arr = new T[_len];
			for (unsigned int i = 0; i < _len; i++)
				_arr[i] = other._arr[i];
		}

		~Array()
		{
			if (_arr)
				delete [] _arr;
		}

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Index out of bounds");
				}
		};

		Array &operator=(Array const &other)
		{
			if (_arr)
				delete [] _arr;
			_len = other._len;
			_arr = new T[_len];
			for (unsigned int i = 0; i < _len; i++)
				_arr[i] = other._arr[i];
			return (*this);
		}

		T &operator[](unsigned int index)
		{
			if (index >= _len)
				throw OutOfBoundsException();
			return (_arr[index]);
		}

		unsigned int size() const
		{
			return (_len);
		}

	private:
		T *_arr;
		unsigned int _len;
};

#endif
