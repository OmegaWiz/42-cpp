/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:07:19 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/06/28 15:09:07 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &fixed);
		Fixed& operator=(Fixed const &fixed);

		Fixed(const int n);
		Fixed(const float f);

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;
	private:
		int _fixed;
		static const int _bits = 8;
};

std::ostream& operator<<(std::ostream &out, Fixed const &fixed);

#endif
