/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:07:19 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/06/28 15:18:11 by kkaiyawo         ###   ########.fr       */
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

		bool operator>(Fixed const &fixed) const;
		bool operator<(Fixed const &fixed) const;
		bool operator>=(Fixed const &fixed) const;
		bool operator<=(Fixed const &fixed) const;
		bool operator==(Fixed const &fixed) const;
		bool operator!=(Fixed const &fixed) const;

		Fixed operator+(Fixed const &fixed) const;
		Fixed operator-(Fixed const &fixed) const;
		Fixed operator*(Fixed const &fixed) const;
		Fixed operator/(Fixed const &fixed) const;

		Fixed& operator++(void); //pre
		Fixed operator++(int); //post
		Fixed& operator--(void); //pre
		Fixed operator--(int); //post

		static Fixed& min(Fixed &a, Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static Fixed const& min(Fixed const &a, Fixed const &b);
		static Fixed const& max(Fixed const &a, Fixed const &b);

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
