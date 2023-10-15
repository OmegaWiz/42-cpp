/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:38:58 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/10/15 14:04:43 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(unsigned int n) : _n(n) {
}

Span::Span(Span const &src) {
	*this = src;
}

Span::~Span(void) {
}

Span &Span::operator=(Span const &rhs) {
	if (this != &rhs) {
		this->_n = rhs._n;
		this->_v = rhs._v;
	}
	return *this;
}

void Span::addNumber(int n) {
	if (this->_v.size() == this->_n)
		throw Span::ContainerFullException();
	this->_v.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (this->_v.size() + (end - begin) > this->_n)
		throw Span::ContainerFullException();
	this->_v.insert(this->_v.end(), begin, end);
}

int Span::shortestSpan(void) {
	if (this->_v.size() <= 1)
		throw Span::NoSpanException();
	std::vector<int> v = this->_v;
	std::sort(v.begin(), v.end());
	int mn = v[1] - v[0];
	for (int i = 1; i < (int) v.size() - 1; i++) {
		mn = std::min(mn, v[i + 1] - v[i]);
	}
	return mn;
}

int Span::longestSpan(void) {
	if (this->_v.size() <= 1)
		throw Span::NoSpanException();
	std::vector<int> v = this->_v;
	std::sort(v.begin(), v.end());
	return v[v.size() - 1] - v[0];
}

const char *Span::ContainerFullException::what() const throw() {
	return "Container is full";
}

const char *Span::NoSpanException::what() const throw() {
	return "No span to find";
}
