#include "../include/BitcoinExchange.hpp"
#include <iostream>
#include <string>

// ************************************************************************** //
//                            BitcoinExchange Class                           //
// ************************************************************************** //

BitcoinExchange::BitcoinExchange(void) : _data()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
  *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
	{
    	_data = copy._data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

// ************************************************************************** //
//                         Public Member Functions                            //
// ************************************************************************** //

void BitcoinExchange::parseData(std::ifstream &file)
{
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
}