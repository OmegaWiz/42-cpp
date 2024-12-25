#pragma once

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <cstddef>
#include <fstream>

#define ld long double
#define s_tm struct tm
#define BAD_INPUT_ERR -1
#define BAD_DATE_ERR -2
#define LESS_THAN_ZERO_ERR -3
#define OVERFLOW_ERR -4
#define LESS_THAN 0
#define EQUAL 1
#define GREATER_THAN 2
#ifndef INT_MAX
# define INT_MAX 2147483647
#endif

class BitcoinExchange {
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange &operator=(BitcoinExchange const &rhs);

		void load_db(std::string const dbfile="data.csv");
		void parse(std::string const infile);

		class FileError : public std::exception {
			public:
				const char *what() const throw();
		};

		class BadInputError : public std::exception {
			public:
				const char *what() const throw();
		};

		class BadDateError : public std::exception {
			public:
				const char *what() const throw();
		};

		class BadValueError : public std::exception {
			public:
				const char *what() const throw();
		};

		class FormatError : public std::exception {
			public:
				const char *what() const throw();
		};
	private:
		std::map<s_tm, ld> m_db;

		int _lineParser(std::string const line, s_tm &date, ld &amount, const char *cmp);
		ld _valueParser(std::string const value);
		s_tm _dateParser(std::string const date);
		// int _dateComparator(std::string const date1, std::string const date2);
		int _strToInt(std::string const str);
};

bool operator<(s_tm const &lhs, s_tm const &rhs) ;
std::ostream &operator<<(std::ostream &os, s_tm const &date);
