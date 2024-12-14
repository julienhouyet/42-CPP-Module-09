#include "../include/BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

// ************************************************************************** //
//                            BitcoinExchange Class                           //
// ************************************************************************** //

BitcoinExchange::BitcoinExchange(void)
{
	this->_loadDatabase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
  	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
	{
    	_database = copy._database;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

// ************************************************************************** //
//                         Private Member Functions                           //
// ************************************************************************** //

/**
 * @brief Load the data from the CSV file
 * 
 * @param filename The name of the file to load
 * 
 * @return void
 */
void BitcoinExchange::_loadDatabase()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
		std::cerr << "Error: could not load database." << std::endl;
		exit(1);
    }

    std::string line;
    // Skip the header line
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        float rate;

        if (std::getline(ss, date, ',') && (ss >> rate))
        {
            _trimWhiteSpace(date);

            std::string dateErrorMessage;
            if (!_isValidDate(date, dateErrorMessage))
            {
				std::cerr << "Error: corrupted database." << std::endl;
				exit(1);
            }

            if (rate < 0 || rate > 2147483647)
            {
				std::cerr << "Error: corrupted database." << std::endl;
				exit(1);
            }

            _database[date] = rate;
        }
        else
        {
			std::cerr << "Error: corrupted database." << std::endl;
			exit(1);
        }
    }
	file.close();
}

/** 
 * @brief Trim whitespace from the beginning and end of a string
 * 
 * @param str The string to trim
 * 
 * @return void
 */
void BitcoinExchange::_trimWhiteSpace(std::string &str)
{
	str.erase(0, str.find_first_not_of(" \t"));
	str.erase(str.find_last_not_of(" \t") + 1);
}

/**
 * @brief Check if the date is valid
 * 
 * @param date The date to check
 * 
 * @return true if the date is valid, false otherwise
 */
bool BitcoinExchange::_isValidDate(const std::string &date, std::string &dateErrorMessage)
{
    std::stringstream ss(date);
    std::string year, month, day;

    if (std::getline(ss, year, '-') && std::getline(ss, month, '-') && std::getline(ss, day))
    {
        if (year.size() == 4 && month.size() == 2 && day.size() == 2)
        {
            std::stringstream year_ss(year);
            std::stringstream month_ss(month);
            std::stringstream day_ss(day);
            int year_int, month_int, day_int;
            year_ss >> year_int;
            month_ss >> month_int;
            day_ss >> day_int;

            if (year_int < 2009 || year_int > 2024 || month_int < 1 || month_int > 12 || day_int < 1 || day_int > 31)
            {
                dateErrorMessage = "Error: bad input => " + date;
                return false;
            }
            return true;
        }
    }
    return false;
}

/**
 * @brief Check if the value is valid
 * 
 * @param value The value to check
 * 
 * @return true if the value is valid, false otherwise
 */
bool BitcoinExchange::_isValidValue(const std::string &value, std::string &valueErrorMessage)
{
    std::stringstream ss(value);
    int intValue;

    if (ss >> intValue) {
        if (intValue < 0) {
            valueErrorMessage = "Error: not a positive number.";
            return false;
        }
        if (intValue > 1000) {
            valueErrorMessage = "Error: too large a number.";
            return false;
        }
        return true;
    }

    ss.clear();
    ss.str(value);

    float floatValue;
    if (ss >> floatValue) {
        if (floatValue < 0.0f) {
            valueErrorMessage = "Error: not a positive number.";
            return false;
        }
        if (floatValue > 1000.0f) {
            valueErrorMessage = "Error: too large a number.";
            return false;
        }
        return true;
    }
    return false;
}

// ************************************************************************** //
//                         Public Member Functions                            //
// ************************************************************************** //

/** 
 * @brief Parse the input file and return value of bitcoin at the date
 * 
 * @param file The file to parse
 * 
 * @return void
 */
void BitcoinExchange::calculateExchangeRate(std::ifstream &file)
{
    std::string line;
	std::string dateErrorMessage;
	std::string valueErrorMessage;

	// Check if the first line is "date | value"
    if (std::getline(file, line) && line != "date | value") {
        std::cerr << "Error: first line must be 'date | value'" << std::endl;
        return;
    }
	
	// Check the rest of the file
    while (std::getline(file, line)) {
		std::stringstream ss(line);
        std::string date, value;

		// Check if line is valid
        if (std::getline(ss, date, '|') && std::getline(ss, value)) {
			_trimWhiteSpace(date);
			_trimWhiteSpace(value);
			dateErrorMessage.clear();
			valueErrorMessage.clear();

            bool dateValid = _isValidDate(date, dateErrorMessage);
            bool valueValid = _isValidValue(value, valueErrorMessage);

            if (!dateValid) {
                std::cerr << dateErrorMessage << std::endl;
            }
            if (!valueValid) {
                std::cerr << valueErrorMessage << std::endl;
            }

			if (dateValid && valueValid) {
				std::map<std::string, float>::iterator dateMatch = _database.lower_bound(date);
				if (dateMatch == _database.end() || dateMatch->first != date) {
					if (dateMatch == _database.begin()) {
						std::cerr << "Error: no previous date available for " << date << std::endl;
						continue;
					}
					--dateMatch;
				}

				float rate = dateMatch->second;
				std::stringstream valueStream(value);
				float inputValue;
				valueStream >> inputValue;
				float result = inputValue * rate;

				std::cout << date << " => " << value << " = " << result << std::endl;
			}
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
}