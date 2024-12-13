#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <stack>
#include <map>
#include <fstream>

class BitcoinExchange
{
private:
	std::map<std::string, float> _data;

public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &copy);
	~BitcoinExchange(void);

	void parseData(std::ifstream &file);
	void trimWhiteSpace(std::string &str);
};

#endif