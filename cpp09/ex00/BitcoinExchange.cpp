#include "BitcoinExchange.hpp"
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(std::string const dbfile) {
	int res;
	std::fstream input;
	input.open(dbfile, std::ios::in);
	if (!input.is_open()) {
		std::cerr << "Error: Could not open file " << dbfile << std::endl;
		return;
	}
	std::string line;
	while (std::getline(input, line)) {
		std::string date, value;
		ld price;
		if ((res = this->_lineParser(line, date, value, ",") < 0)) {
			this->_printError(res);
			continue;
		}
		if ((res = this->_dateChecker(date)) < 0) {
			this->_printError(res);
			continue;
		}
		if ((price = this->_valueParser(value)) < 0) {
			this->_printError(price);
			continue;
		}
		this->m_db[date] = price;
	}
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) {
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	if (this != &rhs) {
		this->m_db = rhs.m_db;
	}
	return *this;
}

void BitcoinExchange::parse(std::string const infile) {
	int res;
	std::fstream input;
	input.open(infile, std::ios::in);
	if (!input.is_open()) {
		std::cerr << "Error: Could not open file " << infile << std::endl;
		return;
	}
	std::string line;
	while (std::getline(input, line)) {
		std::string date, value;
		ld amount;
		if ((res = this->_lineParser(line, date, value, "|") < 0)) {
			this->_printError(res);
			continue;
		}
		if ((res = this->_dateChecker(date)) < 0) {
			this->_printError(res);
			continue;
		}
		if ((amount = this->_valueParser(value)) < 0) {
			this->_printError(amount);
			continue;
		}
		std::cout << date << " => " << amount << " = " << this->m_db[date] * amount << std::endl;;
	}
}

int BitcoinExchange::_lineParser(std::string const line, std::string &date, std::string &value, const char *cmp) {
	size_t pos;
	int res;
	if ((pos = line.find(cmp)) == std::string::npos)
		return BAD_INPUT_ERR;
	date = line.substr(0, pos-1);
	value = line.substr(pos + 1);
	if ((res = this->_dateChecker(date)) < 0)
		return res;
	if ((res = this->_valueParser(value)) < 0)
		return res;
	return 0;
}

int BitcoinExchange::_dateChecker(std::string const date) {
	size_t pos;
	int m, d, y;
	if (date.find(" ") != std::string::npos)
		return BAD_DATE_ERR;
	std::string year, month, day, tmp;
	if ((pos = date.find("-")) == std::string::npos)
		return BAD_DATE_ERR;
	year = date.substr(0, pos);
	tmp = date.substr(pos + 1);
	if ((pos = tmp.find("-")) == std::string::npos)
		return BAD_DATE_ERR;
	month = tmp.substr(0, pos);
	day = tmp.substr(pos + 1);
	if ((y = this->_strToInt(year)) < 0)
		return y;
	if ((m = this->_strToInt(month)) < 0)
		return m;
	if (m > 12)
		return BAD_DATE_ERR;
	if ((d = this->_strToInt(day)) < 0)
		return d;
	if (d > 31)
		return BAD_DATE_ERR;
	if (d == 31) {
		if (m == 2 || m == 4 || m == 6 || m == 9 || m == 11)
			return BAD_DATE_ERR;
	}
	if (d == 30) {
		if (m == 2)
			return BAD_DATE_ERR;
	}
	if (d == 29) {
		if (m == 2) {
			if ((y % 4) != 0)
				return BAD_DATE_ERR;
			if ((y % 100) == 0 && (y % 400) != 0)
				return BAD_DATE_ERR;
		}
	}
	return 0;
}

