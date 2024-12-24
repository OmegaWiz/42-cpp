#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <config_file>" << std::endl;
		return 1;
	}
	BitcoinExchange btc("./cpp_09/data.csv");
	btc.parse(argv[2]);
	return 0;
}
