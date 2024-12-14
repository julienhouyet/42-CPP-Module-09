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

	void _loadDatabase();
	void _trimWhiteSpace(std::string &str);
	bool _isValidDate(const std::string &date, std::string &errorMessage);
	bool _isValidValue(const std::string &value, std::string &errorMessage);

	void calculateExchangeRate(std::ifstream &file);
};

#endif