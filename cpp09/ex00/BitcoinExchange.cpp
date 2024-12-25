#include "BitcoinExchange.hpp"

bool operator<(s_tm const &lhs, s_tm const &rhs) {
	if (lhs.tm_year < rhs.tm_year)
		return true;
	if (lhs.tm_year > rhs.tm_year)
		return false;
	if (lhs.tm_mon < rhs.tm_mon)
		return true;
	if (lhs.tm_mon > rhs.tm_mon)
		return false;
	if (lhs.tm_mday < rhs.tm_mday)
		return true;
	if (lhs.tm_mday > rhs.tm_mday)
		return false;
	if (lhs.tm_hour < rhs.tm_hour)
		return true;
	if (lhs.tm_hour > rhs.tm_hour)
		return false;
	if (lhs.tm_min < rhs.tm_min)
		return true;
	if (lhs.tm_min > rhs.tm_min)
		return false;
	if (lhs.tm_sec < rhs.tm_sec)
		return true;
	if (lhs.tm_sec > rhs.tm_sec)
		return false;
	return false;
}

std::ostream &operator<<(std::ostream &o, s_tm const &tm) {
	o << tm.tm_year << "-" << tm.tm_mon << "-" << tm.tm_mday;
	return o;
}

BitcoinExchange::BitcoinExchange() {
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

void BitcoinExchange::load_db(std::string const dbfile) {
	// int res;
	std::fstream input;
	input.open(dbfile.c_str(), std::ios::in);
	if (!input.is_open()) {
		throw FileError();
		return;
	}
	std::string line;
	int i = 0;
	while (std::getline(input, line)) {
		s_tm date;
		ld value;
		if (i == 0) {
			if (line.compare("date,exchange_rate") != 0) {
				std::cerr << "There are some problem with "
						  << dbfile << std::endl
						  << "Error: Bad Header" << std::endl;
				return;
			}
			i++;
			continue;
		}
		try
		{
			_lineParser(line, date, value, ",");
		}
		catch(const std::exception& e)
		{
			std::cerr << "There are some problem with "
					  << dbfile << std::endl
					  << e.what() << " at line " << i+1 << std::endl;
			return;
		}

		m_db[date] = value;
		i++;
	}
}

void BitcoinExchange::parse(std::string const infile) {
	// int res;
	std::fstream input;
	// input.open(infile, std::ios::in);
	input.open(infile.c_str(), std::ios::in);
	if (!input.is_open()) {
		throw FileError();
		return;
	}
	std::string line;
	int i = 0;
	while (std::getline(input, line)) {
		s_tm date;
		ld value;
		if (i == 0) {
			if (line.compare("date | value") != 0) {
				std::cerr << "There are some problem with "
						  << infile << std::endl
						  << "Error: Bad Header" << std::endl;
				return;
			}
			i++;
			continue;
		}
		try
		{
			_lineParser(line, date, value, "|");
		}
		catch(const std::exception& e)
		{
			std::cerr << "There are some problem with "
					  << infile << std::endl
					  << e.what() << " at line " << i+1 << std::endl;
			i++;
			continue;
		}

		ld final;
		std::map<s_tm, ld>::iterator it = m_db.upper_bound(date);
		if (it == m_db.begin()) final = 0;
		else {
			it--;
			final = it->second;
		}
		std::cout << date << " => " << value << " = " << final * value << std::endl;;
		i++;
	}
}

int BitcoinExchange::_lineParser(std::string const line, s_tm &date, ld &amount, const char *cmp) {
	size_t pos;
	// int res;
	std::string key, value;
	pos = line.find(cmp);
	if (pos == std::string::npos) {
		throw FormatError();
		return -1;
	}
	if (cmp[0] == '|')
		key = line.substr(0, pos-1);
	else
		key = line.substr(0, pos);
	if (cmp[0] == '|')
		value = line.substr(pos + 2, line.size() - (pos + 2));
	else
		value = line.substr(pos + 1, line.size() - (pos + 1));

	date = _dateParser(key);
	amount = _valueParser(value);

	return 0;
}

s_tm BitcoinExchange::_dateParser(std::string const date) {
	s_tm res;
	int y, m, d;
	size_t pos;
	std::string year, month, day, tmp;

	pos = date.find("-");
	if (pos == std::string::npos)
		throw BadDateError();
	year = date.substr(0, pos);
	tmp = date.substr(pos + 1);
	pos = tmp.find("-");
	if (pos == std::string::npos)
		throw BadDateError();
	month = tmp.substr(0, pos);
	day = tmp.substr(pos + 1);
	y = _strToInt(year);
	if (y < 0)
		throw BadDateError();
	if (y > 9999)
		throw BadDateError();
	m = _strToInt(month);
	if (m < 0)
		throw BadDateError();
	if (m > 12)
		throw BadDateError();
	d = _strToInt(day);
	if (d < 0)
		throw BadDateError();
	if (d > 31)
		throw BadDateError();
	if (d == 31) {
		if (m == 2 || m == 4 || m == 6 || m == 9 || m == 11)
			throw BadDateError();
	}
	if (d == 30) {
		if (m == 2)
			throw BadDateError();
	}
	if (d == 29) {
		if (m == 2) {
			if ((y % 4) != 0)
				throw BadDateError();
			if ((y % 100) == 0 && (y % 400) != 0)
				throw BadInputError();
		}
	}
	res.tm_year = y;
	res.tm_mon = m;
	res.tm_mday = d;
	res.tm_hour = 0;
	res.tm_min = 0;
	res.tm_sec = 0;
	return res;
}

ld BitcoinExchange::_valueParser(std::string const value) {
	std::string num, frac;
	ld res, tmp;
	size_t pos;

	pos = value.find(".");
	if (pos != std::string::npos) {
		frac = value.substr(pos + 1);
		num = value.substr(0, pos);
	}
	else {
		num = value;
		frac = "0";
	}
	res = (ld) _strToInt(frac);
	if (res < 0)
		return -1;
	while (res >= 1)
		res /= 10;
	tmp = _strToInt(num);
	if (tmp < 0)
		return -1;
	// std::cout << "DEBUG: " << tmp << " + " << res << " = " << tmp + res << std::endl;
	return tmp + res;
}

int BitcoinExchange::_strToInt(std::string const str) {
	int res = 0;
	int sign = 1;
	size_t i = 0;

	if (str[i] == '-') {
		throw BadValueError();
		return -1;
	}
	for (; str[i] != 0; i++) {
		if (str[i] < '0' || str[i] > '9') {
			throw BadValueError();
			return -1;
		}
		if (res > INT_MAX / 10) {
			throw BadValueError();
			return -1;
		}
		res = res * 10 + (str[i] - '0');
		if (res < 0) {
			throw BadValueError();
			return -1;
		}
	}
	return res * sign;
}

const char *BitcoinExchange::FileError::what() const throw() {
	return "Error: Unable to open file";
}

const char *BitcoinExchange::BadInputError::what() const throw() {
	return "Error: Bad input";
}

const char *BitcoinExchange::BadDateError::what() const throw() {
	return "Error: Bad date";
}

const char *BitcoinExchange::BadValueError::what() const throw() {
	return "Error: Bad value";
}

const char *BitcoinExchange::FormatError::what() const throw() {
	return "Error: Invalid format (expected: key <sep> value)";
}