int BitcoinExchange::_dateComparator(std::string const date1, std::string const date2) {
	int y1, m1, d1, y2, m2, d2;
	size_t pos;
	std::string year, month, day, tmp;

	if ((pos = date1.find("-")) == std::string::npos)
		return BAD_DATE_ERR;
	year = date1.substr(0, pos);
	tmp = date1.substr(pos + 1);
	if ((pos = tmp.find("-")) == std::string::npos)
		return BAD_DATE_ERR;
	month = tmp.substr(0, pos);
	day = tmp.substr(pos + 1);
	if ((y1 = this->_strToInt(year)) < 0)
		return y1;
	if ((m1 = this->_strToInt(month)) < 0)
		return m1;
	if (m1 > 12)
		return BAD_DATE_ERR;
	if ((d1 = this->_strToInt(day)) < 0)
		return d1;
	if (d1 > 31)
		return BAD_DATE_ERR;
	if (d1 == 31) {
		if (m1 == 2 || m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11)
			return BAD_DATE_ERR;
	}
	if (d1 == 30) {
		if (m1 == 2)
			return BAD_DATE_ERR;
	}
	if (d1 == 29) {
		if (m1 == 2) {
			if ((y1 % 4) != 0)
				return BAD_DATE_ERR;
			if ((y1 % 100) == 0 && (y1 % 400) != 0)
				return BAD_DATE_ERR;
		}
	}

	if ((pos = date2.find("-")) == std::string::npos)
		return BAD_DATE_ERR;
	year = date2.substr(0, pos);
	tmp = date2.substr(pos + 1);
	if ((pos = tmp.find("-")) == std::string::npos)
		return BAD_DATE_ERR;
	month = tmp.substr(0, pos);
	day = tmp.substr(pos + 1);
	if ((y2 = this->_strToInt(year)) < 0)
		return y2;
	if ((m2 = this->_strToInt(month)) < 0)
		return m2;
	if (m2 > 12)
		return BAD_DATE_ERR;
	if ((d2 = this->_strToInt(day)) < 0)
		return d2;
	if (d2 > 31)
		return BAD_DATE_ERR;
	if (d2 == 31) {
		if (m2 == 2 || m2 == 4 || m2 == 6 || m2 == 9 || m2 == 11)
			return BAD_DATE_ERR;
	}
	if (d2 == 30) {
		if (m2 == 2)
			return BAD_DATE_ERR;
	}
	if (d2 == 29) {
		if (m2 == 2) {
			if ((y2 % 4) != 0)
				return BAD_DATE_ERR;
			if ((y2 % 100) == 0 && (y2 % 400) != 0)
				return BAD_DATE_ERR;
		}
	}

	if (y1 < y2)
		return LESS_THAN;
	if (y1 > y2)
		return GREATER_THAN;
	if (m1 < m2)
		return LESS_THAN;
	if (m1 > m2)
		return GREATER_THAN;
	if (d1 < d2)
		return LESS_THAN;
	if (d1 > d2)
		return GREATER_THAN;
	return EQUAL;
}

ld BitcoinExchange::_valueParser(std::string const value) {
	std::string num, frac;
	ld res, tmp;

	if (value.find(".") != std::string::npos) {
		frac = value.substr(value.find(".") + 1);
		num = value.substr(0, value.find("."));
	}
	else {
		num = value;
		frac = "0";
	}
	res = this->_strToInt(frac);
	if (res < 0)
		return res;
	while (res > 0)
		res /= 10;
	tmp = this->_strToInt(num);
	if (tmp < 0)
		return tmp;
	return tmp + res;
}

void BitcoinExchange::_printError(int err) {
	switch (err) {
		case BAD_INPUT_ERR:
			std::cerr << "Error: Bad input" << std::endl;
			break;
		case BAD_DATE_ERR:
			std::cerr << "Error: Bad date" << std::endl;
			break;
		case LESS_THAN_ZERO_ERR:
			std::cerr << "Error: Value less than zero" << std::endl;
			break;
		case OVERFLOW_ERR:
			std::cerr << "Error: Overflow" << std::endl;
			break;
		default:
			std::cerr << "Error: Unknown error: " << err << std::endl;
			break;
	}
}

int BitcoinExchange::_strToInt(std::string const str) {
	int res = 0;
	int sign = 1;
	size_t i = 0;

	if (str[i] == '-') {
		return LESS_THAN_ZERO_ERR;
	}
	for (; i < str.length(); i++) {
		if (str[i] < '0' || str[i] > '9')
			return BAD_INPUT_ERR;
		if (res > INT_MAX / 10)
			return OVERFLOW_ERR;
		res = res * 10 + (str[i] - '0');
		if (res < 0)
			return OVERFLOW_ERR;
	}
	return res * sign;
}
