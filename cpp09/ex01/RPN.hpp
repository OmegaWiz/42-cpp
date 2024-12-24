#pragma once

#include <stack>
#include <string>
#include <iostream>

#define ld long double
#define BAD_INPUT_ERR -1
#define INVALID_OPERATION_ERR -2
#define DIVIDE_BY_ZERO_ERR -3
#define OVERFLOW_ERR -4
#define PLUS_SIGN -10
#define MINUS_SIGN -11
#define MULTIPLY_SIGN -12
#define DIVIDE_SIGN -13
#define SPACE -14
#define LESS_THAN 0
#define EQUAL 1
#define GREATER_THAN 2
#ifndef INT_MAX
# define INT_MAX 2147483647
#endif
#define LD_MAX __LDBL_MAX__ // 1.18973e+4932
#define LD_MIN LD_MAX * -1

class RPN {
	public:
		RPN();
		~RPN();
		RPN(RPN const &src);
		RPN &operator=(RPN const &rhs);

		void parse(std::string const input);
	private:
		std::stack<ld> s;

		int _charToInt(char const c);
		void _printError(int err=0);
		bool _isOverflow(ld a, ld b, int oper);
};
