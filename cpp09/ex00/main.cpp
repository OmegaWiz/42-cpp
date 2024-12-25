#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <config_file>" << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	try {
		btc.load_db("data.csv");
	} catch (const std::exception &e) {
		std::cerr << "There are some problems with the database file" << std::endl;
		std::cerr << e.what() << std::endl;
		return 1;
	}
	// std::cout << "Database loaded" << std::endl;
	try {
		btc.parse(argv[1]);
	} catch (const std::exception &e) {
		std::cerr << "There are some problems with the input file" << std::endl;
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
