/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:07:19 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/06/27 15:13:17 by kkaiyawo         ###   ########.fr       */
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
		Fixed &operator=(Fixed const &fixed);

		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int _fixed;
		static const int _bits = 8;
};

#endif
