/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AException.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:01:09 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/09/03 13:36:47 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AException.hpp"

AException::AException() : _msg("AException") {
}

AException::AException(std::string msg) : _msg(msg) {
}

const char *AException::what() const throw() {
	return _msg.c_str();
}

const std::string AException::getMsg() const {
	return (_msg);
}

void AException::setMsg(std::string msg) {
	_msg = msg;
}


