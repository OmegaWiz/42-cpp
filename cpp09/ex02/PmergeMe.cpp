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
					// container3.push_back(x);
					// container4.push_back(x);
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
			// container3.push_back(x);
			// container4.push_back(x);
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
	// gettimeofday(&d1, NULL);
	// std::sort(container3.begin(), container3.end());
	// gettimeofday(&d2, NULL);
	// gettimeofday(&v1, NULL);
	// std::sort(container4.begin(), container4.end());
	// gettimeofday(&v2, NULL);
	// std::cout << "Time to process a range of " << container3.size()
	// 		  << " elements with std::deque  : "
	// 		  << ((d2.tv_sec - d1.tv_sec) * 1000000 + (d2.tv_usec - d1.tv_usec))
	// 		  << " microseconds" << std::endl;
	// std::cout << "Time to process a range of " << container4.size()
	// 		  << " elements with std::vector : "
	// 		  << ((v2.tv_sec - v1.tv_sec) * 1000000 + (v2.tv_usec - v1.tv_usec))
	// 		  << " microseconds" << std::endl;
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

int PmergeMe::_bsearch_d(std::deque<int> &v, int n, int l, int r) {
	if (l > r) return l;
	if (r > (int) v.size() - 1) r = (int) v.size() - 1;
	int m = l + (r - l) / 2;
	if (v[m] == n) {
		return m;
	}
	if (v[m] < n) {
		return _bsearch_d(v, n, m + 1, r);
	}
	return _bsearch_d(v, n, l, m - 1);
}

void PmergeMe::_sort_d(std::deque<int> &v) {
	int index, index3;
	if ((int) v.size() <= 1) return;
	if ((int) v.size() == 2) {
		if (v[0] > v[1]) {
			// int tmp = v[0];
			// v[0] = v[1];
			// v[1] = tmp;
			v.push_front(v.back());
			v.pop_back();
		}
		return;
	}
	if ((int) v.size() % 2 == 1) {
		int x = v.back();
		v.pop_back();
		_sort_d(v);
		index = _bsearch_d(v, x);
		v.insert(v.begin() + index, x);
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
	int to_check = (int) u.size();
	std::deque<int> looker(to_check, 0);
	for (int i = 1; i < (int) v.size(); i += 2) {
		index = _bsearch_d(u, v[i]);
		looker[index] = v[i-1];
	}
	// index = std::find(v.begin(), v.end(), u.front()) - v.begin();
	// u.push_front(v[index - 1]);
	u.push_front(looker[0]);

	int jacob[3] = {1, 1, 3};
	while (jacob[2] < (int) v.size()) {
		for (int i = jacob[2]-1; i > jacob[1]-1; i--) {
			if (i >= to_check) continue;
			int j = looker[i];
			index3 = _bsearch_d(u, j);
			// index3 = _bsearch_d(u, j, 0, 2 * i);
			u.insert(u.begin() + index3, j);
		}
		_next_Jacobstial(jacob);
	}
	v = u;
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

int PmergeMe::_bsearch_v(std::vector<int> &v, int n, int l, int r) {
	if (l > r) return l;
	if (r > (int) v.size() - 1) r = (int) v.size() - 1;
	int m = l + (r - l) / 2;
	if (v[m] == n) {
		return m;
	}
	if (v[m] < n) {
		return _bsearch_v(v, n, m + 1, r);
	}
	return _bsearch_v(v, n, l, m - 1);
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
		return;
	}
	if ((int) v.size() % 2 == 1) {
		int x = v.back();
		v.pop_back();
		_sort_v(v);
		index = _bsearch_v(v, x);
		v.insert(v.begin() + index, x);
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
	int to_check = (int) u.size();
	std::vector<int> looker(u.size(), 0);
	for (int i = 1; i < (int) v.size(); i += 2) {
		index = _bsearch_v(u, v[i]);
		looker[index] = v[i-1];
	}
	// index = std::find(v.begin(), v.end(), u.front()) - v.begin();
	// u.insert(u.begin(), v[index - 1]);
	u.insert(u.begin(), looker[0]);

	int jacob[3] = {1, 1, 3};
	while (jacob[2] < (int) v.size()) {
		for (int i = jacob[2]-1; i > jacob[1]-1; i--) {
			if (i >= to_check) continue;
			int j = looker[i];
			index3 = _bsearch_v(u, j);
			u.insert(u.begin() + index3, j);
		}
		_next_Jacobstial(jacob);
	}
	v = u;
}
