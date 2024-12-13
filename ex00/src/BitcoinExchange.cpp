#include "../include/BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <sstream>
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

/** 
 * @brief Parse the data from the file and return value of bitcoin at the date
 * 
 * @param file The file to parse
 * 
 * @return void
 */
void BitcoinExchange::parseData(std::ifstream &file)
{
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
		std::stringstream ss(line);
        std::string date, value;

		// Check if line is valid
        if (std::getline(ss, date, '|') && std::getline(ss, value)) {
			trimWhiteSpace(date);
			trimWhiteSpace(value);

			// TODO : check if date is valid

			// TODO : check if value is valid

            std::cout << "Date: '" << date << "', Value: '" << value << "'" << std::endl;
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
}

/** 
 * @brief Trim whitespace from the beginning and end of a string
 * 
 * @param str The string to trim
 * 
 * @return void
 */
void BitcoinExchange::trimWhiteSpace(std::string &str)
{
	str.erase(0, str.find_first_not_of(" \t"));
	str.erase(str.find_last_not_of(" \t") + 1);
}