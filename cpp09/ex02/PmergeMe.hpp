#pragma once

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
#include <sys/time.h>

#define ld long double
#define INDEX_ERR -1
#ifndef INT_MAX
# define INT_MAX 2147483647
#endif
#define LD_MAX __LDBL_MAX__ // 1.18973e+4932
#define LD_MIN LD_MAX * -1

class PmergeMe {
	public:
		PmergeMe(char const **av);
		~PmergeMe();
		PmergeMe(PmergeMe const &src);
		PmergeMe &operator=(PmergeMe const &rhs);

	private:
		PmergeMe();
		std::deque<int> container1;
		std::vector<int> container2;
		// std::deque<int> container3;
		// std::vector<int> container4;

		void _next_Jacobstial(int j[3]);
		int _bsearch_d(std::deque<int> &v, int n);
		int _bsearch_d(std::deque<int> &v, int n, int l, int r);
		int _bsearch_v(std::vector<int> &v, int n);
		int _bsearch_v(std::vector<int> &v, int n, int l, int r);
		void _sort_v(std::vector<int> &v);
		void _sort_d(std::deque<int> &v);
};
