#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(char const **av) {
	int i = 1;
	while (av[i]) {
		int x = 0;
		bool isdig = false;
		for (int j = 0; av[i][j]; j++) {
			if (av[i][j] == ' ') {
				if (isdig) {
					container1.push_back(x);
					container2.push_back(x);
					container3.push_back(x);
					container4.push_back(x);
					x = 0;
					isdig = false;
				}
				continue;
			}
			if (av[i][j] < '0' || av[i][j] > '9') {
				std::cerr << "Invalid input" << std::endl;
				return;
			}
			isdig = true;
			if (x >= 100000000) {
				std::cerr << "Overflow" << std::endl;
				return;
			}
			x = x * 10 + av[i][j] - '0';
		}
		if (isdig) {
			container1.push_back(x);
			container2.push_back(x);
			container3.push_back(x);
			container4.push_back(x);
		}
		i++;
	}
	std::cout << "Before sort(1):" << std::endl;
	for (int i = 0; i < (int) container1.size(); i++) {
		std::cout << container1[i] << " ";
	}
	std::cout << std::endl;
	struct timeval d1, d2, v1, v2;
	gettimeofday(&d1, NULL);
	_sort_d(container1);
	gettimeofday(&d2, NULL);
	// std::cout << "After sort(1):" << std::endl;
	// for (int i = 0; i < (int) container1.size(); i++) {
	// 	std::cout << container1[i] << " ";
	// }
	// std::cout << std::endl;
	// std::cout << "Before sort(2):" << std::endl;
	// for (int i = 0; i < (int) container2.size(); i++) {
	// 	std::cout << container2[i] << " ";
	// }
	// std::cout << std::endl;
	gettimeofday(&v1, NULL);
	_sort_v(container2);
	gettimeofday(&v2, NULL);
	std::cout << "After sort(2):" << std::endl;
	for (int i = 0; i < (int) container2.size(); i++) {
		std::cout << container2[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << container1.size()
			  << " elements with std::deque  : "
			  << ((d2.tv_sec - d1.tv_sec) * 1000000 + (d2.tv_usec - d1.tv_usec))
			  << " microseconds" << std::endl;
	std::cout << "Time to process a range of " << container2.size()
			  << " elements with std::vector : "
			  << ((v2.tv_sec - v1.tv_sec) * 1000000 + (v2.tv_usec - v1.tv_usec))
			  << " microseconds" << std::endl;
	gettimeofday(&d1, NULL);
	std::sort(container3.begin(), container3.end());
	gettimeofday(&d2, NULL);
	gettimeofday(&v1, NULL);
	std::sort(container4.begin(), container4.end());
	gettimeofday(&v2, NULL);
	std::cout << "Time to process a range of " << container3.size()
			  << " elements with std::deque  : "
			  << ((d2.tv_sec - d1.tv_sec) * 1000000 + (d2.tv_usec - d1.tv_usec))
			  << " microseconds" << std::endl;
	std::cout << "Time to process a range of " << container4.size()
			  << " elements with std::vector : "
			  << ((v2.tv_sec - v1.tv_sec) * 1000000 + (v2.tv_usec - v1.tv_usec))
			  << " microseconds" << std::endl;
}

PmergeMe::~PmergeMe() {
}

PmergeMe::PmergeMe(PmergeMe const &src) {
	*this = src;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
	if (this != &rhs) {
		this->container1 = rhs.container1;
		this->container2 = rhs.container2;
	}
	return *this;
}


void PmergeMe::_next_Jacobstial(int j[3]) {
	j[0] = j[1];
	j[1] = j[2];
	j[2] = j[1] + 2 * j[0];
}

int PmergeMe::_bsearch_d(std::deque<int> &v, int n) {
	int l = 0;
	int r = (int) v.size() - 1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (v[m] == n) {
			return m;
		}
		if (v[m] < n) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	return l;
}

void PmergeMe::_sort_d(std::deque<int> &v) {
	int index, index3;
	if ((int) v.size() <= 1) return;
	if ((int) v.size() == 2) {
		if (v[0] > v[1]) {
			int tmp = v[0];
			v[0] = v[1];
			v[1] = tmp;
		}
		// std::cout << v[0] << " " << v[1] << std::endl;
		return;
	}
	if ((int) v.size() % 2 == 1) {
		int x = v.back();
		v.pop_back();
		_sort_d(v);
		index = _bsearch_d(v, x);
		// std::cout << "index: " << index << std::endl;
		v.insert(v.begin() + index, x);
		// for (int i = 0; i < (int) v.size(); i++) {
		// 	std::cout << v[i] << " ";
		// }
		// std::cout << " with sort3" << std::endl;
		return;
	}
	std::deque<int> u;
	for (int i = 0; i+1 < (int) v.size(); i += 2) {
		if (v[i] > v[i + 1]) {
			int tmp = v[i];
			v[i] = v[i + 1];
			v[i + 1] = tmp;
		}
		u.push_back(v[i+1]);
	}
	_sort_d(u);
	std::deque<int> sorted = u;
	std::deque<int> looker(u.size(), 0);
	for (int i = 1; i < (int) v.size(); i += 2) {
		index = _bsearch_d(u, v[i]);
		looker[index] = v[i-1];
	}
	// for (int i = 0; i < (int) sorted.size(); i++) {
	// 	std::cout << sorted[i] << " ";
	// }
	// std::cout << "larger half" << std::endl;
	index = std::find(v.begin(), v.end(), u.front()) - v.begin();
	sorted.push_front(v[index - 1]);
	int to_check = (int) u.size();

	int jacob[3] = {1, 1, 3};
	while (jacob[2] < (int) v.size()) {
		for (int i = jacob[2]-1; i > jacob[1]-1; i--) {
			// if (i >= (int) u.size()) continue;
			if (i >= to_check) continue;
			// std::cout << "inserting b[" << i+1 << "] of " << u[i];
			int j = looker[i];
			// std::cout << " which is " << j << std::endl;
			// index2 = _bsearch_d(sorted, u[i]);
			// std::deque<int> tmp(sorted.begin(), sorted.begin() + index2);
			// index3 = _bsearch_d(tmp, j);
			// std::cout << "inserting: " << j << " in ";
			// for (int i = 0; i < (int) sorted.size(); i++) {
			// 	std::cout << sorted[i] << " ";
			// }
			// std::cout << std::endl;
			index3 = _bsearch_d(sorted, j);
			sorted.insert(sorted.begin() + index3, j);
		}
		_next_Jacobstial(jacob);
		// std::cout << "jacob: " << jacob[0] << " " << jacob[1] << " " << jacob[2] << std::endl;
	}
	// for (int i = 0; i < (int) sorted.size(); i++) {
	// 	v[i] = sorted[i];
	// }
	v = sorted;
}

int PmergeMe::_bsearch_v(std::vector<int> &v, int n) {
	int l = 0;
	int r = (int) v.size() - 1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (v[m] == n) {
			return m;
		}
		if (v[m] < n) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	return l;
}

void PmergeMe::_sort_v(std::vector<int> &v) {
	int index, index3;
	if ((int) v.size() <= 1) return;
	if ((int) v.size() == 2) {
		if (v[0] > v[1]) {
			int tmp = v[0];
			v[0] = v[1];
			v[1] = tmp;
		}
		// std::cout << v[0] << " " << v[1] << std::endl;
		return;
	}
	if ((int) v.size() % 2 == 1) {
		int x = v.back();
		v.pop_back();
		_sort_v(v);
		index = _bsearch_v(v, x);
		// std::cout << "index: " << index << std::endl;
		v.insert(v.begin() + index, x);
		// for (int i = 0; i < (int) v.size(); i++) {
		// 	std::cout << v[i] << " ";
		// }
		// std::cout << " with sort3" << std::endl;
		return;
	}
	std::vector<int> u;
	for (int i = 0; i+1 < (int) v.size(); i += 2) {
		if (v[i] > v[i + 1]) {
			int tmp = v[i];
			v[i] = v[i + 1];
			v[i + 1] = tmp;
		}
		u.push_back(v[i+1]);
	}
	_sort_v(u);
	std::vector<int> sorted = u;
	std::vector<int> looker(u.size(), 0);
	for (int i = 1; i < (int) v.size(); i += 2) {
		index = _bsearch_v(u, v[i]);
		looker[index] = v[i-1];
	}
	// for (int i = 0; i < (int) sorted.size(); i++) {
	// 	std::cout << sorted[i] << " ";
	// }
	// std::cout << "larger half" << std::endl;
	index = std::find(v.begin(), v.end(), u.front()) - v.begin();
	sorted.insert(sorted.begin(), v[index - 1]);
	int to_check = (int) u.size();

	int jacob[3] = {1, 1, 3};
	while (jacob[2] < (int) v.size()) {
		for (int i = jacob[2]-1; i > jacob[1]-1; i--) {
			// if (i >= (int) u.size()) continue;
			if (i >= to_check) continue;
			// std::cout << "inserting b[" << i+1 << "] of " << u[i];
			int j = looker[i];
			// std::cout << " which is " << j << std::endl;
			// index2 = _bsearch_d(sorted, u[i]);
			// std::deque<int> tmp(sorted.begin(), sorted.begin() + index2);
			// index3 = _bsearch_d(tmp, j);
			// std::cout << "inserting: " << j << " in ";
			// for (int i = 0; i < (int) sorted.size(); i++) {
			// 	std::cout << sorted[i] << " ";
			// }
			// std::cout << std::endl;
			index3 = _bsearch_v(sorted, j);
			sorted.insert(sorted.begin() + index3, j);
		}
		_next_Jacobstial(jacob);
		// std::cout << "jacob: " << jacob[0] << " " << jacob[1] << " " << jacob[2] << std::endl;
	}
	// for (int i = 0; i < (int) sorted.size(); i++) {
	// 	v[i] = sorted[i];
	// }
	v = sorted;


	// int index, index3;
	// if ((int) v.size() <= 1) return;
	// if ((int) v.size() == 2) {
	// 	if (v[0] > v[1]) {
	// 		int tmp = v[0];
	// 		v[0] = v[1];
	// 		v[1] = tmp;
	// 	}
	// 	return;
	// }
	// if ((int) v.size() % 2 == 1) {
	// 	int x = v.back();
	// 	v.pop_back();
	// 	_sort_v(v);
	// 	index = _bsearch_v(v, x);
	// 	v.insert(v.begin() + index, x);
	// 	return;
	// }
	// std::vector<int> u;
	// for (int i = 0; i+1 < (int) v.size(); i += 2) {
	// 	if (v[i] > v[i + 1]) {
	// 		int tmp = v[i];
	// 		v[i] = v[i + 1];
	// 		v[i + 1] = tmp;
	// 	}
	// 	u.push_back(v[i+1]);
	// }
	// _sort_v(u);
	// std::vector<int> sorted = u;
	// index = _bsearch_v(v, u.front());
	// // sorted.push_front(v[index - 1]); //CHANGE FOR VECTOR
	// sorted.insert(sorted.begin(), v[index - 1]);
	// int jacob[3] = {1, 1, 3};
	// while (jacob[2] < (int) v.size()) {
	// 	for (int i = jacob[2]; i > jacob[1]; i--) {
	// 		if (i >= (int) u.size()) {
	// 			continue;
	// 		}
	// 		index = _bsearch_v(v, u[i]);
	// 		int j = v[index - 1];
	// 		// index2 = _bsearch_d(sorted, u[i]);
	// 		// std::deque<int> tmp(sorted.begin(), sorted.begin() + index2);
	// 		// index3 = _bsearch_d(tmp, j);
	// 		index3 = _bsearch_v(sorted, j);
	// 		sorted.insert(sorted.begin() + index3, j);
	// 	}
	// 	_next_Jacobstial(jacob);
	// }
	// for (int i = 0; i < (int) sorted.size(); i++) {
	// 	v[i] = sorted[i];
	// }
}
