#include "../include/BitcoinExchange.hpp"

// ************************************************************************** //
//                            BitcoinExchange Class                           //
// ************************************************************************** //

BitcoinExchange::BitcoinExchange(void)
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
    // TOTO : Implement the assignment operator
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

// ************************************************************************** //
//                         Public Member Functions                            //
// ************************************************************************** //