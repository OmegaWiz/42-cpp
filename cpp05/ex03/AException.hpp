/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AException.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:57:12 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/03 13:36:24 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AEXCEPTION_HPP
# define AEXCEPTION_HPP

# include <string>
# include <iostream>
# include <exception>

class AException : public std::exception {
	public:
		AException();
		AException(std::string msg);
		~AException() throw() {};
		virtual const char *what() const throw();
		const std::string getMsg() const;
		void setMsg(std::string msg);

	protected:
		std::string _msg;
};

#endif
