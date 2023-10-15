/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:38:58 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/10/15 13:06:48 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iterators>

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
		throw Span::FullException();
	this->_v.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (this->_v.size() + ((end - begin) / sizeof(int)) > this->_n)
		throw Span::FullException();
	this->_v.insert(this->_v.end(), begin, end);
}

int Span::shortestSpan(void) {
	if (this->_v.size() <= 1)
		throw Span::NoSpanException();
	std::vector<int> v = this->_v;
	std::sort(v.begin(), v.end());
	int min = v[1] - v[0];
	for (std::vector<int>::iterator it = v.begin(); it != v.end() - 1; it++) {
		if (*(it + 1) - *it < min)
			min = *(it + 1) - *it;
	}
	return min;
}

int Span::longestSpan(void) {
	if (this->_v.size() <= 1)
		throw Span::NoSpanException();
	std::vector<int> v = this->_v;
	std::sort(v.begin(), v.end());
	return v[v.size() - 1] - v[0];
}

const char *Span::FullException::what() const throw() {
	return "Container is full";
}

const char *Span::NoSpanException::what() const throw() {
	return "No span to find";
}
