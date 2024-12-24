#pragma once

#include <map>
#include <string>
#include <fstream>
#include <iostream>

#define ld long double
#define BAD_INPUT_ERR -1
#define BAD_DATE_ERR -2
#define LESS_THAN_ZERO_ERR -3
#define OVERFLOW_ERR -4
#define LESS_THAN 0
#define EQUAL 1
#define GREATER_THAN 2

class BitcoinExchange {
	public:
		BitcoinExchange(std::string const dbfile="data.csv");
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange &operator=(BitcoinExchange const &rhs);

		void parse(std::string const infile);
	private:
		std::map<std::string, ld> m_db;

		BitcoinExchange();
		int _lineParser(std::string const line, std::string &date, std::string &value, const char *cmp);
		int _dateChecker(std::string const date);
		int _dateComparator(std::string const date1, std::string const date2);
		ld _valueParser(std::string const value);
		void _printError(int err=0);
		int _strToInt(std::string const str);
};
