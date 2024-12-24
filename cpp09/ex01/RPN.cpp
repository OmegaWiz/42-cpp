#include "RPN.hpp"
#include <cstddef>
#include <iostream>
#include <string>

RPN::RPN() {
}

RPN::~RPN() {
}

RPN::RPN(RPN const &src) {
	*this = src;
}

RPN &RPN::operator=(RPN const &rhs) {
	if (this != &rhs) {
		this->s = rhs.s;
	}
	return *this;
}

void RPN::parse(std::string const input) {
	int n = SPACE, x = SPACE;
	for(int i = 0; input[i] != '\0'; i++) {
		x = n;
		n = _charToInt(input[i]);
		if (n == BAD_INPUT_ERR) {
			_printError(BAD_INPUT_ERR);
			return;
		}
		if (n == SPACE) {
			continue;
		}
		if (n >= 0) {
			if (x >= 0) {
				_printError(BAD_INPUT_ERR);
				return;
			}
			s.push(n);
		}
		else {
			if (s.size() < 2) {
				_printError(INVALID_OPERATION_ERR);
				return;
			}
			ld a = s.top();
			s.pop();
			ld b = s.top();
			s.pop();
			switch (n) {
				case PLUS_SIGN:
					if (_isOverflow(a, b, PLUS_SIGN)) {
						_printError(OVERFLOW_ERR);
						return;
					}
					s.push(b + a);
					break;
				case MINUS_SIGN:
					if (_isOverflow(a, b, MINUS_SIGN)) {
						_printError(OVERFLOW_ERR);
						return;
					}
					s.push(b - a);
					break;
				case MULTIPLY_SIGN:
					if (_isOverflow(a, b, MULTIPLY_SIGN)) {
						_printError(OVERFLOW_ERR);
						return;
					}
					s.push(b * a);
					break;
				case DIVIDE_SIGN:
					if (a == 0) {
						_printError(DIVIDE_BY_ZERO_ERR);
						return;
					}
					if (_isOverflow(a, b, DIVIDE_SIGN)) {
						_printError(OVERFLOW_ERR);
						return;
					}
					s.push(b / a);
					break;
				default:
					_printError(BAD_INPUT_ERR);
					return;
			}
		}
	}
	if (s.size() != 1) {
		_printError(BAD_INPUT_ERR);
		return;
	}
	std::cout << s.top() << std::endl;
}

void RPN::_printError(int err) {
	switch (err) {
		case BAD_INPUT_ERR:
			std::cerr << "Error: Bad input\n" << std::endl;
			break;
		case INVALID_OPERATION_ERR:
			std::cerr << "Error: Invalid Operation" << std::endl;
			break;
		case DIVIDE_BY_ZERO_ERR:
			std::cerr << "Error: Division by zero is not permitted" << std::endl;
			break;
		case OVERFLOW_ERR:
			std::cerr << "Error: Overflow" << std::endl;
			break;
		default:
			std::cerr << "Error: Unknown error: " << err << std::endl;
			break;
	}
}

int RPN::_charToInt(char const c) {
	if (c < '0' || c > '9') {
		switch (c) {
			case '+':
				return PLUS_SIGN;
			case '-':
				return MINUS_SIGN;
			case '*':
				return MULTIPLY_SIGN;
			case '/':
				return DIVIDE_SIGN;
			case ' ':
				return SPACE;
			default:
				return BAD_INPUT_ERR;
		}
	}
	else
		return c - '0';
}

bool RPN::_isOverflow(ld a, ld b, int oper) {
	if (oper == PLUS_SIGN) {
		if (a >= 0) {
			if (LD_MAX - a < b) {
				return true;
			}
		}
		else {
			if (LD_MIN - a > b) {
				return true;
			}
		}
	}
	if (oper == MINUS_SIGN) {
		if (a >= 0) {
			if (LD_MIN + a > b) {
				return true;
			}
		}
		else {
			if (LD_MAX + a < b) {
				return true;
			}
		}
	}
	if (oper == MULTIPLY_SIGN) {
		if (a == 0 || b == 0) {
			return false;
		}
		if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
			if (LD_MAX / a < b) {
				return true;
			}
		}
		else {
			if (LD_MIN / a > b) {
				return true;
			}
		}
	}
	if (oper == DIVIDE_SIGN) {
		if (a < -1 && a > 1) return true;
		if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
			if (LD_MAX * a < b) {
				return true;
			}
		}
		else {
			if (LD_MIN * a > b) {
				return true;
			}
		}
	}
	return false;
}
