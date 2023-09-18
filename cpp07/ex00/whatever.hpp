/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 04:39:23 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/18 04:40:09 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T> void swap (T *x, T *y)
{
	T tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

template <typename T> T min (T x, T y)
{
	return (x < y) ? x : y;
}

template <typename T> T max (T x, T y)
{
	return (x > y) ? x : y;
}

#endif
