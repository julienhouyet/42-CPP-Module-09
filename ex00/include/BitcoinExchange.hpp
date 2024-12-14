#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <stack>
#include <map>
#include <fstream>

class BitcoinExchange
{
private:
	std::map<std::string, float> _database;
public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &copy);
	~BitcoinExchange(void);

	void loadDatabase();
	void calculateExchangeRate(std::ifstream &file);
	void trimWhiteSpace(std::string &str);
	bool isValidDate(const std::string &date, std::string &errorMessage);
	bool isValidValue(const std::string &value, std::string &errorMessage);
};

#endif